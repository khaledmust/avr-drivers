#include "application.h"
#include "../utilities/std_types.h"

st_TIMER_config_t myTIMERConfig = {
    TIMER_NORMAL_MODE,
    CLK_64,
    0, 0, 0,
    0, 250
};

typedef struct {
    uint16 onTime;
    uint16 offTime;
}st_APP_BlinkPeriod_t;

struct {
    st_APP_BlinkPeriod_t sequence1;
    st_APP_BlinkPeriod_t sequence2;
    st_APP_BlinkPeriod_t sequence3;
    st_APP_BlinkPeriod_t sequence4;
    st_APP_BlinkPeriod_t sequence5;
    
} st_APP_BlinkSequence = {
    .sequence1 = {.onTime = 100, .offTime = 900},
    .sequence2 = {.onTime = 200, .offTime = 800},
    .sequence3 = {.onTime = 300, .offTime = 700},
    .sequence4 = {.onTime = 400, .offTime = 500},
    .sequence5 = {.onTime = 800, .offTime = 200}
};

uint8 g_ledSequence = 0;
uint8 g_blinkSequence = 0;

uint8 pb1_status = 0;
uint8 pb2_status = 0;

struct st_currentBlinkSequnce_t {
    st_APP_BlinkPeriod_t currentBlink;
}g_st_currentBlinkSequence;

st_LED_config_t led1 = {
    PORTC_ID, PIN0_ID
};

st_LED_config_t led2 = {
    PORTC_ID, PIN1_ID
};

st_LED_config_t led3 = {
    PORTC_ID, PIN3_ID
};

st_LED_config_t led4 = {
    PORTC_ID, PIN7_ID
};


void APP_PB1CallbackFunc(void) {
    g_ledSequence++;
    if (g_ledSequence > 7) {
        g_ledSequence = 0;
    }
    millis(200);
}

void APP_PB2CallbackFunc(void) {
    g_blinkSequence++;
    if (g_blinkSequence > 7) {
        g_blinkSequence = 0;
    }
    millis(200);
}

void APP_Init(void) {
    LED_init(&led1);
    LED_init(&led2);
    LED_init(&led3);
    LED_init(&led4);
    
    PB_init(PB1);
    PB_init(PB2);
    
    TIMER_Init(&myTIMERConfig);
    
    EXI_triggerEdge(EXI_INT0, LOW_LVL);
    EXI_triggerEdge(EXI_INT1, LOW_LVL);
    
    EXI_setCallBack(EXI_INT0, APP_PB1CallbackFunc);
    EXI_setCallBack(EXI_INT1, APP_PB2CallbackFunc);
    
    EXI_enable(EXI_INT0);
    EXI_enable(EXI_INT1);
}


void APP_Start(void) {
    
//    PB_status(PB1, &pb1_status);
//    PB_status(PB2, &pb2_status);
    
//    if (pb2_status == 1) {
//        g_blinkSequence++;
//        pb2_status = 0;
//    }
    
    switch (g_blinkSequence) {
        case 1:
            g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence1;
            break;
        case 2:
            g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence2;
            break;
        case 3:
            g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence3;
            break;
        case 4:
            g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence4;
            break;
        case 5:
            g_st_currentBlinkSequence.currentBlink = st_APP_BlinkSequence.sequence5;
            break;
        default:
            g_blinkSequence = 0;
            /* Do Nothing for now. */
            break;
    }
    
//    if (pb1_status == 0) {
//        g_ledSequence++;
//        pb1_status = 1;
//    }
    
    switch (g_ledSequence) {
        case 0:
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            break;
        case 1:
            LED_on(&led1);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 2:
            LED_on(&led1);
            LED_on(&led2);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 3:
            LED_on(&led1);
            LED_on(&led2);
            LED_on(&led3);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 4:
            LED_on(&led1);
            LED_on(&led2);
            LED_on(&led3);
            LED_on(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 5:
            LED_on(&led2);
            LED_on(&led3);
            LED_on(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 6:
            LED_on(&led3);
            LED_on(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 7:
            LED_on(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.onTime);
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            millis(g_st_currentBlinkSequence.currentBlink.offTime);
            break;
        case 8:
            LED_off(&led1);
            LED_off(&led2);
            LED_off(&led3);
            LED_off(&led4);
            break;
        default:
            g_ledSequence = 0;
            break;
    }
    
    
}
