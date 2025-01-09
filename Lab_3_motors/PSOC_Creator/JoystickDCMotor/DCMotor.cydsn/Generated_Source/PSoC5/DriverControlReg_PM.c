/*******************************************************************************
* File Name: DriverControlReg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DriverControlReg.h"

/* Check for removal by optimization */
#if !defined(DriverControlReg_Sync_ctrl_reg__REMOVED)

static DriverControlReg_BACKUP_STRUCT  DriverControlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: DriverControlReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DriverControlReg_SaveConfig(void) 
{
    DriverControlReg_backup.controlState = DriverControlReg_Control;
}


/*******************************************************************************
* Function Name: DriverControlReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void DriverControlReg_RestoreConfig(void) 
{
     DriverControlReg_Control = DriverControlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: DriverControlReg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DriverControlReg_Sleep(void) 
{
    DriverControlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: DriverControlReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DriverControlReg_Wakeup(void)  
{
    DriverControlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
