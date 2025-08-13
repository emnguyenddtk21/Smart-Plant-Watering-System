#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer_init(void);
uint32_t millis(void);

#endif