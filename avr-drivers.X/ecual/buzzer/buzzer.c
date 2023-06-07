#include "buzzer.h"
#include "../../mcal/gpio/gpio.h"

/**
 * @brief Initializes the pin connected to the buzzer.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 */
void BUZZER_init() {
    GPIO_setPinDirection(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_OUTPUT);
}

/**
 * @brief Turns on the buzzer.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 */
void BUZZER_on() {
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_HIGH);
}

/**
 * @brief Turns off the buzzer.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 */
void BUZZER_off() {
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_LOW);
}