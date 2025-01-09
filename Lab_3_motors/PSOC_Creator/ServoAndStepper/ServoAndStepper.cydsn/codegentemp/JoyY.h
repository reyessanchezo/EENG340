/*******************************************************************************
* File Name: JoyY.h  
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

#if !defined(CY_PINS_JoyY_H) /* Pins JoyY_H */
#define CY_PINS_JoyY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "JoyY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 JoyY__PORT == 15 && ((JoyY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    JoyY_Write(uint8 value);
void    JoyY_SetDriveMode(uint8 mode);
uint8   JoyY_ReadDataReg(void);
uint8   JoyY_Read(void);
void    JoyY_SetInterruptMode(uint16 position, uint16 mode);
uint8   JoyY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the JoyY_SetDriveMode() function.
     *  @{
     */
        #define JoyY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define JoyY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define JoyY_DM_RES_UP          PIN_DM_RES_UP
        #define JoyY_DM_RES_DWN         PIN_DM_RES_DWN
        #define JoyY_DM_OD_LO           PIN_DM_OD_LO
        #define JoyY_DM_OD_HI           PIN_DM_OD_HI
        #define JoyY_DM_STRONG          PIN_DM_STRONG
        #define JoyY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define JoyY_MASK               JoyY__MASK
#define JoyY_SHIFT              JoyY__SHIFT
#define JoyY_WIDTH              1u

/* Interrupt constants */
#if defined(JoyY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in JoyY_SetInterruptMode() function.
     *  @{
     */
        #define JoyY_INTR_NONE      (uint16)(0x0000u)
        #define JoyY_INTR_RISING    (uint16)(0x0001u)
        #define JoyY_INTR_FALLING   (uint16)(0x0002u)
        #define JoyY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define JoyY_INTR_MASK      (0x01u) 
#endif /* (JoyY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define JoyY_PS                     (* (reg8 *) JoyY__PS)
/* Data Register */
#define JoyY_DR                     (* (reg8 *) JoyY__DR)
/* Port Number */
#define JoyY_PRT_NUM                (* (reg8 *) JoyY__PRT) 
/* Connect to Analog Globals */                                                  
#define JoyY_AG                     (* (reg8 *) JoyY__AG)                       
/* Analog MUX bux enable */
#define JoyY_AMUX                   (* (reg8 *) JoyY__AMUX) 
/* Bidirectional Enable */                                                        
#define JoyY_BIE                    (* (reg8 *) JoyY__BIE)
/* Bit-mask for Aliased Register Access */
#define JoyY_BIT_MASK               (* (reg8 *) JoyY__BIT_MASK)
/* Bypass Enable */
#define JoyY_BYP                    (* (reg8 *) JoyY__BYP)
/* Port wide control signals */                                                   
#define JoyY_CTL                    (* (reg8 *) JoyY__CTL)
/* Drive Modes */
#define JoyY_DM0                    (* (reg8 *) JoyY__DM0) 
#define JoyY_DM1                    (* (reg8 *) JoyY__DM1)
#define JoyY_DM2                    (* (reg8 *) JoyY__DM2) 
/* Input Buffer Disable Override */
#define JoyY_INP_DIS                (* (reg8 *) JoyY__INP_DIS)
/* LCD Common or Segment Drive */
#define JoyY_LCD_COM_SEG            (* (reg8 *) JoyY__LCD_COM_SEG)
/* Enable Segment LCD */
#define JoyY_LCD_EN                 (* (reg8 *) JoyY__LCD_EN)
/* Slew Rate Control */
#define JoyY_SLW                    (* (reg8 *) JoyY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define JoyY_PRTDSI__CAPS_SEL       (* (reg8 *) JoyY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define JoyY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) JoyY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define JoyY_PRTDSI__OE_SEL0        (* (reg8 *) JoyY__PRTDSI__OE_SEL0) 
#define JoyY_PRTDSI__OE_SEL1        (* (reg8 *) JoyY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define JoyY_PRTDSI__OUT_SEL0       (* (reg8 *) JoyY__PRTDSI__OUT_SEL0) 
#define JoyY_PRTDSI__OUT_SEL1       (* (reg8 *) JoyY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define JoyY_PRTDSI__SYNC_OUT       (* (reg8 *) JoyY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(JoyY__SIO_CFG)
    #define JoyY_SIO_HYST_EN        (* (reg8 *) JoyY__SIO_HYST_EN)
    #define JoyY_SIO_REG_HIFREQ     (* (reg8 *) JoyY__SIO_REG_HIFREQ)
    #define JoyY_SIO_CFG            (* (reg8 *) JoyY__SIO_CFG)
    #define JoyY_SIO_DIFF           (* (reg8 *) JoyY__SIO_DIFF)
#endif /* (JoyY__SIO_CFG) */

/* Interrupt Registers */
#if defined(JoyY__INTSTAT)
    #define JoyY_INTSTAT            (* (reg8 *) JoyY__INTSTAT)
    #define JoyY_SNAP               (* (reg8 *) JoyY__SNAP)
    
	#define JoyY_0_INTTYPE_REG 		(* (reg8 *) JoyY__0__INTTYPE)
#endif /* (JoyY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_JoyY_H */


/* [] END OF FILE */
