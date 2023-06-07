#ifndef USART_H_
#define USART_H_

#include "../../utilities/std_types.h"

void UART_init(uint16 baudRate);
void UART_sendByte(uint8 *data);
void UART_recieveByte(uint8 *data);
void UART_sendString(uint8 *sendString);
void UART_recieveString();




#endif /* USART_H_ */