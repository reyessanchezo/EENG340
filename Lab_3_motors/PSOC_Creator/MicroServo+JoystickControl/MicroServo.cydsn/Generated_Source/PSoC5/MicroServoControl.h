/*******************************************************************************
* File Name: MicroServoControl.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_MicroServoControl_H)
#define CY_ISR_MicroServoControl_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void MicroServoControl_Start(void);
void MicroServoControl_StartEx(cyisraddress address);
void MicroServoControl_Stop(void);

CY_ISR_PROTO(MicroServoControl_Interrupt);

void MicroServoControl_SetVector(cyisraddress address);
cyisraddress MicroServoControl_GetVector(void);

void MicroServoControl_SetPriority(uint8 priority);
uint8 MicroServoControl_GetPriority(void);

void MicroServoControl_Enable(void);
uint8 MicroServoControl_GetState(void);
void MicroServoControl_Disable(void);

void MicroServoControl_SetPending(void);
void MicroServoControl_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the MicroServoControl ISR. */
#define MicroServoControl_INTC_VECTOR            ((reg32 *) MicroServoControl__INTC_VECT)

/* Address of the MicroServoControl ISR priority. */
#define MicroServoControl_INTC_PRIOR             ((reg8 *) MicroServoControl__INTC_PRIOR_REG)

/* Priority of the MicroServoControl interrupt. */
#define MicroServoControl_INTC_PRIOR_NUMBER      MicroServoControl__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable MicroServoControl interrupt. */
#define MicroServoControl_INTC_SET_EN            ((reg32 *) MicroServoControl__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the MicroServoControl interrupt. */
#define MicroServoControl_INTC_CLR_EN            ((reg32 *) MicroServoControl__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the MicroServoControl interrupt state to pending. */
#define MicroServoControl_INTC_SET_PD            ((reg32 *) MicroServoControl__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the MicroServoControl interrupt. */
#define MicroServoControl_INTC_CLR_PD            ((reg32 *) MicroServoControl__INTC_CLR_PD_REG)


#endif /* CY_ISR_MicroServoControl_H */


/* [] END OF FILE */
