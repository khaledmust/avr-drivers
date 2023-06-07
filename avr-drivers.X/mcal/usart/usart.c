#include "usart.h"
#include "../../utilities/common_macros.h"
#include "../../utilities/registers.h"
/**
 * @brief 
 * This is done by:
 * 1. Set the baud rate.
 * 2. Enable receiver and transmitter.
 * 3. Set frame format.
 */
void UART_init(uint16 baudRate) {
	UBRRH = (uint8) (baudRate >> 8);
	UBRRL = (uint8) baudRate;
	
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
	
	/* Acessing UCSRC. */
	SET_BIT(UCSRC, URSEL);
	
	/* 2-bits stop. */
	CLEAR_BIT(UCSRC, USBS);
	
	SET_BIT(UCSRC, UCSZ0);
	SET_BIT(UCSRC, UCSZ1);
	
}
void UART_sendByte(uint8 *data) {
	while (BIT_IS_CLEAR(UCSRA, UDRE)) {};
	UDR = *data;
}
void UART_recieveByte(uint8 *data) {
	while (BIT_IS_CLEAR(UCSRA, RXC)) {};
		
	*data = UDR;
}
void UART_sendString(uint8 *sendString);
void UART_recieveString();
