#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <util/delay.h> /* For the delay functions */
#include "../../utilities/registers.h"

#define LCD_DATA_BITS_MODE 4 ///< The mode in which the LCD to operated in. (Takes a value of either 4 or 8)

/* Check the validity of the selected mode. */
#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#define LCD_DATA_PORT_ID PORTA_ID ///< The port name where the LCD data pins are connected to.

#if (LCD_DATA_BITS_MODE == 4)
/* If LCD_LAST_PORT_PINS is defined in the code, the LCD driver will use the last 4 pins in the GPIO port for for data.
 * To use the first four pins in the GPIO port for data just remove LCD_LAST_PORT_PINS */
#define LCD_USE_LAST_PORT_PINS

#ifdef LCD_USE_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID         PIN3_ID
#else
#define LCD_FIRST_DATA_PIN_ID         PIN0_ID
#endif

#endif

/**
 * @defgroup LCD_PORT_PIN_CONFIGURATION
 * @{
 */
#define LCD_RS_PORT_ID PORTA_ID ///< The port name where the LCD RS pin is connected to.
#define LCD_RS_PIN_ID  PIN1_ID ///< The pin number where the LCD RS pin is connected to.

#define LCD_EN_PORT_ID PORTA_ID ///< The port name where the LCD EN pin is connected to.
#define LCD_EN_PIN_ID  PIN2_ID ///< The pin number where the LCD EN pin is connected to.

/**
 * @note The development board that I am using has the RW pin tied to the ground.
 * In order to use it please uncomment the following and also uncomment it in the main code.
 */
//#define LCD_RW_PORT PORTB_ID ///< The port name where the LCD RW pin is connected to.
//#define LCD_RW_PIN PIN1_ID ///< The pin number where the LCD RW pin is connected to.
/**@}*/

/**
 * @defgroup LCD_Commands
 * @{
 */
#define CMD_LCD_CLEAR_DISPLAY              0x01 ///< Clears the LCD screen.
#define CMD_LCD_GO_TO_HOME                 0x02 ///< Return the cursor to the start position.
#define CMD_LCD_TWO_LINES_EIGHT_BITS_MODE  0x38 ///< 8-bits mode with 2 lines.
#define CMD_LCD_TWO_LINES_FOUR_BITS_MODE   0x28 ///< 4-bits mode with 2 lines.
#define CMD_LCD_CURSOR_OFF                 0x0C ///< Turns on the LCD screen with the cursor off.
#define CMD_LCD_CURSOR_ON                  0x0E ///< Turns on the LCD screen with the cursor solid.
#define CMD_LCD_SET_CURSOR_LOCATION        0x80 ///< Sets the location of the cursor.
/**@}*/

/**
 * @brief Initializes the pins connected to the LCD display, clears the display,
 * and sets the cursor to the home position.
 */
void LCD_init(void);

/**
 * @brief Sends a command to the LCD display.
 * @param[in] lcd_command The specified command to be sent to the LCD.
 */
void LCD_sendCommand(uint8 lcd_command);

/**
 * @brief Displays the specified character on the LCD display.
 * @param[in] character The specified character to be displayed.
 */
void LCD_displayCharacter(uint8 character);

/**
 * @brief Displays a whole string on the LCD.
 * @param[in] p_string Address of the string to be displayed on the LCD.
 */
void LCD_displayString(uint8 *p_string);

/**
 * @brief Stores a custom character in the CGRAM.
 * @param custom_character[in] Address of the bitmap representation of the character to be created.
 * @param cgram_location[in] Location in CGRAM to write the custom character in.
 */
void LCD_createCustomCharacter(uint8 *custom_character, uint8 cgram_location);

/**
 * @brief Moves the cursor to a specific row and column on the LCD display.
 * @param row The specified row, either row 0 or row 1.
 * @param col The specified column from 0 to 15.
 */
void LCD_moveCursor(uint8 row,  uint8 col);

#endif /* LCD_H_ */