#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "button.h"
#include "actuator.h"
#include "adc.h"
#include "timer.h"

#define AUTO    0
#define MANUAL  1

#define TEMP_THRESHOLD 30
#define MOIST_THRESHOLD 40

uint16_t moisture = 0;
float celsius = 0;

void MODE_AUTO(void);
void MODE_MANUAL(void);

int main(void)
{
	char mode = AUTO;
	button_init();
	ADC_init();
	actuator_init();
	timer_init();
	
	uint16_t adc_temp;
	uint32_t last_adc_time = 0;

	while(1)
	{
		if (mode_read())  mode = 1 - mode;
		
		if (millis() - last_adc_time >= 300UL)
		{
			adc_temp = ADC_read(0);
			celsius = adc_temp * 0.488f;
			moisture = ADC_read(1);
			last_adc_time = millis();
		}
		
		if (mode == AUTO)
		{
			MODE_AUTO();
		}	
		else
		{
			MODE_MANUAL();
		}
		
	}

	return 0;
}

void MODE_AUTO()
{
	if ((moisture < MOIST_THRESHOLD || celsius > TEMP_THRESHOLD))
	{
		turn_pump_on();
		turn_led_on(LED_WATERING);
		_delay_ms(1000);
		turn_pump_off();
		turn_led_off(LED_WATERING);
	}

	_delay_ms(100);
}

void MODE_MANUAL()
{
	if (pump_read() == 1)
	{
		turn_pump_on();
		turn_led_on(LED_WATERING);
		_delay_ms(1000);
		turn_pump_off();
		turn_led_off(LED_WATERING);
	}

	_delay_ms(100);
}
