#ifndef TIMER_H
#define	TIMER_H

#include "../../utilities/std_types.h"

#define F_CPU 16000000UL
#define MAX_COUNT 256
#define MAX_DELAY_NO_PRESCLAER (float32)((MAX_COUNT)*(1/F_CPU))
#define TIMER_INIT_VALUE(REQ_TIME_DELAY,PRESCALER_VALUE) (MAX_COUNT-((REQ_TIME_DELAY/1000UL)*(float32)(F_CPU/PRESCALER_VALUE)))
#define MAX_DELAY(PRESCALER_VALUE) ((((float32)PRESCALER_VALUE/F_CPU)*MAX_COUNT)*1000UL) 

#define NO_PRESCLR      1
#define PRESCLR_8       8   
#define PRESCLR_64      64
#define PRESCLR_256     256
#define PRESCLR_1024    1024    

typedef enum {
    TIMER_NORMAL_MODE = 0, PWM_MODE, CTC_MODE, FAST_PWM_MODE
}en_TIMER_OperationMode_t;

typedef enum {
    COMPARE_OUTPUT_MODE_NORMAL = 0,
    COMPARE_OUTPUT_MODE_TOGGLE,
    COMPARE_OUTPUT_MODE_CLEAR,
    COMPARE_OUTPUT_MODE_SET
}en_TIMER_OutputCompareMode_t;

typedef enum {
    NO_CLK, CLK, CLK_8, CLK_64, CLK_256, CLK_1024
}en_TIMER_ClockSelect_t;

typedef enum {
    INTERRUPT_DISABLE = 0, INTERRUPT_ENABLE
}en_TIMER_InterruptOpMode_t;

typedef struct {
    en_TIMER_OperationMode_t en_TIMER_OperationMode;
    en_TIMER_ClockSelect_t en_TIMER_ClockSelect;
    en_TIMER_OutputCompareMode_t en_TIMER_OutputCompareMode;
    en_TIMER_InterruptOpMode_t en_TIMER_InterruptOpMode;
    uint8 u8_TIMER_InitialValue;
    
}st_TIMER_config_t;

void TIMER_init();
void TIMER_deInit();
void TIMER_delayMillis(uint16 required_delay_ms);
#endif	/* TIMER_H */