/******************************************************************************
* File Name: main.c
*
* Description: Joystick control for microservo and stepper motor
*
*******************************************************************************/


#include <project.h>
#include <stdio.h>
#include <stdlib.h>

static uint default_compare = 18500; //should be 0 degrees on the servo
double temp = 0;
char buffer[100];
uint Stepper_Direction;

CY_ISR(MicroServoControl)
{
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); 
    temp = (ADC_GetResult16(0)/127.0)*950-1150; //reading channel zero, horizontal
    //temp values rang from -1150 to 757, which correspond pretty closely to 0 to 180 degrees on the micro servo

    PWM_Servo_WriteCompare(default_compare+temp);
}

CY_ISR(StepperControl)
{
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); 
    temp = (ADC_GetResult16(1)/127.0)*75-75; //Reading channel one, vertical
    //temp values should range from -100 to 100 +/- 1. 
    //instead of pwm control it should be delay control.
    
    //change timer delay depending on temp value
    //delay has a minimum of 500 microseconds. to go from 0 to 100% speed, 
    
    //Set speed based on magnitude of temp
    //Accomplished by dividing the clock going to the PWM for the stepper
    //from 50 MHz (0.3ms) to 0.5 MHz (30ms), divide clock by up to 100.
    Stepper_Clock_SetDivider(100/(abs((int)temp+1)));
    
    //disable stepping if joystick is neutral
    if((int)temp == 0){
        Stepper_Clock_StopBlock();
      }
    else{
        Stepper_Clock_Start();
    }
    //Set direction based on sign of temp
    if(temp > 0){
        Stepper_Direction_Write(1);
    }else{   
        Stepper_Direction_Write(0);
    }
    sprintf(buffer, "Stepper temp:%i\tdivider: %u\n", (int)temp, (100/abs((int)temp)+1));
        UART_PutString(buffer);
    
}
    
CY_ISR(StepperControl);

CY_ISR(MicroServoControl);




int main()
{
	CYGlobalIntEnable;                        		/* Enable Global Interrupts */
	
    PWM_Stepper_Start();
    PWM_Servo_Start();
    ADC_Start();
    UART_Start();
    UART_PutString("UART Open\n");
    
    ISR_MicroServoControl_StartEx(MicroServoControl);
    ISR_StepperControl_StartEx(StepperControl);
    
    
    
	for(;;)
    {
        
        
        sprintf(buffer, "temp:%i\n", (int)temp);
        //UART_PutString(buffer);
        
		CyDelay(1);
	}
    
}



/* End of File */


