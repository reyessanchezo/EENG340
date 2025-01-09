/*******************************************************************************
* File Name: AIn1.h  
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

#if !defined(CY_PINS_AIn1_H) /* Pins AIn1_H */
#define CY_PINS_AIn1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AIn1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AIn1__PORT == 15 && ((AIn1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AIn1_Write(uint8 value);
void    AIn1_SetDriveMode(uint8 mode);
uint8   AIn1_ReadDataReg(void);
uint8   AIn1_Read(void);
void    AIn1_SetInterruptMode(uint16 position, uint16 mode);
uint8   AIn1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AIn1_SetDriveMode() function.
     *  @{
     */
        #define AIn1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AIn1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AIn1_DM_RES_UP          PIN_DM_RES_UP
        #define AIn1_DM_RES_DWN         PIN_DM_RES_DWN
        #define AIn1_DM_OD_LO           PIN_DM_OD_LO
        #define AIn1_DM_OD_HI           PIN_DM_OD_HI
        #define AIn1_DM_STRONG          PIN_DM_STRONG
        #define AIn1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AIn1_MASK               AIn1__MASK
#define AIn1_SHIFT              AIn1__SHIFT
#define AIn1_WIDTH              1u

/* Interrupt constants */
#if defined(AIn1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AIn1_SetInterruptMode() function.
     *  @{
     */
        #define AIn1_INTR_NONE      (uint16)(0x0000u)
        #define AIn1_INTR_RISING    (uint16)(0x0001u)
        #define AIn1_INTR_FALLING   (uint16)(0x0002u)
        #define AIn1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AIn1_INTR_MASK      (0x01u) 
#endif /* (AIn1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AIn1_PS                     (* (reg8 *) AIn1__PS)
/* Data Register */
#define AIn1_DR                     (* (reg8 *) AIn1__DR)
/* Port Number */
#define AIn1_PRT_NUM                (* (reg8 *) AIn1__PRT) 
/* Connect to Analog Globals */                                                  
#define AIn1_AG                     (* (reg8 *) AIn1__AG)                       
/* Analog MUX bux enable */
#define AIn1_AMUX                   (* (reg8 *) AIn1__AMUX) 
/* Bidirectional Enable */                                                        
#define AIn1_BIE                    (* (reg8 *) AIn1__BIE)
/* Bit-mask for Aliased Register Access */
#define AIn1_BIT_MASK               (* (reg8 *) AIn1__BIT_MASK)
/* Bypass Enable */
#define AIn1_BYP                    (* (reg8 *) AIn1__BYP)
/* Port wide control signals */                                                   
#define AIn1_CTL                    (* (reg8 *) AIn1__CTL)
/* Drive Modes */
#define AIn1_DM0                    (* (reg8 *) AIn1__DM0) 
#define AIn1_DM1                    (* (reg8 *) AIn1__DM1)
#define AIn1_DM2                    (* (reg8 *) AIn1__DM2) 
/* Input Buffer Disable Override */
#define AIn1_INP_DIS                (* (reg8 *) AIn1__INP_DIS)
/* LCD Common or Segment Drive */
#define AIn1_LCD_COM_SEG            (* (reg8 *) AIn1__LCD_COM_SEG)
/* Enable Segment LCD */
#define AIn1_LCD_EN                 (* (reg8 *) AIn1__LCD_EN)
/* Slew Rate Control */
#define AIn1_SLW                    (* (reg8 *) AIn1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AIn1_PRTDSI__CAPS_SEL       (* (reg8 *) AIn1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AIn1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AIn1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AIn1_PRTDSI__OE_SEL0        (* (reg8 *) AIn1__PRTDSI__OE_SEL0) 
#define AIn1_PRTDSI__OE_SEL1        (* (reg8 *) AIn1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AIn1_PRTDSI__OUT_SEL0       (* (reg8 *) AIn1__PRTDSI__OUT_SEL0) 
#define AIn1_PRTDSI__OUT_SEL1       (* (reg8 *) AIn1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AIn1_PRTDSI__SYNC_OUT       (* (reg8 *) AIn1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AIn1__SIO_CFG)
    #define AIn1_SIO_HYST_EN        (* (reg8 *) AIn1__SIO_HYST_EN)
    #define AIn1_SIO_REG_HIFREQ     (* (reg8 *) AIn1__SIO_REG_HIFREQ)
    #define AIn1_SIO_CFG            (* (reg8 *) AIn1__SIO_CFG)
    #define AIn1_SIO_DIFF           (* (reg8 *) AIn1__SIO_DIFF)
#endif /* (AIn1__SIO_CFG) */

/* Interrupt Registers */
#if defined(AIn1__INTSTAT)
    #define AIn1_INTSTAT            (* (reg8 *) AIn1__INTSTAT)
    #define AIn1_SNAP               (* (reg8 *) AIn1__SNAP)
    
	#define AIn1_0_INTTYPE_REG 		(* (reg8 *) AIn1__0__INTTYPE)
#endif /* (AIn1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AIn1_H */


/* [] END OF FILE */
