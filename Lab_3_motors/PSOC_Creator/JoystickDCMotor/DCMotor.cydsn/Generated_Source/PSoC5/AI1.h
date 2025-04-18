/*******************************************************************************
* File Name: AI1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_AI1_H) /* Pins AI1_H */
#define CY_PINS_AI1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AI1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AI1__PORT == 15 && ((AI1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AI1_Write(uint8 value);
void    AI1_SetDriveMode(uint8 mode);
uint8   AI1_ReadDataReg(void);
uint8   AI1_Read(void);
void    AI1_SetInterruptMode(uint16 position, uint16 mode);
uint8   AI1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AI1_SetDriveMode() function.
     *  @{
     */
        #define AI1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AI1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AI1_DM_RES_UP          PIN_DM_RES_UP
        #define AI1_DM_RES_DWN         PIN_DM_RES_DWN
        #define AI1_DM_OD_LO           PIN_DM_OD_LO
        #define AI1_DM_OD_HI           PIN_DM_OD_HI
        #define AI1_DM_STRONG          PIN_DM_STRONG
        #define AI1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AI1_MASK               AI1__MASK
#define AI1_SHIFT              AI1__SHIFT
#define AI1_WIDTH              1u

/* Interrupt constants */
#if defined(AI1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AI1_SetInterruptMode() function.
     *  @{
     */
        #define AI1_INTR_NONE      (uint16)(0x0000u)
        #define AI1_INTR_RISING    (uint16)(0x0001u)
        #define AI1_INTR_FALLING   (uint16)(0x0002u)
        #define AI1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AI1_INTR_MASK      (0x01u) 
#endif /* (AI1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AI1_PS                     (* (reg8 *) AI1__PS)
/* Data Register */
#define AI1_DR                     (* (reg8 *) AI1__DR)
/* Port Number */
#define AI1_PRT_NUM                (* (reg8 *) AI1__PRT) 
/* Connect to Analog Globals */                                                  
#define AI1_AG                     (* (reg8 *) AI1__AG)                       
/* Analog MUX bux enable */
#define AI1_AMUX                   (* (reg8 *) AI1__AMUX) 
/* Bidirectional Enable */                                                        
#define AI1_BIE                    (* (reg8 *) AI1__BIE)
/* Bit-mask for Aliased Register Access */
#define AI1_BIT_MASK               (* (reg8 *) AI1__BIT_MASK)
/* Bypass Enable */
#define AI1_BYP                    (* (reg8 *) AI1__BYP)
/* Port wide control signals */                                                   
#define AI1_CTL                    (* (reg8 *) AI1__CTL)
/* Drive Modes */
#define AI1_DM0                    (* (reg8 *) AI1__DM0) 
#define AI1_DM1                    (* (reg8 *) AI1__DM1)
#define AI1_DM2                    (* (reg8 *) AI1__DM2) 
/* Input Buffer Disable Override */
#define AI1_INP_DIS                (* (reg8 *) AI1__INP_DIS)
/* LCD Common or Segment Drive */
#define AI1_LCD_COM_SEG            (* (reg8 *) AI1__LCD_COM_SEG)
/* Enable Segment LCD */
#define AI1_LCD_EN                 (* (reg8 *) AI1__LCD_EN)
/* Slew Rate Control */
#define AI1_SLW                    (* (reg8 *) AI1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AI1_PRTDSI__CAPS_SEL       (* (reg8 *) AI1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AI1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AI1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AI1_PRTDSI__OE_SEL0        (* (reg8 *) AI1__PRTDSI__OE_SEL0) 
#define AI1_PRTDSI__OE_SEL1        (* (reg8 *) AI1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AI1_PRTDSI__OUT_SEL0       (* (reg8 *) AI1__PRTDSI__OUT_SEL0) 
#define AI1_PRTDSI__OUT_SEL1       (* (reg8 *) AI1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AI1_PRTDSI__SYNC_OUT       (* (reg8 *) AI1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AI1__SIO_CFG)
    #define AI1_SIO_HYST_EN        (* (reg8 *) AI1__SIO_HYST_EN)
    #define AI1_SIO_REG_HIFREQ     (* (reg8 *) AI1__SIO_REG_HIFREQ)
    #define AI1_SIO_CFG            (* (reg8 *) AI1__SIO_CFG)
    #define AI1_SIO_DIFF           (* (reg8 *) AI1__SIO_DIFF)
#endif /* (AI1__SIO_CFG) */

/* Interrupt Registers */
#if defined(AI1__INTSTAT)
    #define AI1_INTSTAT            (* (reg8 *) AI1__INTSTAT)
    #define AI1_SNAP               (* (reg8 *) AI1__SNAP)
    
	#define AI1_0_INTTYPE_REG 		(* (reg8 *) AI1__0__INTTYPE)
#endif /* (AI1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AI1_H */


/* [] END OF FILE */
