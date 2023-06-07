#ifndef BUZZER_H_
#define BUZZER_H_
#include "../../utilities/registers.h"

#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN PIN5_ID

/**
 * @brief Initializes the pin connected to the buzzer.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 */
void BUZZER_init();

/**
 * @brief Turns on the buzzer.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 */
void BUZZER_on();

/**
 * @brief Turns off the buzzer.
 * @param[in] port_id Specifies the GPIO port to be configured.
 * This parameter can be one of PORTx_ID.
 * @param[in] pin_id Specifies the GPIO pin to be configured.
 * This parameter can be one of PINx_ID.
 */
void BUZZER_off();

#endif /* BUZZER_H_ */