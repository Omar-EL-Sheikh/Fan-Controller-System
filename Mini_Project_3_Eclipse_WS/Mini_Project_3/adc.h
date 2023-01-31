/***************************************************************************
 *
 * Module Name: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for ATmega16 ADC Driver
 *
 * Created on: Oct 6, 2022
 *
 * Author: Omar EL-Sheikh
 *
 **************************************************************************/
#ifndef ADC_H_
#define ADC_H_

/***************************************************************************
*								Inclusions
***************************************************************************/
#include"std_types.h"

/***************************************************************************
*								Definitions
***************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 6
#define ADC6 6
#define ADC7 7

/***************************************************************************
*								Types Declaration
***************************************************************************/
typedef enum ADC_ReferenceVolatge {
	AREF, AVCC, INTERNAL_2_56 = 3
} ADC_ReferenceVolatge;

typedef enum ADC_Prescaler {
	F_CPU_2 = 1, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64,
	F_CPU_128
} ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/***************************************************************************
*								Functions Declaration
***************************************************************************/

/*
 * Description :
 * Function responsible for initializing the ADC driver based on configurations
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for reading analog data from a given ADC channel
 * and convert it to digital using the ADC driver and return the digital value.
 */
uint16 ADC_readChannel(uint8 channel);

#endif /* ADC_H_ */
