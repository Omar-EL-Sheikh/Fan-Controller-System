# Fan-Controller-System
Description:
A fan controller system to control fan speed and state based on measured room temperature on 
ATmega16 microcontroller.
The system uses LM35 temperature sensor to measure room temperature using ADC driver.
The speed of the DC motor is set based on the measured room temperature using PWM.
The state of the motor and temperature read is displayed on LM016L LCD

Programming Language(s):
This project is written in C programming language.

Hardware Implementation:
This project is implemented on ATmega16 MC with a frequency of 1Mhz connected to the 
following components:
  - LM35 Temperature Sensor
  - DC Motor
  - L293D Motor Driver
  - LM016L LCD

Drivers:
  - ADC
  - GPIO
  - PWM
  - DC Motor
  - LCD
  - LM35 Senso
