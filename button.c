#include "button.h"
#include "timer.h" 

void button_init(void) {
    BTN_DDR &= ~((1 << BTN_MODE) | (1 << BTN_PUMP));
    BTN_PORT |= (1 << BTN_MODE) | (1 << BTN_PUMP);
}

char mode_read(void)
{
	static uint32_t last_press = 0;
	if (!(BTN_PINR & (1 << BTN_MODE)))
	{
		if (millis() - last_press > DEBOUNCE_DELAY)
		{
			last_press = millis();
			return 1;
		}
	}
	return 0;
}

char pump_read(void)
{
	static uint32_t last_press = 0;
	if (!(BTN_PINR & (1 << BTN_PUMP)))
	{
		if (millis() - last_press > DEBOUNCE_DELAY)
		{
			last_press = millis();
			return 1;
		}
	}
	return 0;
}