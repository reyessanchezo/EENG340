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

static int8 Mouse_Data[3] = {0,0,0}; /* [0] = Buttons, [1] = X-Axis, [2] = Y-Axis */

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() performs following functions:
*  1: Enumerates the PSoC as a HID Mouse.
*  2: Updates Mouse movement data.
*  3: Updates Mouse left click with status of P2[2]
*  4: Waits for ACK from host and then loads new data into EP1.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/

int main()
{
	CYGlobalIntEnable;                        		/* Enable Global Interrupts */
	USBFS_1_Start(0, USBFS_1_DWR_VDDD_OPERATION);   /* Start USBFS Operation/device 0 and with 5V operation */ 	
	while(!USBFS_1_bGetConfiguration()){};      		/* Wait for Device to enumerate */
    USBFS_1_LoadInEP(1, (uint8 *)Mouse_Data, 3); 	/* Loads an inital value into EP1 and sends it out to the PC */
	
    ADC_Start();
    I2C_Start();
    UART_Start();
    UART_PutString("Open\n");
    char buffer[100];
    uint8 i2cdata[10];//10 bytes of data - bytes 3+4, 5+6, and 7 correspond to mousex, mousey, and mousebutton
    double temp;
    
    
	for(;;)
    {
        while(!USBFS_1_bGetEPAckState(1));  			/* Wait for ACK before loading data */
		USBFS_1_LoadInEP(1, (uint8 *)Mouse_Data, 3); 	/* Load latest mouse data into EP1 and send to PC */
	            
        I2C_MasterReadBuf(0x20, i2cdata,10, I2C_MODE_COMPLETE_XFER);
        while(I2C_MasterStatus()!=I2C_MSTAT_RD_CMPLT); //wait for i2c to finish
                      
        Mouse_Data[0] = (1-i2cdata[7]) | (!SW_Read());
        Mouse_Data[1] = ((i2cdata[3]<<8 | i2cdata[4])-31168)/(float)3000;
        Mouse_Data[2] = ((i2cdata[5]<<8 | i2cdata[6])-32768)/(float)3000;
        
        sprintf(buffer, "0:%i\t 1:%i\t 2:%i\t\n",
            Mouse_Data[0], Mouse_Data[1], Mouse_Data[2]);
        
        while(!USBFS_1_bGetEPAckState(1));  			/* Wait for ACK before loading data */
		USBFS_1_LoadInEP(1, (uint8 *)Mouse_Data, 3); 	/* Load latest mouse data into EP1 and send to PC */
	    
        for(int channel = 0; channel < 2; channel++){
            ADC_StartConvert();
            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); 
            temp = (ADC_GetResult16(channel)/128.0)*10.0-10; 
            
            Mouse_Data[channel+1] = temp;
            sprintf(buffer, "channel:%i \t temp:%u \t", channel, (unsigned)temp);
            UART_PutString(buffer);
        
        }
       
        UART_PutString(buffer);
               
		CyDelay(1);
	}
}
/* End of File */


