/*******************************************************************************
* File Name: PWM_DC_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_DC.h"

static PWM_DC_backupStruct PWM_DC_backup;


/*******************************************************************************
* Function Name: PWM_DC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_DC_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_DC_SaveConfig(void) 
{

    #if(!PWM_DC_UsingFixedFunction)
        #if(!PWM_DC_PWMModeIsCenterAligned)
            PWM_DC_backup.PWMPeriod = PWM_DC_ReadPeriod();
        #endif /* (!PWM_DC_PWMModeIsCenterAligned) */
        PWM_DC_backup.PWMUdb = PWM_DC_ReadCounter();
        #if (PWM_DC_UseStatus)
            PWM_DC_backup.InterruptMaskValue = PWM_DC_STATUS_MASK;
        #endif /* (PWM_DC_UseStatus) */

        #if(PWM_DC_DeadBandMode == PWM_DC__B_PWM__DBM_256_CLOCKS || \
            PWM_DC_DeadBandMode == PWM_DC__B_PWM__DBM_2_4_CLOCKS)
            PWM_DC_backup.PWMdeadBandValue = PWM_DC_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_DC_KillModeMinTime)
             PWM_DC_backup.PWMKillCounterPeriod = PWM_DC_ReadKillTime();
        #endif /* (PWM_DC_KillModeMinTime) */

        #if(PWM_DC_UseControl)
            PWM_DC_backup.PWMControlRegister = PWM_DC_ReadControlRegister();
        #endif /* (PWM_DC_UseControl) */
    #endif  /* (!PWM_DC_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_DC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_DC_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_DC_RestoreConfig(void) 
{
        #if(!PWM_DC_UsingFixedFunction)
            #if(!PWM_DC_PWMModeIsCenterAligned)
                PWM_DC_WritePeriod(PWM_DC_backup.PWMPeriod);
            #endif /* (!PWM_DC_PWMModeIsCenterAligned) */

            PWM_DC_WriteCounter(PWM_DC_backup.PWMUdb);

            #if (PWM_DC_UseStatus)
                PWM_DC_STATUS_MASK = PWM_DC_backup.InterruptMaskValue;
            #endif /* (PWM_DC_UseStatus) */

            #if(PWM_DC_DeadBandMode == PWM_DC__B_PWM__DBM_256_CLOCKS || \
                PWM_DC_DeadBandMode == PWM_DC__B_PWM__DBM_2_4_CLOCKS)
                PWM_DC_WriteDeadTime(PWM_DC_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_DC_KillModeMinTime)
                PWM_DC_WriteKillTime(PWM_DC_backup.PWMKillCounterPeriod);
            #endif /* (PWM_DC_KillModeMinTime) */

            #if(PWM_DC_UseControl)
                PWM_DC_WriteControlRegister(PWM_DC_backup.PWMControlRegister);
            #endif /* (PWM_DC_UseControl) */
        #endif  /* (!PWM_DC_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_DC_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_DC_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_DC_Sleep(void) 
{
    #if(PWM_DC_UseControl)
        if(PWM_DC_CTRL_ENABLE == (PWM_DC_CONTROL & PWM_DC_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_DC_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_DC_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_DC_UseControl) */

    /* Stop component */
    PWM_DC_Stop();

    /* Save registers configuration */
    PWM_DC_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_DC_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_DC_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_DC_Wakeup(void) 
{
     /* Restore registers values */
    PWM_DC_RestoreConfig();

    if(PWM_DC_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_DC_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
