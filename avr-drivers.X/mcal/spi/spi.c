#include "spi.h"
#include "../../utilities/common_macros.h"
#include "../../utilities/registers.h"

/**
 * @brief Initializes the MCU as an SPI slave.
 * This is done by setting the MOSI and SCK pins output and all other pins as input.
 * Then configure the control register as follows:
 * SPIE    = 0 Disable SPI Interrupt
 * SPE     = 1 Enable SPI Driver
 * DORD    = 0 Transmit the MSB first
 * MSTR    = 1 Enable Master
 * CPOL    = 0 SCK is low when idle
 * CPHA    = 0 Sample Data with the raising edge
 * SPR1:0  = 00 Choose SPI clock = F_osc/4
 */
void SPI_initMaster(void) {

    /// SS (PB4) -> Output
	SET_BIT(DDRB, PIN4_ID);

    /// MOSI (PB5) -> Output
	SET_BIT(DDRB, PIN5_ID);

    /// MISO (PB6) -> Input
	CLEAR_BIT(DDRB, PIN6_ID);

    /// SCK (PB7) -> Output
	SET_BIT(DDRB, PIN7_ID);

    /// Enable Master
	SET_BIT(SPCR, MSTR);
	
	 /// Enable SPI
	 SET_BIT(SPCR, SPE);
	
	/// Choose SPI clock = F_osc/4
	CLEAR_BIT(SPSR, SPI2X);
}

/**
 * @brief Initializes the MCU as an SPI slave.
 * This is done by setting the MISO output and all other pins as input.
 * Then configure the control register as follows:
 * SPIE    = 0 Disable SPI Interrupt
 * SPE     = 1 Enable SPI Driver
 * DORD    = 0 Transmit the MSB first
 * MSTR    = 1 Enable Master
 * CPOL    = 0 SCK is low when idle
 * CPHA    = 0 Sample Data with the raising edge
 * SPR1:0  = 00 Choose SPI clock = F_osc/4
 */
void SPI_initSlave(void) {

    /// SS (PB4) -> Input
	CLEAR_BIT(DDRB, PIN4_ID);

    /// MOSI (PB5) -> Input
	CLEAR_BIT(DDRB, PIN5_ID);

    /// MISO (PB6) -> Output
	SET_BIT(DDRB, PIN6_ID);

    /// SCK (PB7) -> Input
	CLEAR_BIT(DDRB, PIN7_ID);

    /// Enable SPI
	SET_BIT(SPCR, SPE);
	
	/// Choose SPI clock = F_osc/4
	CLEAR_BIT(SPSR, SPI2X);
}

/**
 * @brief Send/Receive a single byte to/from an SPI slave/master.
 * This is done because of the shift register mechanism applied for the SPI, and that is,
 * to receive a byte we have to first send any byte of data.
 * @param[in] data A single byte of data to be sent to the slave to get out the required byte.
 * @return A byte of data that is the content of the SPDR of the SPI.
 */
uint8 SPI_sendReceiveByte(uint8 data) {
	
	/* Bring CS level down. */
	CLEAR_BIT(PORTB, PIN4_ID);
	
	/* Initiate the communication. */
	SPDR = data;
	
	/* Wait until SPI interrupt flag SPIF = 1 which indicates data has been sent/received correctly. */
	while(BIT_IS_CLEAR(SPSR,SPIF)){}
		
	return SPDR;
}

/**
 * @brief Sends a whole string.
 * This is done by sending a sigle byte at a time until reaching the null terminating character.
 * @param[in] string A pointer to the string to be sent.
 */
void SPI_sendString(const uint8 *string) {
	uint8 index = 0;
	volatile uint8 tmp = 0;
	
	while(string[index] != '\0') {
		tmp = SPI_sendReceiveByte(string[index]);
		index++;
	}
}

/**
 * @brief Receive a whole string.
 * This is done by receiving a single byte at a time until reaching a special character that is agreed upon from the TX and RX.
 * Then the addition of the null terminating character to the string.
 * @param[in] string A pointer to the variable where we will store the string.
 */
void SPI_reveiveString(uint8 *string) {
	uint8 index = 0;
	
	string[index] = SPI_sendReceiveByte(SPI_DUMMY_DATA_VALUE);
	
	while(string[index] != '#') {
		index ++;
		string[index] = SPI_sendReceiveByte(SPI_DUMMY_DATA_VALUE);
	}
	string[index] = '\0';
}