#include "timer.h"
#include "timer_private.h"
#include "../../utilities/common_macros.h"

static uint8 g_TIMER_overFlowsCount = 0;
static uint8 g_TIMER_timerInitialValue = 0;

static void calculatePrescaler(float32 delay_ms, uint16 *prescaler) {
    uint16 prescaler_value = delay_ms / (MAX_DELAY_NO_PRESCLAER * F_CPU);

    if (prescaler_value >= 8) {
        /* Prescaler value F_CPU/8 */
        *prescaler = PRESCLR_8;
    } else if (prescaler_value >= 64) {
        /* Prescaler value F_CPU/64 */
        *prescaler = PRESCLR_64;
    } else if (prescaler_value >= 256) {
        /* Prescaler value F_CPU/256 */
        *prescaler = PRESCLR_256;
    } else if (prescaler_value >= 1024) {
        /* Prescaler value F_CPU/1024 */
        *prescaler = PRESCLR_1024;
    } else {
        /* No prescaler value. */
        *prescaler = 1;
    }
}

static void calcTimerInitValue(uint16 prescaler_value, float32 delay_ms,
        uint8 *timer_inital_value) {
    switch (prescaler_value) {
        case PRESCLR_8:
            *timer_inital_value = TIMER_INIT_VALUE(delay_ms, PRESCLR_8);
            break;
        case PRESCLR_64:
            *timer_inital_value = TIMER_INIT_VALUE(delay_ms, PRESCLR_64);
            break;
        case PRESCLR_256:
            *timer_inital_value = TIMER_INIT_VALUE(delay_ms, PRESCLR_256);
            break;
        case PRESCLR_1024:
            *timer_inital_value = TIMER_INIT_VALUE(delay_ms, PRESCLR_1024);
            break;
        default:
            *timer_inital_value = TIMER_INIT_VALUE(delay_ms, NO_PRESCLR);
            break;
    }
}

static void setPrescalerValue(uint16 prescaler_value) {
    switch (prescaler_value) {
        case NO_PRESCLR:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case PRESCLR_8:
            CLEAR_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case PRESCLR_64:
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case PRESCLR_256:
            CLEAR_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;
        case PRESCLR_1024:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);

            break;
        default:
            ;
    }
}

void TIMER_stop() {
    CLEAR_BIT(TCCR0, CS00);
    CLEAR_BIT(TCCR0, CS01);
    CLEAR_BIT(TCCR0, CS02);
}

void TIMER_delayMillis(uint16 required_delay_ms) {
    uint16 prescaler_value = 0;
    uint8 overFlow_counter = 0;
    calculatePrescaler(required_delay_ms, &prescaler_value);
    if (prescaler_value == 1) {
        /* No prescaler value was needed. */
        calcTimerInitValue(prescaler_value, required_delay_ms, &g_TIMER_timerInitialValue);
        g_TIMER_overFlowsCount = 0;
    } else {
        calcTimerInitValue(prescaler_value, required_delay_ms, &g_TIMER_timerInitialValue);
        g_TIMER_overFlowsCount = required_delay_ms / g_TIMER_timerInitialValue;
    }
    TCNT0 = g_TIMER_timerInitialValue;   
    setPrescalerValue(prescaler_value);
    
    while (overFlow_counter >= g_TIMER_overFlowsCount) {
        if (BIT_IS_SET(TIFR, TOV0)) {
            overFlow_counter++;
        } else {
            
        }
    }
    TIMER_stop();
    
}
