/***************************************************************************//**
* \file IDAC.h
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

#if !defined(CY_IDAC7_IDAC_H)
#define CY_IDAC7_IDAC_H

#include "cyfitter.h"
#include "syslib/cy_syslib.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define IDAC_CURRENT_VALUE        ((uint32_t)0)
#define IDAC_CURRENT_RANGE        ((uint32_t)13)
#define IDAC_CURRENT_POLARITY     ((uint32_t)0)


/**************************************
*    Enumerated Types and Parameters
**************************************/

/* IDAC7 polarity setting constants */
#define IDAC__POL_SOURCE 0
#define IDAC__POL_SINK 1


/* IDAC7 range setting constants */
#define IDAC__RNG_4_96UA 4
#define IDAC__RNG_39_69UA 5
#define IDAC__RNG_317_5UA 6
#define IDAC__RNG_635_0UA 14
#define IDAC__RNG_79_38UA 13
#define IDAC__RNG_9_92UA 12


/* IDAC7 polarity setting definitions */
#define IDAC_POL_SOURCE           ((uint32_t)IDAC__POL_SOURCE)
#define IDAC_POL_SINK             ((uint32_t)IDAC__POL_SINK)

/* IDAC7 range setting definitions */
#define IDAC_RNG_4_96UA           ((uint32_t)IDAC__RNG_4_96UA)
#define IDAC_RNG_9_922UA          ((uint32_t)IDAC__RNG_9_92UA)
#define IDAC_RNG_39_69UA          ((uint32_t)IDAC__RNG_39_69UA)
#define IDAC_RNG_79_38UA          ((uint32_t)IDAC__RNG_79_38UA)
#define IDAC_RNG_317_5UA          ((uint32_t)IDAC__RNG_317_5UA)
#define IDAC_RNG_635_0UA          ((uint32_t)IDAC__RNG_635_0UA)


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
void IDAC_Init(void);
void IDAC_Enable(void);
void IDAC_Start(void);
void IDAC_Stop(void);
void IDAC_SetValue(uint32_t current);
void IDAC_SetPolarity(uint32_t polarity);
void IDAC_SetRange(uint32_t range);
/** @} group_general */

/**
* \addtogroup group_power
* @{
*/
void IDAC_Sleep(void);
void IDAC_Wakeup(void);
/** @} power */


/***************************************
*           Global Variables
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint32_t IDAC_initVar;
/** @} globals */


/***************************************
*            API Constants
***************************************/

/* CSD Config register constants */
#define IDAC_CSD_CONFIG_ENABLE_POS   ((uint32_t)31u)
#define IDAC_CSD_CONFIG_SENSE_EN_POS ((uint32_t)12u)
#define IDAC_CSD_CONFIG_SENSE_EN     ((uint32_t)(0x1u) <<  IDAC_CSD_CONFIG_SENSE_EN_POS)
#define IDAC_CSD_CONFIG_ENABLE       ((uint32_t)(0x1u) <<  IDAC_CSD_CONFIG_ENABLE_POS)

/* IDAC register constants */
#define IDAC_CURRENT_VALUE_POS       ((uint32_t)0u)
#define IDAC_POLY_DYN_POS            ((uint32_t)7u)
#define IDAC_POLARITY_POS            ((uint32_t)8u)
#define IDAC_LEG1_MODE_POS           ((uint32_t)16u)
#define IDAC_LEG2_MODE_POS           ((uint32_t)18u)
#define IDAC_DSI_CTRL_EN_POS         ((uint32_t)21u)
#define IDAC_RANGE_POS               ((uint32_t)22u)
#define IDAC_LEG1_EN_POS             ((uint32_t)24u)
#define IDAC_LEG2_EN_POS             ((uint32_t)25u)

#define IDAC_CURRENT_VALUE_MASK      ((uint32_t)(0x7Fu)  <<  IDAC_CURRENT_VALUE_POS)
#define IDAC_POLARITY_MASK           ((uint32_t)(0x3u)   <<  IDAC_POLARITY_POS)
#define IDAC_POLY_DYN                ((uint32_t)(0x1u)   <<  IDAC_POLY_DYN_POS)
#define IDAC_LEG1_MODE_MASK          ((uint32_t)(0x3u)   <<  IDAC_LEG1_MODE_POS)
#define IDAC_LEG2_MODE_MASK          ((uint32_t)(0x3u)   <<  IDAC_LEG2_MODE_POS)
#define IDAC_DSI_CTRL_EN             ((uint32_t)(0x1u)   <<  IDAC_DSI_CTRL_EN_POS)
#define IDAC_RANGE_MASK              ((uint32_t)(0x3u)   <<  IDAC_RANGE_POS)
#define IDAC_LEG1_EN                 ((uint32_t)(0x1u)   <<  IDAC_LEG1_EN_POS)
#define IDAC_LEG2_EN                 ((uint32_t)(0x1u)   <<  IDAC_LEG2_EN_POS)


/***************************************
*        Registers
***************************************/

/* The pointer to the base address of the HW CSD instance. */
#define IDAC_CSD_HW                  (IDAC_cy_mxs40_csidac__HW)

/* CSD Configuration and Control register */
#define IDAC_CSD_CONTROL_REG         (IDAC_CSD_HW->CONFIG)
#define IDAC_CSD_CONTROL_PTR         ( (reg32 *) &IDAC_CSD_HW->CONFIG)

#if (0 == IDAC_cy_mxs40_csidac__IDX)
    /* IDACA Configuration register */
    #define IDAC_IDAC_CONTROL_REG    (IDAC_CSD_HW->IDACA)
    #define IDAC_IDAC_CONTROL_PTR    ( (reg32 *) &IDAC_CSD_HW->IDACA)
#else
    /* IDACB Configuration register */
    #define IDAC_IDAC_CONTROL_REG    (IDAC_CSD_HW->IDACB)
    #define IDAC_IDAC_CONTROL_PTR    ( (reg32 *) &IDAC_CSD_HW->IDACB)
#endif /* (0 == IDAC_cy_mxs40_csidac__IDX) */

#endif /* CY_IDAC7_IDAC_H */


/* [] END OF FILE */
