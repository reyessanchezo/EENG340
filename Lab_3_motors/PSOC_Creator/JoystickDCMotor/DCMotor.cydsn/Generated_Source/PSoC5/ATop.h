/*******************************************************************************
* File Name: ATop.h  
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

#if !defined(CY_PINS_ATop_H) /* Pins ATop_H */
#define CY_PINS_ATop_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ATop_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ATop__PORT == 15 && ((ATop__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ATop_Write(uint8 value);
void    ATop_SetDriveMode(uint8 mode);
uint8   ATop_ReadDataReg(void);
uint8   ATop_Read(void);
void    ATop_SetInterruptMode(uint16 position, uint16 mode);
uint8   ATop_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ATop_SetDriveMode() function.
     *  @{
     */
        #define ATop_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ATop_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ATop_DM_RES_UP          PIN_DM_RES_UP
        #define ATop_DM_RES_DWN         PIN_DM_RES_DWN
        #define ATop_DM_OD_LO           PIN_DM_OD_LO
        #define ATop_DM_OD_HI           PIN_DM_OD_HI
        #define ATop_DM_STRONG          PIN_DM_STRONG
        #define ATop_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ATop_MASK               ATop__MASK
#define ATop_SHIFT              ATop__SHIFT
#define ATop_WIDTH              1u

/* Interrupt constants */
#if defined(ATop__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ATop_SetInterruptMode() function.
     *  @{
     */
        #define ATop_INTR_NONE      (uint16)(0x0000u)
        #define ATop_INTR_RISING    (uint16)(0x0001u)
        #define ATop_INTR_FALLING   (uint16)(0x0002u)
        #define ATop_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ATop_INTR_MASK      (0x01u) 
#endif /* (ATop__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ATop_PS                     (* (reg8 *) ATop__PS)
/* Data Register */
#define ATop_DR                     (* (reg8 *) ATop__DR)
/* Port Number */
#define ATop_PRT_NUM                (* (reg8 *) ATop__PRT) 
/* Connect to Analog Globals */                                                  
#define ATop_AG                     (* (reg8 *) ATop__AG)                       
/* Analog MUX bux enable */
#define ATop_AMUX                   (* (reg8 *) ATop__AMUX) 
/* Bidirectional Enable */                                                        
#define ATop_BIE                    (* (reg8 *) ATop__BIE)
/* Bit-mask for Aliased Register Access */
#define ATop_BIT_MASK               (* (reg8 *) ATop__BIT_MASK)
/* Bypass Enable */
#define ATop_BYP                    (* (reg8 *) ATop__BYP)
/* Port wide control signals */                                                   
#define ATop_CTL                    (* (reg8 *) ATop__CTL)
/* Drive Modes */
#define ATop_DM0                    (* (reg8 *) ATop__DM0) 
#define ATop_DM1                    (* (reg8 *) ATop__DM1)
#define ATop_DM2                    (* (reg8 *) ATop__DM2) 
/* Input Buffer Disable Override */
#define ATop_INP_DIS                (* (reg8 *) ATop__INP_DIS)
/* LCD Common or Segment Drive */
#define ATop_LCD_COM_SEG            (* (reg8 *) ATop__LCD_COM_SEG)
/* Enable Segment LCD */
#define ATop_LCD_EN                 (* (reg8 *) ATop__LCD_EN)
/* Slew Rate Control */
#define ATop_SLW                    (* (reg8 *) ATop__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ATop_PRTDSI__CAPS_SEL       (* (reg8 *) ATop__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ATop_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ATop__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ATop_PRTDSI__OE_SEL0        (* (reg8 *) ATop__PRTDSI__OE_SEL0) 
#define ATop_PRTDSI__OE_SEL1        (* (reg8 *) ATop__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ATop_PRTDSI__OUT_SEL0       (* (reg8 *) ATop__PRTDSI__OUT_SEL0) 
#define ATop_PRTDSI__OUT_SEL1       (* (reg8 *) ATop__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ATop_PRTDSI__SYNC_OUT       (* (reg8 *) ATop__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ATop__SIO_CFG)
    #define ATop_SIO_HYST_EN        (* (reg8 *) ATop__SIO_HYST_EN)
    #define ATop_SIO_REG_HIFREQ     (* (reg8 *) ATop__SIO_REG_HIFREQ)
    #define ATop_SIO_CFG            (* (reg8 *) ATop__SIO_CFG)
    #define ATop_SIO_DIFF           (* (reg8 *) ATop__SIO_DIFF)
#endif /* (ATop__SIO_CFG) */

/* Interrupt Registers */
#if defined(ATop__INTSTAT)
    #define ATop_INTSTAT            (* (reg8 *) ATop__INTSTAT)
    #define ATop_SNAP               (* (reg8 *) ATop__SNAP)
    
	#define ATop_0_INTTYPE_REG 		(* (reg8 *) ATop__0__INTTYPE)
#endif /* (ATop__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ATop_H */


/* [] END OF FILE */
