#include "timer.h"

static volatile uint32_t timer_millis = 0;

void timer_init(void)
{
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    OCR0A = 124;
    TIMSK0 = (1 << OCIE0A);
    sei();
}

ISR(TIMER0_COMPA_vect)
{
    timer_millis++;
}

uint32_t millis(void)
{
    uint32_t ms;

    cli();
    ms = timer_millis;
    sei();

    return ms;
}
