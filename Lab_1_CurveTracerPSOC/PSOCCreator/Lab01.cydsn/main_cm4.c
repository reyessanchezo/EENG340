/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_Start();
    UART_Start();
    IDAC_Start();
    VDAC_Start();
    ADC_SetConvertMode(CY_SAR_START_CONVERT_CONTINUOUS);
    ADC_StartConvert();
    
    uint32_t VCH, VCL, VBH, VBL;
    uint32_t vdac_val = 0, idac_val = 0;

    char buffer[100];
    
    //to get the four channels, pull channel data to 4 different variables or an array of variables
    
    
    for(;;)
    {
        /* At various Base current levels, sweep the VDAC and output the measurements in csv format */
        for(idac_val = 50; idac_val < 70; idac_val += 1) {
            IDAC_SetValue(idac_val);
            for(vdac_val = 10; vdac_val < 4095; vdac_val += 40) {
                VDAC_SetValueBuffered(vdac_val);
                CyDelay(1);
                ADC_StartConvert();
                ADC_IsEndConversion(CY_SAR_WAIT_FOR_RESULT);
                VCH = ADC_GetResult32(0);
                VCL = ADC_GetResult32(1);
                VBH = ADC_GetResult32(2);
                VBL = ADC_GetResult32(3);
                
                //data to voltage = 3.3v/4096*data
        
                //output, tab delimited
                
                sprintf(buffer, "%u\t %u\t %u\t %u\t %u\t %u\n",
                    (unsigned int)VCH, (unsigned int)VCL, 
                    (unsigned int)VBH, (unsigned int)VBL,
                    (unsigned int)idac_val, (unsigned int)vdac_val);
                
                UART_PutString(buffer);
                
            }
            CyDelay(1);
        }
        VDAC_SetValueBuffered(0);
        IDAC_SetValue(0);
        
        /*//IDAC testing
        
        if(direction == 1){
            idac_val += interval;    
        }else
        {
            idac_val -= interval;
        }
        
        if ((idac_val > 120) | (idac_val < 5)) {
            direction *= -1;
        }
        
        
        
        //VDAC testing
        
                
        if(V_direction == 1){
            vdac_val += V_interval;    
        }else
        {
            vdac_val -= V_interval;
        }
        
        if ((vdac_val > 3900) | (vdac_val < 10)) {
            V_direction  *= -1;
        }
        VDAC_SetValueBuffered(vdac_val);
        */
        
        
        
        
        CyDelay(8000);
    }
}

/* [] END OF FILE */
