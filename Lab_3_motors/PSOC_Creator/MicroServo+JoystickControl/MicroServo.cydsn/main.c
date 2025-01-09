/******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description: This is the source code for the HID Mouse code example.
*
* Related Document: CE195394_HID_Mouse.pdf
*
* Hardware Dependency: See CE195394_HID_Mouse.pdf
*
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/


#include <project.h>
#include <stdio.h>

static uint default_compare = 18500; //should be 0 degrees on the servo
double temp = 0;


CY_ISR(MicroServoControl)
{
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); 
    temp = (ADC_GetResult16(0)/127.0)*950-1150; //reading channel zero, horizontal
    //temp values rang from -1150 to 757, which correspond pretty closely to 0 to 180 degrees on the micro servo

    PWM_WriteCompare(default_compare+temp);
}


CY_ISR(MicroServoControl);




int main()
{
	CYGlobalIntEnable;                        		/* Enable Global Interrupts */
	
    PWM_Start();
    ADC_Start();
    UART_Start();
    UART_PutString("UART Open\n");
    char buffer[100];
    ISR_MicroServoControl_StartEx(MicroServoControl);
    
    
    
	for(;;)
    {
        
        
        sprintf(buffer, "temp:%i\n", (int)temp);
        UART_PutString(buffer);
        
		CyDelay(1);
	}
    
}



/* End of File */


