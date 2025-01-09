/*******************************************************************************
* File Name: ISR_MicroServoControl.h
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
#if !defined(CY_ISR_ISR_MicroServoControl_H)
#define CY_ISR_ISR_MicroServoControl_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_MicroServoControl_Start(void);
void ISR_MicroServoControl_StartEx(cyisraddress address);
void ISR_MicroServoControl_Stop(void);

CY_ISR_PROTO(ISR_MicroServoControl_Interrupt);

void ISR_MicroServoControl_SetVector(cyisraddress address);
cyisraddress ISR_MicroServoControl_GetVector(void);

void ISR_MicroServoControl_SetPriority(uint8 priority);
uint8 ISR_MicroServoControl_GetPriority(void);

void ISR_MicroServoControl_Enable(void);
uint8 ISR_MicroServoControl_GetState(void);
void ISR_MicroServoControl_Disable(void);

void ISR_MicroServoControl_SetPending(void);
void ISR_MicroServoControl_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_MicroServoControl ISR. */
#define ISR_MicroServoControl_INTC_VECTOR            ((reg32 *) ISR_MicroServoControl__INTC_VECT)

/* Address of the ISR_MicroServoControl ISR priority. */
#define ISR_MicroServoControl_INTC_PRIOR             ((reg8 *) ISR_MicroServoControl__INTC_PRIOR_REG)

/* Priority of the ISR_MicroServoControl interrupt. */
#define ISR_MicroServoControl_INTC_PRIOR_NUMBER      ISR_MicroServoControl__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_MicroServoControl interrupt. */
#define ISR_MicroServoControl_INTC_SET_EN            ((reg32 *) ISR_MicroServoControl__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_MicroServoControl interrupt. */
#define ISR_MicroServoControl_INTC_CLR_EN            ((reg32 *) ISR_MicroServoControl__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_MicroServoControl interrupt state to pending. */
#define ISR_MicroServoControl_INTC_SET_PD            ((reg32 *) ISR_MicroServoControl__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_MicroServoControl interrupt. */
#define ISR_MicroServoControl_INTC_CLR_PD            ((reg32 *) ISR_MicroServoControl__INTC_CLR_PD_REG)


#endif /* CY_ISR_ISR_MicroServoControl_H */


/* [] END OF FILE */
