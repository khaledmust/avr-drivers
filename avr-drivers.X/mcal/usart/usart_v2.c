/*
 * usart_v2.c
 *
 * Created: 2023-05-25 9:59:02 AM
 *  Author: Khaled
 */ 
#include "usart_v2.h"
#include "../../utilities/common_macros.h"
#include "../../utilities/registers.h"
#include "../../utilities/interrupts.h"

static void (*fptr_USART_txComplete) (void) = NULL;
static void (*fptr_USART_rxComplete) (void) = NULL;
static void (*fptr_USART_bufferEmtpy) (void) = NULL;


static void USART_setBaudRate(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	uint8 baud_rate = 0;
	switch(ptr_st_USART_CONFIG->en_USART_BAUD_RATE) {
		case USART_2400:
			break;
		case USART_4800:
			break;
		case USART_9600:
			baud_rate = 51; // From the data sheet.
			UBRRH = (uint8) (baud_rate >> 8);
			UBRRL = (uint8) baud_rate ;
			break;
		case USART_19200:
			break;
		case USART_115200:
			break;
		default:
		;
			// Do nothing.
		
	}
}

static void USART_setTransmissionSpeed(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	switch(ptr_st_USART_CONFIG->en_USART_TRANSMISSION_SPEED) {
		case USART_NORMAL_SPEED:
			CLEAR_BIT(UCSRA, U2X);
			break;
		case USART_DOUBLE_SPEED:
			SET_BIT(UCSRA, U2X);
			break;
		default:
		;
			// Do nothing.
	}
}

static void USART_setRole(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	switch(ptr_st_USART_CONFIG->en_USART_OPERATION_ROLE) {
		case USART_RX_ROLE:
			SET_BIT(UCSRB, RXEN);
			CLEAR_BIT(UCSRB, TXEN);
			break;
		case USART_TX_ROLE:
			SET_BIT(UCSRB, TXEN);
			CLEAR_BIT(UCSRB, RXEN);
			break;
		case USART_DUAL_ROLE:
			SET_BIT(UCSRB, RXEN);
			SET_BIT(UCSRB, TXEN);
			break;
		default:
		;
			// Do nothing.
	}
}

static void USART_setDataFrameSize(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	/* Enable writing to the UCSRC register. */
	SET_BIT(UCSRC, URSEL);
	
	switch(ptr_st_USART_CONFIG->en_USART_DATA_FRAME_SIZE) {
		case USART_DATA_5_BITS:
			CLEAR_BIT(UCSRC, UCSZ0);
			CLEAR_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_DATA_6_BITS:
			SET_BIT(UCSRC, UCSZ0);
			CLEAR_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_DATA_7_BITS:
			CLEAR_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_DATA_8_BITS:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_DATA_9_BITS:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			SET_BIT(UCSRB, UCSZ2);
			break;
		default:
		;
		// Do nothing.
	}
	CLEAR_BIT(UCSRC, URSEL);
}

static void USART_setOperationMode(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	/* Enable writing to the UCSRC register. */
	SET_BIT(UCSRC, URSEL);
	switch(ptr_st_USART_CONFIG->en_USART_OPERATION_MODE) {
		case USART_ASYNC:
			CLEAR_BIT(UCSRC, UMSEL);
			break;
		case USART_SYNC:
			SET_BIT(UCSRC, UMSEL);
			break;
		default:
		;
			// Do nothing.
	}
	CLEAR_BIT(UCSRC, URSEL);
}

static void USART_setParityBit(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	/* Enable writing to the UCSRC register. */
	SET_BIT(UCSRC, URSEL);
	
	switch(ptr_st_USART_CONFIG->en_USART_PARITY_BIT) {
		case USART_PARITY_DISABLED:
			CLEAR_BIT(UCSRC, UPM0);
			CLEAR_BIT(UCSRC, UPM1);
			break;
		case  USART_PARITY_EVEN:
			CLEAR_BIT(UCSRC, UPM0);
			SET_BIT(UCSRC, UPM1);
			break;
		case USART_PARITY_ODD:
			SET_BIT(UCSRC, UPM0);
			SET_BIT(UCSRC, UPM1);
			break;
		default:
		;
			// Do nothing.
	}
	CLEAR_BIT(UCSRC, URSEL);
}

static void USART_setStopBit(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	/* Enable writing to the UCSRC register. */
	SET_BIT(UCSRC, URSEL);
	
	switch(ptr_st_USART_CONFIG->en_USART_STOP_BIT) {
		case USART_STOP_1_BIT:
			CLEAR_BIT(UCSRC, USBS);
			break;
		case USART_STOP_2_BIT:
			SET_BIT(UCSRC, USBS);
			break;
		default:
		// Do nothing.
		;
	}
	CLEAR_BIT(UCSRC, URSEL);
}

static void USART_enableInterrupt(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	if (ptr_st_USART_CONFIG->en_USART_INTERRUPT_MODE == USART_INTERRUPT_MODE) {
		if (ptr_st_USART_CONFIG->en_USART_OPERATION_ROLE == USART_RX_ROLE) {
			/* Receive complete interrupt enable. */
			SET_BIT(UCSRB, RXCIE);
		} else if (ptr_st_USART_CONFIG->en_USART_OPERATION_ROLE == USART_TX_ROLE) {
			/* Transmit complete interrupt enable. */
			SET_BIT(UCSRB, TXCIE);
			SET_BIT(UCSRB, UDRIE);
		} else if (ptr_st_USART_CONFIG->en_USART_OPERATION_ROLE == USART_DUAL_ROLE) {
			SET_BIT(UCSRB, RXCIE);
			SET_BIT(UCSRB, TXCIE);
			SET_BIT(UCSRB, UDRIE);
		}
	} else {
		// Do nothing.
	}
	/* Enable global interrupt mode. */
	SET_BIT(UCSRB, UDRIE);
	sei();
}

void USART_init(st_USART_CONFIG_t *ptr_st_USART_CONFIG) {
	if (ptr_st_USART_CONFIG != NULL) {
		/* Set the baud rate. */
		USART_setBaudRate(ptr_st_USART_CONFIG);
		USART_enableInterrupt(ptr_st_USART_CONFIG);
		/* Set operation mode. */
		//USART_setOperationMode(ptr_st_USART_CONFIG);
		/* Set operation role. */
		USART_setRole(ptr_st_USART_CONFIG);
		/* Set transmission speed, this is only for the asyncronous mode. */
		//USART_setTransmissionSpeed(ptr_st_USART_CONFIG);
		/* Set data frame size. */
		//USART_setDataFrameSize(ptr_st_USART_CONFIG);
		/* Set parity bit. */
		//USART_setParityBit(ptr_st_USART_CONFIG);
		/* Set number of stop bits. */
		//USART_setStopBit(ptr_st_USART_CONFIG);
		UCSRC = (1<<URSEL)|(3<<UCSZ0);
	} else {
		// Report Error.
	}
}

void USART_sendByte(uint8 data) {
	while(BIT_IS_CLEAR(UCSRA, UDRE)) {};
	UDR = data;
}

void USART_sendByteNonBlocking(void) {
	/* Enable UDR interrupt. */
	UCSRB |= (1 << UDRIE);
}

//void USART_sendByte( unsigned char data ) {
	///* Wait for empty transmit buffer */
	//while ( !( UCSRA & (1<<UDRE)) ) ;
	///* Put data into buffer, sends the data */
	//UDR = data;
//}

uint8 USART_recieveByte(void) {
	while (BIT_IS_CLEAR(UCSRA, RXC)) {};
	return UDR;
}

//unsigned char USART_recieveByte( void ) { 
	///* Wait for data to be received */ 
	//while ( !(UCSRA & (1<<RXC)) ) ; 
	///* Get and return received data from buffer */ 
	//return UDR; 
//}


void USART_sendString(uint8 *ptr_data) {
	uint8 i = 0;
	while (ptr_data[i] != '\0') {
		USART_sendByte(ptr_data[i]);
		i++;
	}
}

void USART_sendStringNonBlocking(uint8 *ptr_data) {
	uint8 index = 0;
	while (ptr_data[index] != '\0') {
		USART_sendByteNonBlocking();
		index++;
	}
}

void USART_recieveString(uint8 *ptr_data) {
	uint8 i = 0;
	
	ptr_data[i] = USART_recieveByte();
	
	while (ptr_data[i] != '#') {
		i++;
		ptr_data[i] = USART_recieveByte();
	}
	ptr_data[i] = '\0';
}

void USART_setCallBack(en_USART_interruptFlag_t en_USART_interruptFlag, void(*fptr_USART_localFunction)(void)) {
	switch (en_USART_interruptFlag) {
		case RX_COMPLETE:
			fptr_USART_rxComplete = fptr_USART_localFunction;
			break;
		case BUFFER_EMPTY:
			fptr_USART_bufferEmtpy = fptr_USART_localFunction;
			break;
		case TX_COMPLETE:
			fptr_USART_txComplete = fptr_USART_localFunction;
			break;
		default:
			;
			// Do nothing.
	}
}

ISR(USART_RXC_vect) {
	if (fptr_USART_rxComplete != NULL) {
		fptr_USART_rxComplete();
	}
}

ISR(USART_UDRE_vect) {
	
	UDR = myString[g_temp];
	    // Disable UDR interrupt.
		UCSRB &= ~(1 << UDRIE);
}

ISR(USART_TXC_vect) {
	//if (fptr_USART_txComplete != NULL) {
		//fptr_USART_txComplete();
	//}
	
	UCSRB |= (1 << UDRIE);
	g_temp++;
	UCSRA |= (1 << TXC);
	   
		   
	    
}