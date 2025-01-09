/*******************************************************************************
* File Name: ABot.h  
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

#if !defined(CY_PINS_ABot_H) /* Pins ABot_H */
#define CY_PINS_ABot_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ABot_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ABot__PORT == 15 && ((ABot__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ABot_Write(uint8 value);
void    ABot_SetDriveMode(uint8 mode);
uint8   ABot_ReadDataReg(void);
uint8   ABot_Read(void);
void    ABot_SetInterruptMode(uint16 position, uint16 mode);
uint8   ABot_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ABot_SetDriveMode() function.
     *  @{
     */
        #define ABot_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ABot_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ABot_DM_RES_UP          PIN_DM_RES_UP
        #define ABot_DM_RES_DWN         PIN_DM_RES_DWN
        #define ABot_DM_OD_LO           PIN_DM_OD_LO
        #define ABot_DM_OD_HI           PIN_DM_OD_HI
        #define ABot_DM_STRONG          PIN_DM_STRONG
        #define ABot_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ABot_MASK               ABot__MASK
#define ABot_SHIFT              ABot__SHIFT
#define ABot_WIDTH              1u

/* Interrupt constants */
#if defined(ABot__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ABot_SetInterruptMode() function.
     *  @{
     */
        #define ABot_INTR_NONE      (uint16)(0x0000u)
        #define ABot_INTR_RISING    (uint16)(0x0001u)
        #define ABot_INTR_FALLING   (uint16)(0x0002u)
        #define ABot_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ABot_INTR_MASK      (0x01u) 
#endif /* (ABot__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ABot_PS                     (* (reg8 *) ABot__PS)
/* Data Register */
#define ABot_DR                     (* (reg8 *) ABot__DR)
/* Port Number */
#define ABot_PRT_NUM                (* (reg8 *) ABot__PRT) 
/* Connect to Analog Globals */                                                  
#define ABot_AG                     (* (reg8 *) ABot__AG)                       
/* Analog MUX bux enable */
#define ABot_AMUX                   (* (reg8 *) ABot__AMUX) 
/* Bidirectional Enable */                                                        
#define ABot_BIE                    (* (reg8 *) ABot__BIE)
/* Bit-mask for Aliased Register Access */
#define ABot_BIT_MASK               (* (reg8 *) ABot__BIT_MASK)
/* Bypass Enable */
#define ABot_BYP                    (* (reg8 *) ABot__BYP)
/* Port wide control signals */                                                   
#define ABot_CTL                    (* (reg8 *) ABot__CTL)
/* Drive Modes */
#define ABot_DM0                    (* (reg8 *) ABot__DM0) 
#define ABot_DM1                    (* (reg8 *) ABot__DM1)
#define ABot_DM2                    (* (reg8 *) ABot__DM2) 
/* Input Buffer Disable Override */
#define ABot_INP_DIS                (* (reg8 *) ABot__INP_DIS)
/* LCD Common or Segment Drive */
#define ABot_LCD_COM_SEG            (* (reg8 *) ABot__LCD_COM_SEG)
/* Enable Segment LCD */
#define ABot_LCD_EN                 (* (reg8 *) ABot__LCD_EN)
/* Slew Rate Control */
#define ABot_SLW                    (* (reg8 *) ABot__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ABot_PRTDSI__CAPS_SEL       (* (reg8 *) ABot__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ABot_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ABot__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ABot_PRTDSI__OE_SEL0        (* (reg8 *) ABot__PRTDSI__OE_SEL0) 
#define ABot_PRTDSI__OE_SEL1        (* (reg8 *) ABot__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ABot_PRTDSI__OUT_SEL0       (* (reg8 *) ABot__PRTDSI__OUT_SEL0) 
#define ABot_PRTDSI__OUT_SEL1       (* (reg8 *) ABot__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ABot_PRTDSI__SYNC_OUT       (* (reg8 *) ABot__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ABot__SIO_CFG)
    #define ABot_SIO_HYST_EN        (* (reg8 *) ABot__SIO_HYST_EN)
    #define ABot_SIO_REG_HIFREQ     (* (reg8 *) ABot__SIO_REG_HIFREQ)
    #define ABot_SIO_CFG            (* (reg8 *) ABot__SIO_CFG)
    #define ABot_SIO_DIFF           (* (reg8 *) ABot__SIO_DIFF)
#endif /* (ABot__SIO_CFG) */

/* Interrupt Registers */
#if defined(ABot__INTSTAT)
    #define ABot_INTSTAT            (* (reg8 *) ABot__INTSTAT)
    #define ABot_SNAP               (* (reg8 *) ABot__SNAP)
    
	#define ABot_0_INTTYPE_REG 		(* (reg8 *) ABot__0__INTTYPE)
#endif /* (ABot__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ABot_H */


/* [] END OF FILE */
