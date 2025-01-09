/*******************************************************************************
* File Name: BBot.h  
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

#if !defined(CY_PINS_BBot_H) /* Pins BBot_H */
#define CY_PINS_BBot_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BBot_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BBot__PORT == 15 && ((BBot__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BBot_Write(uint8 value);
void    BBot_SetDriveMode(uint8 mode);
uint8   BBot_ReadDataReg(void);
uint8   BBot_Read(void);
void    BBot_SetInterruptMode(uint16 position, uint16 mode);
uint8   BBot_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BBot_SetDriveMode() function.
     *  @{
     */
        #define BBot_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BBot_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BBot_DM_RES_UP          PIN_DM_RES_UP
        #define BBot_DM_RES_DWN         PIN_DM_RES_DWN
        #define BBot_DM_OD_LO           PIN_DM_OD_LO
        #define BBot_DM_OD_HI           PIN_DM_OD_HI
        #define BBot_DM_STRONG          PIN_DM_STRONG
        #define BBot_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BBot_MASK               BBot__MASK
#define BBot_SHIFT              BBot__SHIFT
#define BBot_WIDTH              1u

/* Interrupt constants */
#if defined(BBot__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BBot_SetInterruptMode() function.
     *  @{
     */
        #define BBot_INTR_NONE      (uint16)(0x0000u)
        #define BBot_INTR_RISING    (uint16)(0x0001u)
        #define BBot_INTR_FALLING   (uint16)(0x0002u)
        #define BBot_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BBot_INTR_MASK      (0x01u) 
#endif /* (BBot__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BBot_PS                     (* (reg8 *) BBot__PS)
/* Data Register */
#define BBot_DR                     (* (reg8 *) BBot__DR)
/* Port Number */
#define BBot_PRT_NUM                (* (reg8 *) BBot__PRT) 
/* Connect to Analog Globals */                                                  
#define BBot_AG                     (* (reg8 *) BBot__AG)                       
/* Analog MUX bux enable */
#define BBot_AMUX                   (* (reg8 *) BBot__AMUX) 
/* Bidirectional Enable */                                                        
#define BBot_BIE                    (* (reg8 *) BBot__BIE)
/* Bit-mask for Aliased Register Access */
#define BBot_BIT_MASK               (* (reg8 *) BBot__BIT_MASK)
/* Bypass Enable */
#define BBot_BYP                    (* (reg8 *) BBot__BYP)
/* Port wide control signals */                                                   
#define BBot_CTL                    (* (reg8 *) BBot__CTL)
/* Drive Modes */
#define BBot_DM0                    (* (reg8 *) BBot__DM0) 
#define BBot_DM1                    (* (reg8 *) BBot__DM1)
#define BBot_DM2                    (* (reg8 *) BBot__DM2) 
/* Input Buffer Disable Override */
#define BBot_INP_DIS                (* (reg8 *) BBot__INP_DIS)
/* LCD Common or Segment Drive */
#define BBot_LCD_COM_SEG            (* (reg8 *) BBot__LCD_COM_SEG)
/* Enable Segment LCD */
#define BBot_LCD_EN                 (* (reg8 *) BBot__LCD_EN)
/* Slew Rate Control */
#define BBot_SLW                    (* (reg8 *) BBot__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BBot_PRTDSI__CAPS_SEL       (* (reg8 *) BBot__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BBot_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BBot__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BBot_PRTDSI__OE_SEL0        (* (reg8 *) BBot__PRTDSI__OE_SEL0) 
#define BBot_PRTDSI__OE_SEL1        (* (reg8 *) BBot__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BBot_PRTDSI__OUT_SEL0       (* (reg8 *) BBot__PRTDSI__OUT_SEL0) 
#define BBot_PRTDSI__OUT_SEL1       (* (reg8 *) BBot__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BBot_PRTDSI__SYNC_OUT       (* (reg8 *) BBot__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BBot__SIO_CFG)
    #define BBot_SIO_HYST_EN        (* (reg8 *) BBot__SIO_HYST_EN)
    #define BBot_SIO_REG_HIFREQ     (* (reg8 *) BBot__SIO_REG_HIFREQ)
    #define BBot_SIO_CFG            (* (reg8 *) BBot__SIO_CFG)
    #define BBot_SIO_DIFF           (* (reg8 *) BBot__SIO_DIFF)
#endif /* (BBot__SIO_CFG) */

/* Interrupt Registers */
#if defined(BBot__INTSTAT)
    #define BBot_INTSTAT            (* (reg8 *) BBot__INTSTAT)
    #define BBot_SNAP               (* (reg8 *) BBot__SNAP)
    
	#define BBot_0_INTTYPE_REG 		(* (reg8 *) BBot__0__INTTYPE)
#endif /* (BBot__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BBot_H */


/* [] END OF FILE */
