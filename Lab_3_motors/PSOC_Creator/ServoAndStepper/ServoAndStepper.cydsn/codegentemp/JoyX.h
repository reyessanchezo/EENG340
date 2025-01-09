/*******************************************************************************
* File Name: JoyX.h  
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

#if !defined(CY_PINS_JoyX_H) /* Pins JoyX_H */
#define CY_PINS_JoyX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "JoyX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 JoyX__PORT == 15 && ((JoyX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    JoyX_Write(uint8 value);
void    JoyX_SetDriveMode(uint8 mode);
uint8   JoyX_ReadDataReg(void);
uint8   JoyX_Read(void);
void    JoyX_SetInterruptMode(uint16 position, uint16 mode);
uint8   JoyX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the JoyX_SetDriveMode() function.
     *  @{
     */
        #define JoyX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define JoyX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define JoyX_DM_RES_UP          PIN_DM_RES_UP
        #define JoyX_DM_RES_DWN         PIN_DM_RES_DWN
        #define JoyX_DM_OD_LO           PIN_DM_OD_LO
        #define JoyX_DM_OD_HI           PIN_DM_OD_HI
        #define JoyX_DM_STRONG          PIN_DM_STRONG
        #define JoyX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define JoyX_MASK               JoyX__MASK
#define JoyX_SHIFT              JoyX__SHIFT
#define JoyX_WIDTH              1u

/* Interrupt constants */
#if defined(JoyX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in JoyX_SetInterruptMode() function.
     *  @{
     */
        #define JoyX_INTR_NONE      (uint16)(0x0000u)
        #define JoyX_INTR_RISING    (uint16)(0x0001u)
        #define JoyX_INTR_FALLING   (uint16)(0x0002u)
        #define JoyX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define JoyX_INTR_MASK      (0x01u) 
#endif /* (JoyX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define JoyX_PS                     (* (reg8 *) JoyX__PS)
/* Data Register */
#define JoyX_DR                     (* (reg8 *) JoyX__DR)
/* Port Number */
#define JoyX_PRT_NUM                (* (reg8 *) JoyX__PRT) 
/* Connect to Analog Globals */                                                  
#define JoyX_AG                     (* (reg8 *) JoyX__AG)                       
/* Analog MUX bux enable */
#define JoyX_AMUX                   (* (reg8 *) JoyX__AMUX) 
/* Bidirectional Enable */                                                        
#define JoyX_BIE                    (* (reg8 *) JoyX__BIE)
/* Bit-mask for Aliased Register Access */
#define JoyX_BIT_MASK               (* (reg8 *) JoyX__BIT_MASK)
/* Bypass Enable */
#define JoyX_BYP                    (* (reg8 *) JoyX__BYP)
/* Port wide control signals */                                                   
#define JoyX_CTL                    (* (reg8 *) JoyX__CTL)
/* Drive Modes */
#define JoyX_DM0                    (* (reg8 *) JoyX__DM0) 
#define JoyX_DM1                    (* (reg8 *) JoyX__DM1)
#define JoyX_DM2                    (* (reg8 *) JoyX__DM2) 
/* Input Buffer Disable Override */
#define JoyX_INP_DIS                (* (reg8 *) JoyX__INP_DIS)
/* LCD Common or Segment Drive */
#define JoyX_LCD_COM_SEG            (* (reg8 *) JoyX__LCD_COM_SEG)
/* Enable Segment LCD */
#define JoyX_LCD_EN                 (* (reg8 *) JoyX__LCD_EN)
/* Slew Rate Control */
#define JoyX_SLW                    (* (reg8 *) JoyX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define JoyX_PRTDSI__CAPS_SEL       (* (reg8 *) JoyX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define JoyX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) JoyX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define JoyX_PRTDSI__OE_SEL0        (* (reg8 *) JoyX__PRTDSI__OE_SEL0) 
#define JoyX_PRTDSI__OE_SEL1        (* (reg8 *) JoyX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define JoyX_PRTDSI__OUT_SEL0       (* (reg8 *) JoyX__PRTDSI__OUT_SEL0) 
#define JoyX_PRTDSI__OUT_SEL1       (* (reg8 *) JoyX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define JoyX_PRTDSI__SYNC_OUT       (* (reg8 *) JoyX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(JoyX__SIO_CFG)
    #define JoyX_SIO_HYST_EN        (* (reg8 *) JoyX__SIO_HYST_EN)
    #define JoyX_SIO_REG_HIFREQ     (* (reg8 *) JoyX__SIO_REG_HIFREQ)
    #define JoyX_SIO_CFG            (* (reg8 *) JoyX__SIO_CFG)
    #define JoyX_SIO_DIFF           (* (reg8 *) JoyX__SIO_DIFF)
#endif /* (JoyX__SIO_CFG) */

/* Interrupt Registers */
#if defined(JoyX__INTSTAT)
    #define JoyX_INTSTAT            (* (reg8 *) JoyX__INTSTAT)
    #define JoyX_SNAP               (* (reg8 *) JoyX__SNAP)
    
	#define JoyX_0_INTTYPE_REG 		(* (reg8 *) JoyX__0__INTTYPE)
#endif /* (JoyX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_JoyX_H */


/* [] END OF FILE */
