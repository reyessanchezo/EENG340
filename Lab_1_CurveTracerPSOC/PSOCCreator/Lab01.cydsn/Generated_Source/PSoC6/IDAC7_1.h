/***************************************************************************//**
* \file IDAC7_1.h
* \version 1.0
*
* \brief
*  This file provides constants and parameter values for the IDAC7
*  component.
*
********************************************************************************
* \copyright
* Copyright 2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_IDAC7_IDAC7_1_H)
#define CY_IDAC7_IDAC7_1_H

#include "cyfitter.h"
#include "syslib/cy_syslib.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define IDAC7_1_CURRENT_VALUE        ((uint32_t)0)
#define IDAC7_1_CURRENT_RANGE        ((uint32_t)13)
#define IDAC7_1_CURRENT_POLARITY     ((uint32_t)0)


/**************************************
*    Enumerated Types and Parameters
**************************************/

/* IDAC7 polarity setting constants */
#define IDAC7_1__POL_SOURCE 0
#define IDAC7_1__POL_SINK 1


/* IDAC7 range setting constants */
#define IDAC7_1__RNG_4_96UA 4
#define IDAC7_1__RNG_39_69UA 5
#define IDAC7_1__RNG_317_5UA 6
#define IDAC7_1__RNG_635_0UA 14
#define IDAC7_1__RNG_79_38UA 13
#define IDAC7_1__RNG_9_92UA 12


/* IDAC7 polarity setting definitions */
#define IDAC7_1_POL_SOURCE           ((uint32_t)IDAC7_1__POL_SOURCE)
#define IDAC7_1_POL_SINK             ((uint32_t)IDAC7_1__POL_SINK)

/* IDAC7 range setting definitions */
#define IDAC7_1_RNG_4_96UA           ((uint32_t)IDAC7_1__RNG_4_96UA)
#define IDAC7_1_RNG_9_922UA          ((uint32_t)IDAC7_1__RNG_9_92UA)
#define IDAC7_1_RNG_39_69UA          ((uint32_t)IDAC7_1__RNG_39_69UA)
#define IDAC7_1_RNG_79_38UA          ((uint32_t)IDAC7_1__RNG_79_38UA)
#define IDAC7_1_RNG_317_5UA          ((uint32_t)IDAC7_1__RNG_317_5UA)
#define IDAC7_1_RNG_635_0UA          ((uint32_t)IDAC7_1__RNG_635_0UA)


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
void IDAC7_1_Init(void);
void IDAC7_1_Enable(void);
void IDAC7_1_Start(void);
void IDAC7_1_Stop(void);
void IDAC7_1_SetValue(uint32_t current);
void IDAC7_1_SetPolarity(uint32_t polarity);
void IDAC7_1_SetRange(uint32_t range);
/** @} group_general */

/**
* \addtogroup group_power
* @{
*/
void IDAC7_1_Sleep(void);
void IDAC7_1_Wakeup(void);
/** @} power */


/***************************************
*           Global Variables
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint32_t IDAC7_1_initVar;
/** @} globals */


/***************************************
*            API Constants
***************************************/

/* CSD Config register constants */
#define IDAC7_1_CSD_CONFIG_ENABLE_POS   ((uint32_t)31u)
#define IDAC7_1_CSD_CONFIG_SENSE_EN_POS ((uint32_t)12u)
#define IDAC7_1_CSD_CONFIG_SENSE_EN     ((uint32_t)(0x1u) <<  IDAC7_1_CSD_CONFIG_SENSE_EN_POS)
#define IDAC7_1_CSD_CONFIG_ENABLE       ((uint32_t)(0x1u) <<  IDAC7_1_CSD_CONFIG_ENABLE_POS)

/* IDAC register constants */
#define IDAC7_1_CURRENT_VALUE_POS       ((uint32_t)0u)
#define IDAC7_1_POLY_DYN_POS            ((uint32_t)7u)
#define IDAC7_1_POLARITY_POS            ((uint32_t)8u)
#define IDAC7_1_LEG1_MODE_POS           ((uint32_t)16u)
#define IDAC7_1_LEG2_MODE_POS           ((uint32_t)18u)
#define IDAC7_1_DSI_CTRL_EN_POS         ((uint32_t)21u)
#define IDAC7_1_RANGE_POS               ((uint32_t)22u)
#define IDAC7_1_LEG1_EN_POS             ((uint32_t)24u)
#define IDAC7_1_LEG2_EN_POS             ((uint32_t)25u)

#define IDAC7_1_CURRENT_VALUE_MASK      ((uint32_t)(0x7Fu)  <<  IDAC7_1_CURRENT_VALUE_POS)
#define IDAC7_1_POLARITY_MASK           ((uint32_t)(0x3u)   <<  IDAC7_1_POLARITY_POS)
#define IDAC7_1_POLY_DYN                ((uint32_t)(0x1u)   <<  IDAC7_1_POLY_DYN_POS)
#define IDAC7_1_LEG1_MODE_MASK          ((uint32_t)(0x3u)   <<  IDAC7_1_LEG1_MODE_POS)
#define IDAC7_1_LEG2_MODE_MASK          ((uint32_t)(0x3u)   <<  IDAC7_1_LEG2_MODE_POS)
#define IDAC7_1_DSI_CTRL_EN             ((uint32_t)(0x1u)   <<  IDAC7_1_DSI_CTRL_EN_POS)
#define IDAC7_1_RANGE_MASK              ((uint32_t)(0x3u)   <<  IDAC7_1_RANGE_POS)
#define IDAC7_1_LEG1_EN                 ((uint32_t)(0x1u)   <<  IDAC7_1_LEG1_EN_POS)
#define IDAC7_1_LEG2_EN                 ((uint32_t)(0x1u)   <<  IDAC7_1_LEG2_EN_POS)


/***************************************
*        Registers
***************************************/

/* The pointer to the base address of the HW CSD instance. */
#define IDAC7_1_CSD_HW                  (IDAC7_1_cy_mxs40_csidac__HW)

/* CSD Configuration and Control register */
#define IDAC7_1_CSD_CONTROL_REG         (IDAC7_1_CSD_HW->CONFIG)
#define IDAC7_1_CSD_CONTROL_PTR         ( (reg32 *) &IDAC7_1_CSD_HW->CONFIG)

#if (0 == IDAC7_1_cy_mxs40_csidac__IDX)
    /* IDACA Configuration register */
    #define IDAC7_1_IDAC_CONTROL_REG    (IDAC7_1_CSD_HW->IDACA)
    #define IDAC7_1_IDAC_CONTROL_PTR    ( (reg32 *) &IDAC7_1_CSD_HW->IDACA)
#else
    /* IDACB Configuration register */
    #define IDAC7_1_IDAC_CONTROL_REG    (IDAC7_1_CSD_HW->IDACB)
    #define IDAC7_1_IDAC_CONTROL_PTR    ( (reg32 *) &IDAC7_1_CSD_HW->IDACB)
#endif /* (0 == IDAC7_1_cy_mxs40_csidac__IDX) */

#endif /* CY_IDAC7_IDAC7_1_H */


/* [] END OF FILE */
