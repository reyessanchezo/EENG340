/*******************************************************************************
* File Name: AIn2.h  
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

#if !defined(CY_PINS_AIn2_H) /* Pins AIn2_H */
#define CY_PINS_AIn2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AIn2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AIn2__PORT == 15 && ((AIn2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AIn2_Write(uint8 value);
void    AIn2_SetDriveMode(uint8 mode);
uint8   AIn2_ReadDataReg(void);
uint8   AIn2_Read(void);
void    AIn2_SetInterruptMode(uint16 position, uint16 mode);
uint8   AIn2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AIn2_SetDriveMode() function.
     *  @{
     */
        #define AIn2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AIn2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AIn2_DM_RES_UP          PIN_DM_RES_UP
        #define AIn2_DM_RES_DWN         PIN_DM_RES_DWN
        #define AIn2_DM_OD_LO           PIN_DM_OD_LO
        #define AIn2_DM_OD_HI           PIN_DM_OD_HI
        #define AIn2_DM_STRONG          PIN_DM_STRONG
        #define AIn2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AIn2_MASK               AIn2__MASK
#define AIn2_SHIFT              AIn2__SHIFT
#define AIn2_WIDTH              1u

/* Interrupt constants */
#if defined(AIn2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AIn2_SetInterruptMode() function.
     *  @{
     */
        #define AIn2_INTR_NONE      (uint16)(0x0000u)
        #define AIn2_INTR_RISING    (uint16)(0x0001u)
        #define AIn2_INTR_FALLING   (uint16)(0x0002u)
        #define AIn2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AIn2_INTR_MASK      (0x01u) 
#endif /* (AIn2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AIn2_PS                     (* (reg8 *) AIn2__PS)
/* Data Register */
#define AIn2_DR                     (* (reg8 *) AIn2__DR)
/* Port Number */
#define AIn2_PRT_NUM                (* (reg8 *) AIn2__PRT) 
/* Connect to Analog Globals */                                                  
#define AIn2_AG                     (* (reg8 *) AIn2__AG)                       
/* Analog MUX bux enable */
#define AIn2_AMUX                   (* (reg8 *) AIn2__AMUX) 
/* Bidirectional Enable */                                                        
#define AIn2_BIE                    (* (reg8 *) AIn2__BIE)
/* Bit-mask for Aliased Register Access */
#define AIn2_BIT_MASK               (* (reg8 *) AIn2__BIT_MASK)
/* Bypass Enable */
#define AIn2_BYP                    (* (reg8 *) AIn2__BYP)
/* Port wide control signals */                                                   
#define AIn2_CTL                    (* (reg8 *) AIn2__CTL)
/* Drive Modes */
#define AIn2_DM0                    (* (reg8 *) AIn2__DM0) 
#define AIn2_DM1                    (* (reg8 *) AIn2__DM1)
#define AIn2_DM2                    (* (reg8 *) AIn2__DM2) 
/* Input Buffer Disable Override */
#define AIn2_INP_DIS                (* (reg8 *) AIn2__INP_DIS)
/* LCD Common or Segment Drive */
#define AIn2_LCD_COM_SEG            (* (reg8 *) AIn2__LCD_COM_SEG)
/* Enable Segment LCD */
#define AIn2_LCD_EN                 (* (reg8 *) AIn2__LCD_EN)
/* Slew Rate Control */
#define AIn2_SLW                    (* (reg8 *) AIn2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AIn2_PRTDSI__CAPS_SEL       (* (reg8 *) AIn2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AIn2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AIn2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AIn2_PRTDSI__OE_SEL0        (* (reg8 *) AIn2__PRTDSI__OE_SEL0) 
#define AIn2_PRTDSI__OE_SEL1        (* (reg8 *) AIn2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AIn2_PRTDSI__OUT_SEL0       (* (reg8 *) AIn2__PRTDSI__OUT_SEL0) 
#define AIn2_PRTDSI__OUT_SEL1       (* (reg8 *) AIn2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AIn2_PRTDSI__SYNC_OUT       (* (reg8 *) AIn2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AIn2__SIO_CFG)
    #define AIn2_SIO_HYST_EN        (* (reg8 *) AIn2__SIO_HYST_EN)
    #define AIn2_SIO_REG_HIFREQ     (* (reg8 *) AIn2__SIO_REG_HIFREQ)
    #define AIn2_SIO_CFG            (* (reg8 *) AIn2__SIO_CFG)
    #define AIn2_SIO_DIFF           (* (reg8 *) AIn2__SIO_DIFF)
#endif /* (AIn2__SIO_CFG) */

/* Interrupt Registers */
#if defined(AIn2__INTSTAT)
    #define AIn2_INTSTAT            (* (reg8 *) AIn2__INTSTAT)
    #define AIn2_SNAP               (* (reg8 *) AIn2__SNAP)
    
	#define AIn2_0_INTTYPE_REG 		(* (reg8 *) AIn2__0__INTTYPE)
#endif /* (AIn2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AIn2_H */


/* [] END OF FILE */
