#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <avr/io.h>

#define AC_DDR     DDRD
#define AC_PORT    PORTD

#define PUMP_OUT        PORTD0
#define LED_NORMAL      PORTD1
#define LED_WATERING    PORTD2
#define LED_LOW_MOISTURE PORTD3

void actuator_init(void);
void turn_pump_on(void);
void turn_pump_off(void);
void turn_led_on(char color);
void turn_led_off(char color);

#endif