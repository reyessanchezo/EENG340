/***************************************************************************//**
* \file IDAC.c
* \version 1.0
*
* \brief
*  This file provides the source code of APIs for the IDAC7 component.
*
*******************************************************************************
* \copyright
* Copyright 2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IDAC.h"

uint32_t IDAC_initVar = 0u;


/*******************************************************************************
* Function Name: IDAC_Init
****************************************************************************//**
*
*  Initializes all initial parameters and operating modes.
*
*******************************************************************************/
void IDAC_Init(void)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    /* Set IDAC default values */
    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC_IDAC_CONTROL_REG;
    newRegisterValue &= (uint32_t)(~IDAC_POLY_DYN  &
                                 ~IDAC_LEG1_MODE_MASK &
                                 ~IDAC_LEG2_MODE_MASK &
                                 ~IDAC_DSI_CTRL_EN);
    IDAC_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);

    /* Set initial configuration */
    IDAC_SetValue(IDAC_CURRENT_VALUE);
    IDAC_SetPolarity(IDAC_CURRENT_POLARITY);
    IDAC_SetRange(IDAC_CURRENT_RANGE);
}


/*******************************************************************************
* Function Name: IDAC_Enable
****************************************************************************//**
*
*  Enables the IDAC for operation.
*
*******************************************************************************/
void IDAC_Enable(void)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;
	
    interruptState = CyEnterCriticalSection();

    /* Enable CSD */
	newRegisterValue = (uint32_t)IDAC_CSD_CONTROL_REG;
    newRegisterValue |= (IDAC_CSD_CONFIG_ENABLE | IDAC_CSD_CONFIG_SENSE_EN);
    IDAC_CSD_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: IDAC_Start
****************************************************************************//**
*
*  Initializes all the parameters required to setup the component as defined
*  in the customizer.
*
*  This component does not stop the CSD IP block. One possible way to turn off 
*  the entire CSD block is to use a specific define (IDAC_CSD_CONFIG_ENABLE) 
*  for the m0s8csdv2 IP block control register (IDAC_CSD_CONTROL_REG): 
*  IDAC_CSD_CONTROL_REG &= ~IDAC_CSD_CONFIG_ENABLE
*
* \globalvars
*  \ref IDAC_initVar - this variable is used to indicate the initial
*  configuration of this component. The variable is initialized to zero and
*  set to 1 the first time IDAC_Start() is called. This allows
*  the component initialization without re-initialization in all subsequent
*  calls to the IDAC_Start() routine.
*
*******************************************************************************/
void IDAC_Start(void)
{
    if(0u == IDAC_initVar)
    {
        IDAC_Init();
        IDAC_initVar = 1u;
    }

    IDAC_Enable();
}


/*******************************************************************************
* Function Name: IDAC_Stop
****************************************************************************//**
*
*  The Stop is not required.
*
*  This component does not stop the CSD IP block. One possible way to turn off 
*  the entire CSD block is to use a specific define (IDAC_CSD_CONFIG_ENABLE) 
*  for the m0s8csdv2 IP block control register (IDAC_CSD_CONTROL_REG): 
*  IDAC_CSD_CONTROL_REG &= ~IDAC_CSD_CONFIG_ENABLE
*
*******************************************************************************/
void IDAC_Stop(void)
{
    /* Do nothing */
}


/*******************************************************************************
* Function Name: IDAC_SetValue
****************************************************************************//**
*
*  Sets the IDAC current to the new value.
*
*  \param uint32_t current: The current value
*  * Valid range    : [0 - 127]
*
*******************************************************************************/
void IDAC_SetValue(uint32_t current)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC_IDAC_CONTROL_REG & ~IDAC_CURRENT_VALUE_MASK;

    newRegisterValue |= ((current << IDAC_CURRENT_VALUE_POS) & IDAC_CURRENT_VALUE_MASK);

    IDAC_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: IDAC_SetPolarity
****************************************************************************//**
*
*  Sets polarity to either sink or source.
*
*  \param uint32_t polarity: Current polarity
*  * IDAC_POL_SOURCE   : Source polarity
*  * IDAC_POL_SINK     : Sink polarity
*
*******************************************************************************/
void IDAC_SetPolarity(uint32_t polarity)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC_IDAC_CONTROL_REG & ~IDAC_POLARITY_MASK;

    newRegisterValue |= ((polarity << IDAC_POLARITY_POS) & IDAC_POLARITY_MASK);

    IDAC_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: IDAC_SetRange
****************************************************************************//**
*
* Sets the IDAC range to one of the six ranges.
*
*  \param uint32_t range: Current range
*  * IDAC_RNG_4_96UA   : 39.06 nA/bit current range
*  * IDAC_RNG_9_922UA   : 78.125 nA/bit current range
*  * IDAC_RNG_39_69UA   : 312.5 nA/bit current range
*  * IDAC_RNG_79_38UA   : 625 nA/bit current range
*  * IDAC_RNG_317_5UA  : 2.5 uA/bit current range
*  * IDAC_RNG_635_0UA  : 5.0 uA/bit current range
*
*******************************************************************************/
void IDAC_SetRange(uint32_t range)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC_IDAC_CONTROL_REG & (~IDAC_RANGE_MASK    &
                                                            ~IDAC_LEG1_EN       &
                                                            ~IDAC_LEG2_EN);

    newRegisterValue |= (range << IDAC_RANGE_POS);

    IDAC_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/* [] END OF FILE */
