/*******************************************************************************
* File Name: PWM_Stepper_PM.c
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

#include "PWM_Stepper.h"

static PWM_Stepper_backupStruct PWM_Stepper_backup;


/*******************************************************************************
* Function Name: PWM_Stepper_SaveConfig
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
*  PWM_Stepper_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Stepper_SaveConfig(void) 
{

    #if(!PWM_Stepper_UsingFixedFunction)
        #if(!PWM_Stepper_PWMModeIsCenterAligned)
            PWM_Stepper_backup.PWMPeriod = PWM_Stepper_ReadPeriod();
        #endif /* (!PWM_Stepper_PWMModeIsCenterAligned) */
        PWM_Stepper_backup.PWMUdb = PWM_Stepper_ReadCounter();
        #if (PWM_Stepper_UseStatus)
            PWM_Stepper_backup.InterruptMaskValue = PWM_Stepper_STATUS_MASK;
        #endif /* (PWM_Stepper_UseStatus) */

        #if(PWM_Stepper_DeadBandMode == PWM_Stepper__B_PWM__DBM_256_CLOCKS || \
            PWM_Stepper_DeadBandMode == PWM_Stepper__B_PWM__DBM_2_4_CLOCKS)
            PWM_Stepper_backup.PWMdeadBandValue = PWM_Stepper_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Stepper_KillModeMinTime)
             PWM_Stepper_backup.PWMKillCounterPeriod = PWM_Stepper_ReadKillTime();
        #endif /* (PWM_Stepper_KillModeMinTime) */

        #if(PWM_Stepper_UseControl)
            PWM_Stepper_backup.PWMControlRegister = PWM_Stepper_ReadControlRegister();
        #endif /* (PWM_Stepper_UseControl) */
    #endif  /* (!PWM_Stepper_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Stepper_RestoreConfig
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
*  PWM_Stepper_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Stepper_RestoreConfig(void) 
{
        #if(!PWM_Stepper_UsingFixedFunction)
            #if(!PWM_Stepper_PWMModeIsCenterAligned)
                PWM_Stepper_WritePeriod(PWM_Stepper_backup.PWMPeriod);
            #endif /* (!PWM_Stepper_PWMModeIsCenterAligned) */

            PWM_Stepper_WriteCounter(PWM_Stepper_backup.PWMUdb);

            #if (PWM_Stepper_UseStatus)
                PWM_Stepper_STATUS_MASK = PWM_Stepper_backup.InterruptMaskValue;
            #endif /* (PWM_Stepper_UseStatus) */

            #if(PWM_Stepper_DeadBandMode == PWM_Stepper__B_PWM__DBM_256_CLOCKS || \
                PWM_Stepper_DeadBandMode == PWM_Stepper__B_PWM__DBM_2_4_CLOCKS)
                PWM_Stepper_WriteDeadTime(PWM_Stepper_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Stepper_KillModeMinTime)
                PWM_Stepper_WriteKillTime(PWM_Stepper_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Stepper_KillModeMinTime) */

            #if(PWM_Stepper_UseControl)
                PWM_Stepper_WriteControlRegister(PWM_Stepper_backup.PWMControlRegister);
            #endif /* (PWM_Stepper_UseControl) */
        #endif  /* (!PWM_Stepper_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Stepper_Sleep
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
*  PWM_Stepper_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Stepper_Sleep(void) 
{
    #if(PWM_Stepper_UseControl)
        if(PWM_Stepper_CTRL_ENABLE == (PWM_Stepper_CONTROL & PWM_Stepper_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Stepper_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Stepper_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Stepper_UseControl) */

    /* Stop component */
    PWM_Stepper_Stop();

    /* Save registers configuration */
    PWM_Stepper_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Stepper_Wakeup
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
*  PWM_Stepper_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Stepper_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Stepper_RestoreConfig();

    if(PWM_Stepper_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Stepper_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
