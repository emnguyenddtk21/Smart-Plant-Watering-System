#include "adc.h"

void ADC_init(void)
{
    DDRC = 0x00;
    ADCSRA = 0x87;
    ADMUX = 0x40;
}

uint16_t ADC_read(uint8_t channel)
{
    ADMUX = 0x40 | (channel & 0x07);
    ADCSRA |= (1 << ADSC);
    while (!(ADCSRA & (1 << ADIF)));
    ADCSRA |= (1 << ADIF);
    return ADCW;
}