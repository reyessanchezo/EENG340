/***************************************************************************//**
* \file IDAC7_1.c
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

#include "IDAC7_1.h"

uint32_t IDAC7_1_initVar = 0u;


/*******************************************************************************
* Function Name: IDAC7_1_Init
****************************************************************************//**
*
*  Initializes all initial parameters and operating modes.
*
*******************************************************************************/
void IDAC7_1_Init(void)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    /* Set IDAC default values */
    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC7_1_IDAC_CONTROL_REG;
    newRegisterValue &= (uint32_t)(~IDAC7_1_POLY_DYN  &
                                 ~IDAC7_1_LEG1_MODE_MASK &
                                 ~IDAC7_1_LEG2_MODE_MASK &
                                 ~IDAC7_1_DSI_CTRL_EN);
    IDAC7_1_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);

    /* Set initial configuration */
    IDAC7_1_SetValue(IDAC7_1_CURRENT_VALUE);
    IDAC7_1_SetPolarity(IDAC7_1_CURRENT_POLARITY);
    IDAC7_1_SetRange(IDAC7_1_CURRENT_RANGE);
}


/*******************************************************************************
* Function Name: IDAC7_1_Enable
****************************************************************************//**
*
*  Enables the IDAC for operation.
*
*******************************************************************************/
void IDAC7_1_Enable(void)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;
	
    interruptState = CyEnterCriticalSection();

    /* Enable CSD */
	newRegisterValue = (uint32_t)IDAC7_1_CSD_CONTROL_REG;
    newRegisterValue |= (IDAC7_1_CSD_CONFIG_ENABLE | IDAC7_1_CSD_CONFIG_SENSE_EN);
    IDAC7_1_CSD_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: IDAC7_1_Start
****************************************************************************//**
*
*  Initializes all the parameters required to setup the component as defined
*  in the customizer.
*
*  This component does not stop the CSD IP block. One possible way to turn off 
*  the entire CSD block is to use a specific define (IDAC7_1_CSD_CONFIG_ENABLE) 
*  for the m0s8csdv2 IP block control register (IDAC7_1_CSD_CONTROL_REG): 
*  IDAC7_1_CSD_CONTROL_REG &= ~IDAC7_1_CSD_CONFIG_ENABLE
*
* \globalvars
*  \ref IDAC7_1_initVar - this variable is used to indicate the initial
*  configuration of this component. The variable is initialized to zero and
*  set to 1 the first time IDAC7_1_Start() is called. This allows
*  the component initialization without re-initialization in all subsequent
*  calls to the IDAC7_1_Start() routine.
*
*******************************************************************************/
void IDAC7_1_Start(void)
{
    if(0u == IDAC7_1_initVar)
    {
        IDAC7_1_Init();
        IDAC7_1_initVar = 1u;
    }

    IDAC7_1_Enable();
}


/*******************************************************************************
* Function Name: IDAC7_1_Stop
****************************************************************************//**
*
*  The Stop is not required.
*
*  This component does not stop the CSD IP block. One possible way to turn off 
*  the entire CSD block is to use a specific define (IDAC7_1_CSD_CONFIG_ENABLE) 
*  for the m0s8csdv2 IP block control register (IDAC7_1_CSD_CONTROL_REG): 
*  IDAC7_1_CSD_CONTROL_REG &= ~IDAC7_1_CSD_CONFIG_ENABLE
*
*******************************************************************************/
void IDAC7_1_Stop(void)
{
    /* Do nothing */
}


/*******************************************************************************
* Function Name: IDAC7_1_SetValue
****************************************************************************//**
*
*  Sets the IDAC current to the new value.
*
*  \param uint32_t current: The current value
*  * Valid range    : [0 - 127]
*
*******************************************************************************/
void IDAC7_1_SetValue(uint32_t current)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC7_1_IDAC_CONTROL_REG & ~IDAC7_1_CURRENT_VALUE_MASK;

    newRegisterValue |= ((current << IDAC7_1_CURRENT_VALUE_POS) & IDAC7_1_CURRENT_VALUE_MASK);

    IDAC7_1_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: IDAC7_1_SetPolarity
****************************************************************************//**
*
*  Sets polarity to either sink or source.
*
*  \param uint32_t polarity: Current polarity
*  * IDAC7_1_POL_SOURCE   : Source polarity
*  * IDAC7_1_POL_SINK     : Sink polarity
*
*******************************************************************************/
void IDAC7_1_SetPolarity(uint32_t polarity)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC7_1_IDAC_CONTROL_REG & ~IDAC7_1_POLARITY_MASK;

    newRegisterValue |= ((polarity << IDAC7_1_POLARITY_POS) & IDAC7_1_POLARITY_MASK);

    IDAC7_1_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: IDAC7_1_SetRange
****************************************************************************//**
*
* Sets the IDAC range to one of the six ranges.
*
*  \param uint32_t range: Current range
*  * IDAC7_1_RNG_4_96UA   : 39.06 nA/bit current range
*  * IDAC7_1_RNG_9_922UA   : 78.125 nA/bit current range
*  * IDAC7_1_RNG_39_69UA   : 312.5 nA/bit current range
*  * IDAC7_1_RNG_79_38UA   : 625 nA/bit current range
*  * IDAC7_1_RNG_317_5UA  : 2.5 uA/bit current range
*  * IDAC7_1_RNG_635_0UA  : 5.0 uA/bit current range
*
*******************************************************************************/
void IDAC7_1_SetRange(uint32_t range)
{
    uint32_t interruptState;
    uint32_t newRegisterValue;

    interruptState = CyEnterCriticalSection();

    newRegisterValue = (uint32_t)IDAC7_1_IDAC_CONTROL_REG & (~IDAC7_1_RANGE_MASK    &
                                                            ~IDAC7_1_LEG1_EN       &
                                                            ~IDAC7_1_LEG2_EN);

    newRegisterValue |= (range << IDAC7_1_RANGE_POS);

    IDAC7_1_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(interruptState);
}


/* [] END OF FILE */
