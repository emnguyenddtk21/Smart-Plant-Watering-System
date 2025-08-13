#include "actuator.h"

void actuator_init (void)
{
	AC_DDR |= 0X0F;
}

void turn_pump_on (void)
{
	AC_PORT |= (1 << PUMP_OUT);
}

void turn_pump_off (void)
{
	AC_PORT &= ~(1 << PUMP_OUT);
}

void turn_led_on(char color)
{
    AC_PORT |= (1 << color);
}

void turn_led_off(char color)
{
	AC_PORT &= ~(1 << color);
}