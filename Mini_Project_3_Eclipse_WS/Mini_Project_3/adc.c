/***************************************************************************
 *
 * Module Name: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for ATmega16 ADC Driver
 *
 * Created on: Oct 6, 2022
 *
 * Author: Omar EL-Sheikh
 *
 **************************************************************************/

/***************************************************************************
*								Inclusions
***************************************************************************/
#include"adc.h"
#include"common_macros.h"
#include"avr/io.h"

/***************************************************************************
*								Functions Definitions
***************************************************************************/

/*
 * Description:
 * Function to initialize the ADC driver based on the configurations sent
 */
void ADC_init(const ADC_ConfigType * Config_Ptr){

	/* ADMUX Register Description:
	 * REFS1:0 = Corresponding bits to the specified reference volt
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX &= (0X3F); /* Clearing bits 7:6 in ADMUX register */
	ADMUX |= (Config_Ptr -> ref_volt << 6); /* Setting 7:6 bits in ADMUX register to choose the specified reference volt*/

	/* ADCSRA Register Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 =  Corresponding bits to the specified pre-scaler --> ADC must operate in range 50-200Khz
	 */
	ADCSRA |= (1<<ADEN); /* Enabling ADC */
	ADCSRA &= (0XF8); /* Clearing bits 2:0 in ADCSRA register */
	ADCSRA |= Config_Ptr -> prescaler; /* Setting 2:0 bits in ADCSRA register to choose the specified pre-scaler*/
}

/*
 * Description :
 * Function responsible for reading analog data from a given ADC channel
 * and convert it to digital using the ADC driver and return the digital value.
 */
uint16 ADC_readChannel(uint8 channel){
	channel &= 0x07; /* Input channel number must be from 0-->7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by writing '1' to it */
	return ADC; /* Return the digital value from the ADC data register */
}



