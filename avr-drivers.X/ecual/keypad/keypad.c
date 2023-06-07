#include "keypad.h"
#include "../../mcal/gpio/gpio.h"

#define UPPER_NIBBLE 0xF0
#define LOWER_NIBBLE 0x0F

/**
 * A constant array that represents the position of the key on the a 4*4 keypad.
 */
const uint8 keypad_keys [4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
};

/**
 * Constant array that represents the actual character on a 4*4 keypad matrix.
 */
const uint8 KEY_LABEL[16] = {'1', '2', '3', 'A',
                             '4', '5', '6', 'B',
                             '7', '8', '9', 'C',
                             '*', '0', '#', 'D'};

/**
 * @brief Initializes the direction of the row keypad pins as output pins, and the columns keypad pins as input pins.
 * This is done by using the GPIO_setPinDirection function from the GPIO driver.
 */
void KEYPAD_init(void) {
    /* Initialize the row pins as output. */
    for (uint8 current_row = 0; current_row < KEYPAD_NUM_ROWS; current_row++) {
        GPIO_setPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row, GPIO_PIN_OUTPUT);
    }

    /* Initialize the column pins as input. */
    for (uint8 current_col = 0; current_col < KEYPAD_NUM_COLS; current_col++) {
        GPIO_setPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_FIRST_COL_PIN_ID + current_col, GPIO_PIN_INPUT);
    }
}

/**
 * @brief Returns the number of position of the key pressed on the keypad matrix.
 * @return An unsigned integer value that represents the position of the key pressed.
 */
uint8 KEYPAD_getKeyPressed(void) {
    /* Used to store the value of the port to preserve the unused pin by the keypad. */
    uint8 keypad_row_port_value;
    volatile uint8 keypad_col_port_value;

    /* Read the current value of the rows port and store it in the local variable. */
    GPIO_readPort(KEYPAD_ROW_PORT_ID, &keypad_row_port_value);

    /* Masking the lower nibble of the port. */
    keypad_row_port_value = (keypad_row_port_value & LOWER_NIBBLE) | (GPIO_PORT_HIGH & UPPER_NIBBLE);

    /* Initiate all the rows as output high and preserve the lower nibble of the port by using the keypad_row_port_value. */
    GPIO_writePort(KEYPAD_ROW_PORT_ID, keypad_row_port_value);

    /* Row iterator. */
    uint8 current_row;

    /* Set the current row to output low and read the current value of the col. */
    for (current_row = 0; current_row < 4; current_row++) {
        /* Toggle the state of the current row. */
        GPIO_togglePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row);
        /* Read the current value of the whole port. */
        GPIO_readPort(KEYPAD_COL_PORT_ID, &keypad_col_port_value);
        /* Mask the columns pins that are connected to the MCU. */
        keypad_col_port_value = (keypad_col_port_value & KEYPAD_COL_PINS);
        /* Checks the value of the port and re-toggles the row pin. */
        switch (keypad_col_port_value) {
            /* Col1: 0bxx1110xx */
            case 0x38:
				GPIO_togglePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row);
                return keypad_keys[current_row][0];
            /* Col2: 0bxx1101xx */
            case 0x34:
				GPIO_togglePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row);
                return keypad_keys[current_row][1];
            /* Col3: 0bxx1011xx */
            case 0x2C:
				GPIO_togglePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row);
                return keypad_keys[current_row][2];
            /* Col4: 0bxx0111xx */
            case 0x1C:
				GPIO_togglePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row);
                return keypad_keys[current_row][3];
            default:
                GPIO_togglePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID + current_row);
        }
    }
}

/**
 * @brief Maps the position of the key with the actual value of the keypad.
 * @param current_key_pressed An unsigned integer value that represents the position of the key pressed.
 * @return An unsigned integer of the actual reading of the keypad.
 */
uint8 KEYPAD_mappedKey(uint8 current_key_pressed) {
    return KEY_LABEL[current_key_pressed - 1];
}
