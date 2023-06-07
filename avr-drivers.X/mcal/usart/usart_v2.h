/*
 * usart_v2.h
 *
 * Created: 2023-05-25 9:59:17 AM
 *  Author: khale
 */ 


#ifndef USART_V2_H_
#define USART_V2_H_

#include "../../utilities/std_types.h"

extern uint8 g_temp ;
extern char myString[10];

/**
 * @enum en_USART_TRANSMISSION_SPEED_t
 * @brief Specifies the transmission speed of the USART module.
 */
typedef enum {
	USART_NORMAL_SPEED = 0, USART_DOUBLE_SPEED	
}en_USART_TRANSMISSION_SPEED_t;

/**
 * @enum en_USART_OPERATION_ROLE_t
 * @brief Specifies the operation role of the USART module.
 */
typedef enum {
		USART_RX_ROLE = 0, USART_TX_ROLE, USART_DUAL_ROLE
}en_USART_OPERATION_ROLE_t;

/**
 * @enum en_USART_DATA_FRAME_SIZE_t
 * @brief SPecifies the data frame size of the USART module.
 */
typedef enum {
	USART_DATA_5_BITS = 0, USART_DATA_6_BITS, USART_DATA_7_BITS, USART_DATA_8_BITS, USART_DATA_9_BITS
}en_USART_DATA_FRAME_SIZE_t;

/**
 * @enum en_USART_OPERATION_MODE_t
 * @brief SPecifies the operation mode of the USART module.
 * The USART module would be operating in asynchronous or synchronous mode.
 */
typedef enum {
	USART_ASYNC = 0, USART_SYNC
}en_USART_OPERATION_MODE_t;

/**
 * @enum en_USART_PARITY_BIT_t
 * @brief Specifies the parity bit option for the USART module.
 */
typedef enum {
	USART_PARITY_DISABLED = 0, USART_PARITY_EVEN, USART_PARITY_ODD	
}en_USART_PARITY_BIT_t;

/**
 * @enum en_USART_STOP_BIT_t
 * @brief Specifies the number of stop bits in the data frame.
 */
typedef enum {
	USART_STOP_1_BIT = 0, USART_STOP_2_BIT
}en_USART_STOP_BIT_t;

/**
 * @enum en_USART_BAUD_RATE_t
 * @brief Specifies the baud rate of the USART module in case of asynchronous mode.
 */
typedef enum {
	USART_2400, USART_4800, USART_9600, USART_19200, USART_115200
}en_USART_BAUD_RATE_t;

typedef enum {
	USART_POLLING_MODE, USART_INTERRUPT_MODE 
}en_USART_INTERRUPT_MODE_t;

typedef enum {
	RX_COMPLETE, BUFFER_EMPTY, TX_COMPLETE
}en_USART_interruptFlag_t;

/**
 * Configuration structure of the USART module.
 */
typedef struct {
	en_USART_BAUD_RATE_t en_USART_BAUD_RATE;
	en_USART_OPERATION_MODE_t en_USART_OPERATION_MODE;
	en_USART_OPERATION_ROLE_t en_USART_OPERATION_ROLE;
	en_USART_TRANSMISSION_SPEED_t en_USART_TRANSMISSION_SPEED;
	en_USART_DATA_FRAME_SIZE_t en_USART_DATA_FRAME_SIZE;
	en_USART_PARITY_BIT_t en_USART_PARITY_BIT;
	en_USART_STOP_BIT_t en_USART_STOP_BIT;
	en_USART_INTERRUPT_MODE_t en_USART_INTERRUPT_MODE;
}st_USART_CONFIG_t;

/**
 * @brief Initializes the USART module with the specific user configuration.
 * @param[in] ptr_st_USART_CONFIG Address of the user configuration structure of the USART module.
 */
void USART_init(st_USART_CONFIG_t *ptr_st_USART_CONFIG);

/**
 * @brief Sends a single byte of data.
 * @param[in] ptr_data Address of one byte of data to be sent.
 */
void USART_sendByte(uint8 data);

/**
 * @brief Receives a single byte from the Rx side.
 * @param[out] ptr_data Address of the variable where the data is written to.
 */
uint8 USART_recieveByte(void);

/**
 * @brief Sends a whole string.
 * @param[in] ptr_data Address of the string to be sent.
 */
void USART_sendString(uint8 *ptr_data);

/**
 * @brief Receives a whole string.
 * @param[out] ptr_data Address of the variable where the string is written to.
 */
void USART_recieveString(uint8 *ptr_data);

void USART_setCallBack(en_USART_interruptFlag_t en_USART_interruptFlag, void(*fptr_USART_localFunction)(void));
void USART_sendByteNonBlocking(void);
void USART_sendStringNonBlocking(uint8 *ptr_data);
#endif /* USART_V2_H_ */