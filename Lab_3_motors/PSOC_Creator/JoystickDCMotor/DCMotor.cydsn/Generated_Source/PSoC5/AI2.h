/*******************************************************************************
* File Name: AI2.h  
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

#if !defined(CY_PINS_AI2_H) /* Pins AI2_H */
#define CY_PINS_AI2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AI2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AI2__PORT == 15 && ((AI2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AI2_Write(uint8 value);
void    AI2_SetDriveMode(uint8 mode);
uint8   AI2_ReadDataReg(void);
uint8   AI2_Read(void);
void    AI2_SetInterruptMode(uint16 position, uint16 mode);
uint8   AI2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AI2_SetDriveMode() function.
     *  @{
     */
        #define AI2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AI2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AI2_DM_RES_UP          PIN_DM_RES_UP
        #define AI2_DM_RES_DWN         PIN_DM_RES_DWN
        #define AI2_DM_OD_LO           PIN_DM_OD_LO
        #define AI2_DM_OD_HI           PIN_DM_OD_HI
        #define AI2_DM_STRONG          PIN_DM_STRONG
        #define AI2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AI2_MASK               AI2__MASK
#define AI2_SHIFT              AI2__SHIFT
#define AI2_WIDTH              1u

/* Interrupt constants */
#if defined(AI2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AI2_SetInterruptMode() function.
     *  @{
     */
        #define AI2_INTR_NONE      (uint16)(0x0000u)
        #define AI2_INTR_RISING    (uint16)(0x0001u)
        #define AI2_INTR_FALLING   (uint16)(0x0002u)
        #define AI2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AI2_INTR_MASK      (0x01u) 
#endif /* (AI2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AI2_PS                     (* (reg8 *) AI2__PS)
/* Data Register */
#define AI2_DR                     (* (reg8 *) AI2__DR)
/* Port Number */
#define AI2_PRT_NUM                (* (reg8 *) AI2__PRT) 
/* Connect to Analog Globals */                                                  
#define AI2_AG                     (* (reg8 *) AI2__AG)                       
/* Analog MUX bux enable */
#define AI2_AMUX                   (* (reg8 *) AI2__AMUX) 
/* Bidirectional Enable */                                                        
#define AI2_BIE                    (* (reg8 *) AI2__BIE)
/* Bit-mask for Aliased Register Access */
#define AI2_BIT_MASK               (* (reg8 *) AI2__BIT_MASK)
/* Bypass Enable */
#define AI2_BYP                    (* (reg8 *) AI2__BYP)
/* Port wide control signals */                                                   
#define AI2_CTL                    (* (reg8 *) AI2__CTL)
/* Drive Modes */
#define AI2_DM0                    (* (reg8 *) AI2__DM0) 
#define AI2_DM1                    (* (reg8 *) AI2__DM1)
#define AI2_DM2                    (* (reg8 *) AI2__DM2) 
/* Input Buffer Disable Override */
#define AI2_INP_DIS                (* (reg8 *) AI2__INP_DIS)
/* LCD Common or Segment Drive */
#define AI2_LCD_COM_SEG            (* (reg8 *) AI2__LCD_COM_SEG)
/* Enable Segment LCD */
#define AI2_LCD_EN                 (* (reg8 *) AI2__LCD_EN)
/* Slew Rate Control */
#define AI2_SLW                    (* (reg8 *) AI2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AI2_PRTDSI__CAPS_SEL       (* (reg8 *) AI2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AI2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AI2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AI2_PRTDSI__OE_SEL0        (* (reg8 *) AI2__PRTDSI__OE_SEL0) 
#define AI2_PRTDSI__OE_SEL1        (* (reg8 *) AI2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AI2_PRTDSI__OUT_SEL0       (* (reg8 *) AI2__PRTDSI__OUT_SEL0) 
#define AI2_PRTDSI__OUT_SEL1       (* (reg8 *) AI2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AI2_PRTDSI__SYNC_OUT       (* (reg8 *) AI2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AI2__SIO_CFG)
    #define AI2_SIO_HYST_EN        (* (reg8 *) AI2__SIO_HYST_EN)
    #define AI2_SIO_REG_HIFREQ     (* (reg8 *) AI2__SIO_REG_HIFREQ)
    #define AI2_SIO_CFG            (* (reg8 *) AI2__SIO_CFG)
    #define AI2_SIO_DIFF           (* (reg8 *) AI2__SIO_DIFF)
#endif /* (AI2__SIO_CFG) */

/* Interrupt Registers */
#if defined(AI2__INTSTAT)
    #define AI2_INTSTAT            (* (reg8 *) AI2__INTSTAT)
    #define AI2_SNAP               (* (reg8 *) AI2__SNAP)
    
	#define AI2_0_INTTYPE_REG 		(* (reg8 *) AI2__0__INTTYPE)
#endif /* (AI2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AI2_H */


/* [] END OF FILE */
