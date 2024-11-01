#include <xc.h>
#include "adc.h"

void ADC_Initialize(void)
{
	/* ADC enabled; ADC single conversion; ADC clock is Fosc; result left justified */
	ADCON0 = 0x80;

    /* ADC clock frequency = Fosc / (2*(19+1)) = 1.6 MHz */
	ADCLK = 0x13;

    /* ADC Input channel is RA1/ANA1 */
    ADPCH = 0x01;
}


void ADC_Start(void)
{
	/* GO = 1 */
	ADCON0 |= 0x01;
}

