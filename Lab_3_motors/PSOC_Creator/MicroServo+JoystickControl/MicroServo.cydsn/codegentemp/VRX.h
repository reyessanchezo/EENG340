/*******************************************************************************
* File Name: VRX.h  
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

#if !defined(CY_PINS_VRX_H) /* Pins VRX_H */
#define CY_PINS_VRX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VRX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VRX__PORT == 15 && ((VRX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VRX_Write(uint8 value);
void    VRX_SetDriveMode(uint8 mode);
uint8   VRX_ReadDataReg(void);
uint8   VRX_Read(void);
void    VRX_SetInterruptMode(uint16 position, uint16 mode);
uint8   VRX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VRX_SetDriveMode() function.
     *  @{
     */
        #define VRX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VRX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VRX_DM_RES_UP          PIN_DM_RES_UP
        #define VRX_DM_RES_DWN         PIN_DM_RES_DWN
        #define VRX_DM_OD_LO           PIN_DM_OD_LO
        #define VRX_DM_OD_HI           PIN_DM_OD_HI
        #define VRX_DM_STRONG          PIN_DM_STRONG
        #define VRX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VRX_MASK               VRX__MASK
#define VRX_SHIFT              VRX__SHIFT
#define VRX_WIDTH              1u

/* Interrupt constants */
#if defined(VRX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VRX_SetInterruptMode() function.
     *  @{
     */
        #define VRX_INTR_NONE      (uint16)(0x0000u)
        #define VRX_INTR_RISING    (uint16)(0x0001u)
        #define VRX_INTR_FALLING   (uint16)(0x0002u)
        #define VRX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VRX_INTR_MASK      (0x01u) 
#endif /* (VRX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VRX_PS                     (* (reg8 *) VRX__PS)
/* Data Register */
#define VRX_DR                     (* (reg8 *) VRX__DR)
/* Port Number */
#define VRX_PRT_NUM                (* (reg8 *) VRX__PRT) 
/* Connect to Analog Globals */                                                  
#define VRX_AG                     (* (reg8 *) VRX__AG)                       
/* Analog MUX bux enable */
#define VRX_AMUX                   (* (reg8 *) VRX__AMUX) 
/* Bidirectional Enable */                                                        
#define VRX_BIE                    (* (reg8 *) VRX__BIE)
/* Bit-mask for Aliased Register Access */
#define VRX_BIT_MASK               (* (reg8 *) VRX__BIT_MASK)
/* Bypass Enable */
#define VRX_BYP                    (* (reg8 *) VRX__BYP)
/* Port wide control signals */                                                   
#define VRX_CTL                    (* (reg8 *) VRX__CTL)
/* Drive Modes */
#define VRX_DM0                    (* (reg8 *) VRX__DM0) 
#define VRX_DM1                    (* (reg8 *) VRX__DM1)
#define VRX_DM2                    (* (reg8 *) VRX__DM2) 
/* Input Buffer Disable Override */
#define VRX_INP_DIS                (* (reg8 *) VRX__INP_DIS)
/* LCD Common or Segment Drive */
#define VRX_LCD_COM_SEG            (* (reg8 *) VRX__LCD_COM_SEG)
/* Enable Segment LCD */
#define VRX_LCD_EN                 (* (reg8 *) VRX__LCD_EN)
/* Slew Rate Control */
#define VRX_SLW                    (* (reg8 *) VRX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VRX_PRTDSI__CAPS_SEL       (* (reg8 *) VRX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VRX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VRX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VRX_PRTDSI__OE_SEL0        (* (reg8 *) VRX__PRTDSI__OE_SEL0) 
#define VRX_PRTDSI__OE_SEL1        (* (reg8 *) VRX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VRX_PRTDSI__OUT_SEL0       (* (reg8 *) VRX__PRTDSI__OUT_SEL0) 
#define VRX_PRTDSI__OUT_SEL1       (* (reg8 *) VRX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VRX_PRTDSI__SYNC_OUT       (* (reg8 *) VRX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VRX__SIO_CFG)
    #define VRX_SIO_HYST_EN        (* (reg8 *) VRX__SIO_HYST_EN)
    #define VRX_SIO_REG_HIFREQ     (* (reg8 *) VRX__SIO_REG_HIFREQ)
    #define VRX_SIO_CFG            (* (reg8 *) VRX__SIO_CFG)
    #define VRX_SIO_DIFF           (* (reg8 *) VRX__SIO_DIFF)
#endif /* (VRX__SIO_CFG) */

/* Interrupt Registers */
#if defined(VRX__INTSTAT)
    #define VRX_INTSTAT            (* (reg8 *) VRX__INTSTAT)
    #define VRX_SNAP               (* (reg8 *) VRX__SNAP)
    
	#define VRX_0_INTTYPE_REG 		(* (reg8 *) VRX__0__INTTYPE)
#endif /* (VRX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VRX_H */


/* [] END OF FILE */
