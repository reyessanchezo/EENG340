/******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description: Joystick control for DC Motor. Uses joystick for speed and direction control of a dc gearmotor.
*******************************************************************************/


#include <project.h>
#include <stdio.h>
#include <stdlib.h>

double temp = 0;
int range = 450;


CY_ISR(DCMotorControl)
{
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); 
    temp = (ADC_GetResult16(0)/128.0)*range-range; //reading channel zero, horizontal
    //temp should range from -450 to +450

    //Set PWM, 475 being ~95% duty cycle since the drivers are limited by the charge pump
    PWM_DC_WriteCompare(abs((int)temp));
    
    //Set direction based on sign of temp
    if(temp > 15){
        //CCW
        DriverControlReg_Write(1);
        
    }else if(temp < -15){   
        //CW
        DriverControlReg_Write(2);
    }else{
        /*//Brake, both grounded FETs activated... Don't do this, the source goes into over-voltage protection
        DriverControlReg_Write(3);
        PWM_DC_WriteCompare(range);
        */
        DriverControlReg_Write(1);
        PWM_DC_WriteCompare(0);
    }
    //Don't set DriverControlReg to 0, that activates both top FETs connecting 12v to 12v.
}


CY_ISR(DCMotorControl);


int main()
{
	CYGlobalIntEnable;                        		/* Enable Global Interrupts */
	
    
    PWM_DC_Start();
    ADC_Start();
    UART_Start();
    UART_PutString("UART Open\n");
    char buffer[100];
    ISR_DCMotorControl_StartEx(DCMotorControl);
    
    
    
	for(;;)
    {
        
        
        sprintf(buffer, "temp:%i\n", (int)temp);
        UART_PutString(buffer);
        
		CyDelay(1);
	}
    
}



/* End of File */


