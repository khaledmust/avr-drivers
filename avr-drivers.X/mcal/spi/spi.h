#ifndef SPI_H_
#define SPI_H_

#include "../../utilities/std_types.h"

/**
 * SPI dummy value used to receive a byte from the other device.
 */
#define SPI_DUMMY_DATA_VALUE 0xFF

/**
 * @brief Initializes the MCU as an SPI master.
 */
void SPI_initMaster(void);

/**
 * @brief Initializes the MCU as an SPI slave.
 */
void SPI_initSlave(void);

/**
 * @brief Send/Receive a single byte to/from an SPI slave/master.
 * @param[in] data A single byte of data to be sent to the slave to get out the required byte.
 * @return A byte of data that is the content of the SPDR of the SPI.
 */
uint8 SPI_sendReceiveByte(uint8 data);

void SPI_reveiveString(uint8 *string);
void SPI_sendString(const uint8 *string);

#endif /* SPI_H_ */