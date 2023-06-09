#include "mcal/timer/timer.h"
#include "ecual/led/led.h"

int main() {
    LED_init(blue);
    LED_on(blue);
    for(double i =0; i < 100000; i++) {
        // delay.
    }
    LED_off(blue);
    
    while (1) {
        TIMER_delayMillis(1000);
        LED_toggle(blue);
    }
}
