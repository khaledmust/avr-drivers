#include "lcd.h"
#include "../../utilities/std_types.h"
#include "../../mcal/gpio/gpio.h"

#define UPPER_NIBBLE 0xF0
#define LOWER_NIBBLE 0x0F
#define LCD_DATA_PINS_MASK 0x87

/**
 * @brief Initializes the pins connected to the LCD display.
 * This done by using the GPIO_setPinDirection function from the GPIO driver.
 */
void LCD_init(void) {
    GPIO_setPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_PIN_OUTPUT);
    /* Disables as the RW pin is connected to the ground. */
    //GPIO_setPinDirection(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_OUTPUT);
    GPIO_setPinDirection(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_OUTPUT);

#if (LCD_DATA_BITS_MODE == 4)
    GPIO_setPinDirection(LCD_DATA_PORT_ID, LCD_FIRST_DATA_PIN_ID, GPIO_PIN_OUTPUT);
    GPIO_setPinDirection(LCD_DATA_PORT_ID, LCD_FIRST_DATA_PIN_ID + 1, GPIO_PIN_OUTPUT);
    GPIO_setPinDirection(LCD_DATA_PORT_ID, LCD_FIRST_DATA_PIN_ID + 2, GPIO_PIN_OUTPUT);
    GPIO_setPinDirection(LCD_DATA_PORT_ID, LCD_FIRST_DATA_PIN_ID + 3, GPIO_PIN_OUTPUT);

    LCD_sendCommand(CMD_LCD_TWO_LINES_FOUR_BITS_MODE);

#elif (LCD_DATA_BITS_MODE == 8)
    GPIO_setPortDirection(LCD_DATA_PORT_ID, GPIO_PORT_OUTPUT);
    LCD_sendCommand(CMD_LCD_TWO_LINES_EIGHT_BITS_MODE);
#endif

    LCD_sendCommand(CMD_LCD_CURSOR_OFF);
    LCD_sendCommand(CMD_LCD_CLEAR_DISPLAY);
	
	_delay_ms(30);
}

/**
 * @brief Sends a command to the LCD display.
 * To send a command to the LCD display the following must be done:
 * 1. Both the RS = 0 and RW = 0.
 * 2. The EN pin must be toggled to high.
 * 3. Send the specified command. (This is done by writing the command to the data port)
 * 4. The EN pin is toggled to low.
 * @param[in] lcd_command The specified command to be sent to the LCD.
 */
void LCD_sendCommand(uint8 lcd_command) {
    GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_PIN_LOW);
    //GPIO_writePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_LOW);

#if (LCD_DATA_BITS_MODE == 8)
    GPIO_writePort(LCD_DATA_PORT_ID, lcd_command);
    _delay_ms(1);
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_LOW);
    _delay_ms(1);
	
#elif (LCD_DATA_BITS_MODE == 4)
    /* Used to store the value of the port to preserve the unused pin by the LCD. */
	volatile uint8 lcd_port_value = 0;

    /* Read the current value of the LCD_DATA_PORT_ID. */
    GPIO_readPort(LCD_DATA_PORT_ID, &lcd_port_value);

    /* Mask the port with 0b1xxxx111 to preserve the state of the bits, and OR it with the upper nibble
     * being shifted to the right. */
	lcd_port_value = (lcd_port_value & LCD_DATA_PINS_MASK) | ((lcd_command & 0xF0) >> 1);

    /* Enable the E pin. */
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);
    _delay_ms(1);
    /* Write the command value to the port. */
	GPIO_writePort(LCD_DATA_PORT_ID, lcd_port_value);
    _delay_ms(1);
    /* Set the E pin to low. */
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_LOW);
    _delay_ms(5);


    /* Read the current value of the LCD_DATA_PORT_ID. */
    GPIO_readPort(LCD_DATA_PORT_ID, &lcd_port_value);
    /* Mask the port with 0b1xxxx111 to preserve the state of the bits, and OR it with the lower nibble
     * being shifted to the right. */
    lcd_port_value = (lcd_port_value & LCD_DATA_PINS_MASK) | ((lcd_command & 0x0F) << 3);

    /* Enable the E pin. */
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);
    _delay_ms(1);
    GPIO_writePort(LCD_DATA_PORT_ID, lcd_port_value);
    _delay_ms(1);
    /* Set the E pin to low. */
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_LOW);
    _delay_ms(2);
#endif
}

/**
 * @brief Displays the specified character on the LCD display.
 * To send data to the LCD module the following must be performed:
 * 1. Set the LCD RS pin to high.
 * 2. Set the LCD RW pin to low.
 * 3. Toggle the LCD EN pin to high.
 * 4. Send the upper nibble.
 * 5. Toggle the LCD EN pin to low.
 * 6. Toggle the LCD EN pin to high.
 * 7. Send the lower nibble.
 * 8. Toggle the LCD EN pin to low.
 * @param[in] character The selected character to be displayed.
 */
void LCD_displayCharacter(uint8 character) {
    GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_PIN_HIGH);
    //GPIO_writePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_LOW);
    _delay_us(1);
//    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);

#if (LCD_DATA_BITS_MODE == 8)
    GPIO_writePort(LCD_DATA_PORT_ID, character);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_LOW);
	_delay_ms(1);
	
#elif (LCD_DATA_BITS_MODE == 4)
    volatile uint8 lcd_port_value = 0;

    /* Read the current value of the LCD_DATA_PORT_ID. */
    GPIO_readPort(LCD_DATA_PORT_ID, &lcd_port_value);
    lcd_port_value = (lcd_port_value & LCD_DATA_PINS_MASK) | ((character & 0xF0) >> 1);

    //GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);
    _delay_ms(1);
    GPIO_writePort(LCD_DATA_PORT_ID, lcd_port_value);
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);
	_delay_ms(1);
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_LOW);
    _delay_ms(2);

//    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);

    /* Read the current value of the LCD_DATA_PORT_ID. */
    GPIO_readPort(LCD_DATA_PORT_ID, &lcd_port_value);
    lcd_port_value = (lcd_port_value & LCD_DATA_PINS_MASK) | ((character & 0x0F) << 3);

    //GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);
    _delay_ms(1);
    GPIO_writePort(LCD_DATA_PORT_ID, lcd_port_value);
	GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_HIGH);
	_delay_ms(1);
    GPIO_writePin(LCD_EN_PORT_ID, LCD_EN_PIN_ID, GPIO_PIN_LOW);
	_delay_ms(5);
#endif
}

/**
 * @brief Displays a whole p_string on the LCD.
 * This is done by iterating over the whole p_string until finding a user defined special character
 * (in this case the value '\0'), and using the LCD_displayCharacter to display every character of the p_string.
 * @param[in] p_string Address of the p_string to be displayed on the LCD.
 */
void LCD_displayString(uint8 *p_string) {
    uint8 index = 0;
    while (p_string[index] != '\0') {
        LCD_displayCharacter(p_string[index]);
        index++;
    }
}

/**
 * @brief Stores a custom character in the CGRAM.
 * Every character consumes 8 bytes of data and the CGRAM is only 64 bytes, thus giving us only 8 custom characters
 * to be defined.
 * The address of the CGRAM starts from 0x40 and ends at 0x7F.
 * So if we wanted to write on the second location (i.e. position 1)
 * we would write to address = 0x40 + (8 * 1)
 * @param custom_character[in] Address of the bitmap representation of the character to be created.
 * @param cgram_location[in] Location in CGRAM to write the custom character in.
 */
void LCD_createCustomCharacter(uint8 *custom_character, uint8 cgram_location) {
    /// Index of every byte of the custom character.
    uint8 custom_character_byte_index = 0;
    /**
     * To write to the CGRAM we must perform the following:
     * 1. Set RS = 0 and RW = 0
     * 2. Set DB7 = 0 and DB6 = 1 (so as to obtain the initial value 0x40)
     * The command to write to CGRAM is the address where we want to write our data (starting from 0x40)
     */
    LCD_sendCommand(0x40 + (cgram_location * 8));
    for (custom_character_byte_index = 0; custom_character_byte_index < 8; custom_character_byte_index++) {
        LCD_displayCharacter(custom_character[custom_character_byte_index]);
    }
}

/**
 * @brief Moves the cursor to a specific row and column on the LCD display.
 * @param row The specified row, either row 0 or row 1.
 * @param col The specified column from 0 to 15.
 */
void LCD_moveCursor(uint8 row,  uint8 col) {
    uint8 lcd_address = 0;
    switch (row) {
        /// First row, the address starts from 0x00 to 0x27.
        case 0:
            lcd_address = col;
            break;
        case 1:
            lcd_address = col + 0x40;
            break;
        default:
            /* Do nothing. */
            ;
    }
    LCD_sendCommand(lcd_address | CMD_LCD_SET_CURSOR_LOCATION);
}
