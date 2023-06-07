#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../utilities/registers.h"
#include "../../utilities/std_types.h"
#include "../../utilities/common_macros.h"


/**
 * @defgroup KEYPAD_PORT_PIN_CONFIGURATION
 * @{
 */
#define KEYPAD_NUM_COLS 4 ///< The number of columns for the connected keypad matrix.
#define KEYPAD_NUM_ROWS 4 ///< The number of rows for the connected keypad matrix.

#define KEYPAD_ROW_PORT_ID  PORTB_ID ///< The port ID where the rows of the keypad are connected to.
#define KEYPAD_COL_PORT_ID  PORTD_ID ///< The port ID where the columns of the keypad are connected to.

#define KEYPAD_FIRST_ROW_PIN_ID PIN4_ID ///< The pin number where the first row pin is connected to.
#define KEYPAD_FIRST_COL_PIN_ID PIN2_ID ///< The pin number where the first column pin is connected to.

#define KEYPAD_ROW_PINS 0x0F ///< The row pins mask.
#define KEYPAD_COL_PINS 0x3C ///< The column pins mask.

#define KEYPAD_LOGIC_BUTTON_PRESSED   LOGIC_LOW
#define KEYPAD_LOGIC_BUTTON_RELEASED  LOGIC_HIGH
/**@}*/

/**
 * @brief Initializes the direction of the row keypad pins as output pins, and the columns keypad pins as input pins.
 */
void KEYPAD_init(void);

/**
 * @brief Returns the number of position of the key pressed on the keypad matrix.
 * @return An unsigned integer value that represents the position of the key pressed.
 */
uint8 KEYPAD_getKeyPressed(void);

/**
 * @brief Maps the position of the key with the actual value of the keypad.
 * @param current_key_pressed An unsigned integer value that represents the position of the key pressed.
 * @return An unsigned integer of the actual reading of the keypad.
 */
uint8 KEYPAD_mappedKey(uint8 current_key_pressed);

#endif /* KEYPAD_H_ */