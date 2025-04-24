
#include <xc.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "adc.h"

void main(void) {
    
    /* Store ADC result */
    /* float Vadc=0; */
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();
    
    /* Config ADC */
    ADC_Initialize();
    
    /* infinite loop */
    while(1)
    {
     /* Start ADC conversion */
     ADC_Start();
        
     /* Wait for Go = 0 */
	 while (ADC_conversionComplete)
         ;

     /* Write ADC result (low) to RB7:RB6 */
	 LATD = ADRESL;

	 /* Write ADC result (high) to RC7:RC0 */
	 LATC = ADRESH;
    
     /* Convert to analog voltage */
     //Vadc = ADRES * (float)19.6E-03;
     
     } /* while */
        
    
    return;
} /* main*/
