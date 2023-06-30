#include "mcal/timer/timer.h"
#include "ecual/led/led.h"
#include "mcal/timer/timer_private.h"
#include "utilities/common_macros.h"
#include "services/timer_services.h"
#include "application/application.h"

//st_TIMER_config_t myTIMERConfig = {
//    TIMER_NORMAL_MODE,
//    CLK_64,
//    0, 0, 0,
//    0, 250
//};

int main() {
    
    
    APP_Init();
    
    while (1) {
        APP_Start();
    }
//    LED_init(blue);
//    LED_init(red);
//    LED_init(green);
//    TIMER_Init(&myTIMERConfig);
//    
//    
//    
//    while (1) {
//        millis(50);
//        LED_toggle(red);
//    }
    
//    while (1) {
//        LED_on(blue);
//        for (x = 0; x < 200; x++) {
//            while (TIMER_GetOCFlagStatus() != FLAG_SET) {
//            
//            }
//            SET_BIT(TIFR, OCF0);
//        }
//        LED_toggle(red);    
//    }
}
