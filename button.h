#ifndef BUTTON_H
#define BUTTON_H

#include <avr/io.h>
#include <stdint.h>
	
#define BTN_DDR		DDRB
#define BTN_PINR    PINB
#define BTN_PORT	PORTB
#define BTN_MODE    PORTB0
#define BTN_PUMP    PORTB1

#define DEBOUNCE_DELAY 50

void button_init(void);
char mode_read(void);
char pump_read(void);

#endif