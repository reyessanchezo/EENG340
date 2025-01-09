/*******************************************************************************
* File Name: BTop.h  
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

#if !defined(CY_PINS_BTop_H) /* Pins BTop_H */
#define CY_PINS_BTop_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BTop_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BTop__PORT == 15 && ((BTop__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BTop_Write(uint8 value);
void    BTop_SetDriveMode(uint8 mode);
uint8   BTop_ReadDataReg(void);
uint8   BTop_Read(void);
void    BTop_SetInterruptMode(uint16 position, uint16 mode);
uint8   BTop_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BTop_SetDriveMode() function.
     *  @{
     */
        #define BTop_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BTop_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BTop_DM_RES_UP          PIN_DM_RES_UP
        #define BTop_DM_RES_DWN         PIN_DM_RES_DWN
        #define BTop_DM_OD_LO           PIN_DM_OD_LO
        #define BTop_DM_OD_HI           PIN_DM_OD_HI
        #define BTop_DM_STRONG          PIN_DM_STRONG
        #define BTop_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BTop_MASK               BTop__MASK
#define BTop_SHIFT              BTop__SHIFT
#define BTop_WIDTH              1u

/* Interrupt constants */
#if defined(BTop__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BTop_SetInterruptMode() function.
     *  @{
     */
        #define BTop_INTR_NONE      (uint16)(0x0000u)
        #define BTop_INTR_RISING    (uint16)(0x0001u)
        #define BTop_INTR_FALLING   (uint16)(0x0002u)
        #define BTop_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BTop_INTR_MASK      (0x01u) 
#endif /* (BTop__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BTop_PS                     (* (reg8 *) BTop__PS)
/* Data Register */
#define BTop_DR                     (* (reg8 *) BTop__DR)
/* Port Number */
#define BTop_PRT_NUM                (* (reg8 *) BTop__PRT) 
/* Connect to Analog Globals */                                                  
#define BTop_AG                     (* (reg8 *) BTop__AG)                       
/* Analog MUX bux enable */
#define BTop_AMUX                   (* (reg8 *) BTop__AMUX) 
/* Bidirectional Enable */                                                        
#define BTop_BIE                    (* (reg8 *) BTop__BIE)
/* Bit-mask for Aliased Register Access */
#define BTop_BIT_MASK               (* (reg8 *) BTop__BIT_MASK)
/* Bypass Enable */
#define BTop_BYP                    (* (reg8 *) BTop__BYP)
/* Port wide control signals */                                                   
#define BTop_CTL                    (* (reg8 *) BTop__CTL)
/* Drive Modes */
#define BTop_DM0                    (* (reg8 *) BTop__DM0) 
#define BTop_DM1                    (* (reg8 *) BTop__DM1)
#define BTop_DM2                    (* (reg8 *) BTop__DM2) 
/* Input Buffer Disable Override */
#define BTop_INP_DIS                (* (reg8 *) BTop__INP_DIS)
/* LCD Common or Segment Drive */
#define BTop_LCD_COM_SEG            (* (reg8 *) BTop__LCD_COM_SEG)
/* Enable Segment LCD */
#define BTop_LCD_EN                 (* (reg8 *) BTop__LCD_EN)
/* Slew Rate Control */
#define BTop_SLW                    (* (reg8 *) BTop__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BTop_PRTDSI__CAPS_SEL       (* (reg8 *) BTop__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BTop_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BTop__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BTop_PRTDSI__OE_SEL0        (* (reg8 *) BTop__PRTDSI__OE_SEL0) 
#define BTop_PRTDSI__OE_SEL1        (* (reg8 *) BTop__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BTop_PRTDSI__OUT_SEL0       (* (reg8 *) BTop__PRTDSI__OUT_SEL0) 
#define BTop_PRTDSI__OUT_SEL1       (* (reg8 *) BTop__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BTop_PRTDSI__SYNC_OUT       (* (reg8 *) BTop__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BTop__SIO_CFG)
    #define BTop_SIO_HYST_EN        (* (reg8 *) BTop__SIO_HYST_EN)
    #define BTop_SIO_REG_HIFREQ     (* (reg8 *) BTop__SIO_REG_HIFREQ)
    #define BTop_SIO_CFG            (* (reg8 *) BTop__SIO_CFG)
    #define BTop_SIO_DIFF           (* (reg8 *) BTop__SIO_DIFF)
#endif /* (BTop__SIO_CFG) */

/* Interrupt Registers */
#if defined(BTop__INTSTAT)
    #define BTop_INTSTAT            (* (reg8 *) BTop__INTSTAT)
    #define BTop_SNAP               (* (reg8 *) BTop__SNAP)
    
	#define BTop_0_INTTYPE_REG 		(* (reg8 *) BTop__0__INTTYPE)
#endif /* (BTop__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BTop_H */


/* [] END OF FILE */
