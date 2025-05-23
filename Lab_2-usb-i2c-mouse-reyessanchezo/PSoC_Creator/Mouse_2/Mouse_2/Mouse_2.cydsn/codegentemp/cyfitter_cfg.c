
/*******************************************************************************
* File Name: cyfitter_cfg.c
* 
* PSoC Creator  4.4
*
* Description:
* This file contains device initialization code.
* Except for the user defined sections in CyClockStartupError(), this file should not be modified.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "cyfitter_cfg.h"
#include "cyapicallbacks.h"

#define CY_NEED_CYCLOCKSTARTUPERROR 1


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CYPACKED 
    #define CYPACKED_ATTR __attribute__ ((packed))
    #define CYALIGNED __attribute__ ((aligned))
    #define CY_CFG_UNUSED __attribute__ ((unused))
    #ifndef CY_CFG_SECTION
        #define CY_CFG_SECTION __attribute__ ((section(".psocinit")))
    #endif
    
    #if defined(__ARMCC_VERSION)
        #define CY_CFG_MEMORY_BARRIER() __memory_changed()
    #else
        #define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
    #endif
    
#elif defined(__ICCARM__)
    #include <intrinsics.h>

    #define CYPACKED __packed
    #define CYPACKED_ATTR 
    #define CYALIGNED _Pragma("data_alignment=4")
    #define CY_CFG_UNUSED _Pragma("diag_suppress=Pe177")
    #define CY_CFG_SECTION _Pragma("location=\".psocinit\"")
    
    #define CY_CFG_MEMORY_BARRIER() __DMB()
    
#else
    #error Unsupported toolchain
#endif

#ifndef CYCODE
    #define CYCODE
#endif
#ifndef CYDATA
    #define CYDATA
#endif
#ifndef CYFAR
    #define CYFAR
#endif
#ifndef CYXDATA
    #define CYXDATA
#endif


CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n);
CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n)
{
	(void)memset(s, 0, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}




/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0u
#define CYCLOCKSTART_XTAL_ERROR  1u
#define CYCLOCKSTART_32KHZ_ERROR 2u
#define CYCLOCKSTART_PLL_ERROR   3u
#define CYCLOCKSTART_FLL_ERROR   4u
#define CYCLOCKSTART_WCO_ERROR   5u


#ifdef CY_NEED_CYCLOCKSTARTUPERROR
/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc.), the system will end up here.  Unless reimplemented by
*  the customer, this function will stop in an infinite loop.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode);
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

#ifdef CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK
    CY_CFG_Clock_Startup_ErrorCallback();
#else
    /*  If not using CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK, place your clock startup code here. */
    /* `#START CyClockStartupError` */



    /* `#END` */

    while(1) {}
#endif /* CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK */
}
#endif

#define CY_CFG_BASE_ADDR_COUNT 38u
CYPACKED typedef struct
{
	uint8 offset;
	uint8 value;
} CYPACKED_ATTR cy_cfg_addrvalue_t;



/*******************************************************************************
* Function Name: cfg_write_bytes32
********************************************************************************
* Summary:
*  This function is used for setting up the chip configuration areas that
*  contain relatively sparse data.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[]);
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[])
{
	/* For 32-bit little-endian architectures */
	uint32 i, j = 0u;
	for (i = 0u; i < CY_CFG_BASE_ADDR_COUNT; i++)
	{
		uint32 baseAddr = addr_table[i];
		uint8 count = (uint8)baseAddr;
		baseAddr &= 0xFFFFFF00u;
		while (count != 0u)
		{
			CY_SET_REG8((void *)(baseAddr + data_table[j].offset), data_table[j].value);
			j++;
			count--;
		}
	}
}

/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*  Performs the initialization of all of the clocks in the device based on the
*  settings in the Clock tab of the DWR.  This includes enabling the requested
*  clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void ClockSetup(void);
static void ClockSetup(void)
{
	uint32 timeout;
	uint8 pllLock;


	/* Configure Digital Clocks based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x0019u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0 + 0x2u), 0x1Cu);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0), 0x0019u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0 + 0x2u), 0x19u);

	/* Configure ILO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_SLOWCLK_ILO_CR0), 0x06u);

	/* Configure IMO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_FASTCLK_IMO_CR), 0x52u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8((void CYFAR *)CYREG_FLSHID_CUST_TABLES_IMO_USB)));

	/* Configure PLL based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_P), 0x0710u);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_CFG0), 0x1251u);
	/* Wait up to 250us for the PLL to lock */
	pllLock = 0u;
	for (timeout = 250u / 10u; (timeout > 0u) && (pllLock != 0x03u); timeout--)
	{ 
		pllLock = 0x03u & ((uint8)((uint8)pllLock << 1) | ((CY_GET_XTND_REG8((void CYFAR *)CYREG_FASTCLK_PLL_SR) & 0x01u) >> 0));
		CyDelayCycles(10u * 48u); /* Delay 10us based on 48MHz clock */
	}
	/* If we ran out of time the PLL didn't lock so go to the error function */
	if (timeout == 0u)
	{
		CyClockStartupError(CYCLOCKSTART_PLL_ERROR);
	}

	/* Configure Bus/Master Clock based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x0100u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x07u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG2), 0x48u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00u);

	/* Configure USB Clock based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_UCFG), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_LD), 0x02u);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG2), ((CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG2) | 0x03u)));
}


/* Analog API Functions */


/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void AnalogSetDefault(void);
static void AnalogSetDefault(void)
{
	uint8 bg_xover_inl_trim = CY_GET_XTND_REG8((void CYFAR *)(CYREG_FLSHID_MFG_CFG_BG_XOVER_INL_TRIM + 1u));
	uint8 cr4 = CY_GET_XTND_REG8((void CYFAR *)(CYREG_RESET_CR4));
	uint8 cr5 = CY_GET_XTND_REG8((void CYFAR *)(CYREG_RESET_CR5));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_BG_DFT0), (bg_xover_inl_trim & 0x07u));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_BG_DFT1), ((bg_xover_inl_trim >> 4) & 0x0Fu));
	/* Disable PRES while setting up SAR voltage reference */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_RESET_CR4), (cr4 | 0x03u));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_RESET_CR5), (cr5 | 0x03u));
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PRT3_AG, 0x03u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR1_CSR1, 0x40u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR1_CSR3, 0x40u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR1_SW0, 0x30u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR1_SW3, 0x20u);
	CyDelayUs(10u); /* Allow vref to settle before re-enabling PRES */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_RESET_CR5), (cr5));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_RESET_CR4), (cr4));
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, 0x44u);
}


/*******************************************************************************
* Function Name: SetAnalogRoutingPumps
********************************************************************************
*
* Summary:
* Enables or disables the analog pumps feeding analog routing switches.
* Intended to be called at startup, based on the Vdda system configuration;
* may be called during operation when the user informs us that the Vdda voltage
* crossed the pump threshold.
*
* Parameters:
*  enabled - 1 to enable the pumps, 0 to disable the pumps
*
* Return:
*  void
*
*******************************************************************************/
void SetAnalogRoutingPumps(uint8 enabled)
{
	uint8 regValue = CY_GET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0);
	if (enabled != 0u)
	{
		regValue |= 0x22u;
	}
	else
	{
		regValue &= (uint8)~0x22u;
	}
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, regValue);
}


#define CY_AMUX_UNUSED CYREG_BOOST_SR


/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/

void cyfitter_cfg(void)
{
	/* IOPINS0_0 Address: CYREG_PRT0_DM0 Size (bytes): 8 */
	static const uint8 CYCODE BS_IOPINS0_0_VAL[] = {
		0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x04u, 0x00u};

	/* IOPINS0_7 Address: CYREG_PRT12_DR Size (bytes): 10 */
	static const uint8 CYCODE BS_IOPINS0_7_VAL[] = {
		0x80u, 0x00u, 0x40u, 0x80u, 0x80u, 0x00u, 0x80u, 0x00u, 0x00u, 0x00u};

	/* IOPINS0_8 Address: CYREG_PRT15_DR Size (bytes): 10 */
	static const uint8 CYCODE BS_IOPINS0_8_VAL[] = {
		0x40u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0xC0u, 0x00u};

	/* IOPINS0_1 Address: CYREG_PRT1_DM0 Size (bytes): 8 */
	static const uint8 CYCODE BS_IOPINS0_1_VAL[] = {
		0x00u, 0x0Bu, 0x0Bu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};

	/* IOPINS0_3 Address: CYREG_PRT3_DR Size (bytes): 10 */
	static const uint8 CYCODE BS_IOPINS0_3_VAL[] = {
		0x04u, 0x00u, 0x00u, 0x04u, 0x00u, 0x00u, 0x00u, 0x03u, 0x03u, 0x00u};

	/* PHUB_CFGMEM1 Address: CYREG_PHUB_CFGMEM1_CFG0 Size (bytes): 4 */
	static const uint8 CYCODE BS_PHUB_CFGMEM1_VAL[] = {
		0x00u, 0x01u, 0x00u, 0x00u};

#ifdef CYGlobalIntDisable
	/* Disable interrupts by default. Let user enable if/when they want. */
	CYGlobalIntDisable
#endif

	/* Enable/Disable Debug functionality based on settings from System DWR */
	CY_SET_XTND_REG8((void CYFAR *)CYREG_MLOGIC_DEBUG, (CY_GET_XTND_REG8((void CYFAR *)CYREG_MLOGIC_DEBUG) | 0x04u));

	{
		static const uint32 CYCODE cy_cfg_addr_table[] = {
			0x40004501u, /* Base address: 0x40004500 Count: 1 */
			0x40005204u, /* Base address: 0x40005200 Count: 4 */
			0x40005B01u, /* Base address: 0x40005B00 Count: 1 */
			0x40006403u, /* Base address: 0x40006400 Count: 3 */
			0x40006501u, /* Base address: 0x40006500 Count: 1 */
			0x4001000Eu, /* Base address: 0x40010000 Count: 14 */
			0x40010120u, /* Base address: 0x40010100 Count: 32 */
			0x40010212u, /* Base address: 0x40010200 Count: 18 */
			0x40010332u, /* Base address: 0x40010300 Count: 50 */
			0x40010447u, /* Base address: 0x40010400 Count: 71 */
			0x40010546u, /* Base address: 0x40010500 Count: 70 */
			0x4001062Du, /* Base address: 0x40010600 Count: 45 */
			0x40010742u, /* Base address: 0x40010700 Count: 66 */
			0x4001083Au, /* Base address: 0x40010800 Count: 58 */
			0x4001094Au, /* Base address: 0x40010900 Count: 74 */
			0x40010B09u, /* Base address: 0x40010B00 Count: 9 */
			0x40010D03u, /* Base address: 0x40010D00 Count: 3 */
			0x40010F02u, /* Base address: 0x40010F00 Count: 2 */
			0x40011416u, /* Base address: 0x40011400 Count: 22 */
			0x40011530u, /* Base address: 0x40011500 Count: 48 */
			0x40011631u, /* Base address: 0x40011600 Count: 49 */
			0x4001173Fu, /* Base address: 0x40011700 Count: 63 */
			0x40011845u, /* Base address: 0x40011800 Count: 69 */
			0x40011949u, /* Base address: 0x40011900 Count: 73 */
			0x40011B02u, /* Base address: 0x40011B00 Count: 2 */
			0x40014009u, /* Base address: 0x40014000 Count: 9 */
			0x40014106u, /* Base address: 0x40014100 Count: 6 */
			0x40014202u, /* Base address: 0x40014200 Count: 2 */
			0x40014306u, /* Base address: 0x40014300 Count: 6 */
			0x40014508u, /* Base address: 0x40014500 Count: 8 */
			0x40014601u, /* Base address: 0x40014600 Count: 1 */
			0x40014706u, /* Base address: 0x40014700 Count: 6 */
			0x40014805u, /* Base address: 0x40014800 Count: 5 */
			0x40014907u, /* Base address: 0x40014900 Count: 7 */
			0x40014C07u, /* Base address: 0x40014C00 Count: 7 */
			0x40014D08u, /* Base address: 0x40014D00 Count: 8 */
			0x4001500Au, /* Base address: 0x40015000 Count: 10 */
			0x40015102u, /* Base address: 0x40015100 Count: 2 */
		};

		static const cy_cfg_addrvalue_t CYCODE cy_cfg_data_table[] = {
			{0x7Eu, 0x02u},
			{0x18u, 0x01u},
			{0x1Cu, 0x04u},
			{0x61u, 0x80u},
			{0x7Cu, 0x40u},
			{0x2Fu, 0x84u},
			{0x82u, 0x01u},
			{0x83u, 0x0Fu},
			{0x87u, 0x38u},
			{0x87u, 0x72u},
			{0x56u, 0x08u},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Bu, 0x04u},
			{0x5Du, 0x90u},
			{0x5Fu, 0x01u},
			{0x84u, 0x01u},
			{0x98u, 0x01u},
			{0xB6u, 0x01u},
			{0xB8u, 0x80u},
			{0xBEu, 0x40u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDFu, 0x01u},
			{0x00u, 0x44u},
			{0x02u, 0x10u},
			{0x03u, 0x08u},
			{0x04u, 0xD8u},
			{0x08u, 0x20u},
			{0x09u, 0x8Au},
			{0x0Au, 0x04u},
			{0x0Du, 0x80u},
			{0x0Eu, 0x98u},
			{0x16u, 0x18u},
			{0x1Fu, 0x40u},
			{0x2Au, 0x08u},
			{0x2Eu, 0x10u},
			{0x2Fu, 0x08u},
			{0x31u, 0x82u},
			{0x33u, 0x08u},
			{0x34u, 0x20u},
			{0x36u, 0x40u},
			{0x38u, 0x94u},
			{0x3Cu, 0x16u},
			{0x3Eu, 0x40u},
			{0x5Bu, 0xA0u},
			{0x63u, 0x05u},
			{0x8Fu, 0x01u},
			{0xC0u, 0xE7u},
			{0xC2u, 0xFFu},
			{0xC4u, 0x60u},
			{0xCAu, 0x22u},
			{0xCCu, 0x3Bu},
			{0xCEu, 0xFEu},
			{0xD6u, 0x0Cu},
			{0xD8u, 0x0Cu},
			{0x56u, 0x02u},
			{0x57u, 0x3Du},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Bu, 0x0Cu},
			{0x5Fu, 0x01u},
			{0x80u, 0x02u},
			{0x9Eu, 0x01u},
			{0xB2u, 0x02u},
			{0xB4u, 0x01u},
			{0xBEu, 0x04u},
			{0xD4u, 0x01u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDBu, 0x04u},
			{0xDCu, 0x01u},
			{0xDDu, 0x10u},
			{0xDFu, 0x01u},
			{0x02u, 0x80u},
			{0x04u, 0x14u},
			{0x0Bu, 0x01u},
			{0x0Du, 0x80u},
			{0x0Eu, 0x94u},
			{0x16u, 0x80u},
			{0x19u, 0x24u},
			{0x2Au, 0x08u},
			{0x2Eu, 0x06u},
			{0x2Fu, 0x08u},
			{0x31u, 0x02u},
			{0x33u, 0x08u},
			{0x36u, 0x40u},
			{0x38u, 0x94u},
			{0x3Au, 0x02u},
			{0x3Cu, 0x14u},
			{0x3Eu, 0x40u},
			{0x58u, 0x12u},
			{0x59u, 0x04u},
			{0x5Bu, 0x80u},
			{0x5Eu, 0x20u},
			{0x60u, 0x02u},
			{0x62u, 0x80u},
			{0x67u, 0x80u},
			{0x6Du, 0x52u},
			{0x6Eu, 0x02u},
			{0x6Fu, 0x10u},
			{0x77u, 0x06u},
			{0x7Fu, 0x02u},
			{0x84u, 0x04u},
			{0x93u, 0x85u},
			{0x94u, 0x9Cu},
			{0x96u, 0x44u},
			{0x9Eu, 0x08u},
			{0xA4u, 0x01u},
			{0xA5u, 0x8Au},
			{0xA6u, 0x40u},
			{0xA7u, 0x08u},
			{0xAFu, 0x20u},
			{0xB3u, 0x80u},
			{0xB6u, 0x04u},
			{0xC0u, 0x68u},
			{0xC2u, 0xF1u},
			{0xC4u, 0x10u},
			{0xCAu, 0xE2u},
			{0xCCu, 0x13u},
			{0xCEu, 0x7Fu},
			{0xD6u, 0x2Fu},
			{0xD8u, 0x80u},
			{0xDEu, 0x10u},
			{0x02u, 0x01u},
			{0x03u, 0x03u},
			{0x15u, 0x01u},
			{0x22u, 0x02u},
			{0x2Eu, 0x04u},
			{0x30u, 0x04u},
			{0x32u, 0x02u},
			{0x33u, 0x02u},
			{0x34u, 0x01u},
			{0x35u, 0x01u},
			{0x40u, 0x62u},
			{0x41u, 0x04u},
			{0x45u, 0xEBu},
			{0x46u, 0xC0u},
			{0x48u, 0x0Bu},
			{0x49u, 0xFFu},
			{0x4Au, 0xFFu},
			{0x4Bu, 0xFFu},
			{0x4Eu, 0xF0u},
			{0x4Fu, 0x44u},
			{0x50u, 0x0Cu},
			{0x58u, 0x04u},
			{0x59u, 0x0Cu},
			{0x5Au, 0x04u},
			{0x5Du, 0x01u},
			{0x5Fu, 0x01u},
			{0x66u, 0xC0u},
			{0x6Au, 0x40u},
			{0x6Bu, 0x02u},
			{0x80u, 0x08u},
			{0x81u, 0x04u},
			{0x85u, 0x10u},
			{0x86u, 0x48u},
			{0x87u, 0x20u},
			{0x89u, 0x20u},
			{0x8Au, 0x81u},
			{0x8Bu, 0x10u},
			{0x8Du, 0x80u},
			{0x8Fu, 0x40u},
			{0x90u, 0x01u},
			{0x91u, 0x02u},
			{0x94u, 0x04u},
			{0x95u, 0x01u},
			{0x98u, 0x02u},
			{0x99u, 0x08u},
			{0x9Eu, 0x04u},
			{0x9Fu, 0x01u},
			{0xA2u, 0x02u},
			{0xA3u, 0x08u},
			{0xA6u, 0x10u},
			{0xA7u, 0x02u},
			{0xAAu, 0x20u},
			{0xABu, 0x04u},
			{0xADu, 0x40u},
			{0xAFu, 0x80u},
			{0xB0u, 0x80u},
			{0xB2u, 0x1Fu},
			{0xB4u, 0x20u},
			{0xB5u, 0xFFu},
			{0xB6u, 0x40u},
			{0xB8u, 0x08u},
			{0xBBu, 0x80u},
			{0xBEu, 0x04u},
			{0xBFu, 0x10u},
			{0xD2u, 0x03u},
			{0xD3u, 0x02u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDBu, 0x04u},
			{0xDCu, 0x10u},
			{0xDFu, 0x01u},
			{0x02u, 0x40u},
			{0x04u, 0x01u},
			{0x07u, 0x14u},
			{0x0Eu, 0x96u},
			{0x11u, 0x42u},
			{0x15u, 0x10u},
			{0x16u, 0x40u},
			{0x17u, 0x0Au},
			{0x18u, 0xA0u},
			{0x19u, 0x02u},
			{0x1Au, 0x54u},
			{0x1Bu, 0x1Cu},
			{0x1Cu, 0x97u},
			{0x1Du, 0x8Eu},
			{0x1Eu, 0x80u},
			{0x1Fu, 0x44u},
			{0x20u, 0x08u},
			{0x21u, 0x20u},
			{0x22u, 0x04u},
			{0x27u, 0x09u},
			{0x2Eu, 0xCEu},
			{0x2Fu, 0x48u},
			{0x32u, 0x04u},
			{0x36u, 0x40u},
			{0x37u, 0x56u},
			{0x39u, 0x02u},
			{0x3Cu, 0x04u},
			{0x3Du, 0x52u},
			{0x40u, 0x80u},
			{0x41u, 0x10u},
			{0x48u, 0x08u},
			{0x49u, 0x08u},
			{0x4Au, 0x80u},
			{0x52u, 0x20u},
			{0x6Cu, 0x04u},
			{0x6Eu, 0x20u},
			{0x6Fu, 0x02u},
			{0x7Bu, 0x02u},
			{0x80u, 0x04u},
			{0x82u, 0x20u},
			{0x88u, 0x01u},
			{0x8Cu, 0x10u},
			{0x8Du, 0x02u},
			{0x91u, 0x50u},
			{0x93u, 0x05u},
			{0x94u, 0x9Cu},
			{0x96u, 0x54u},
			{0x99u, 0x20u},
			{0x9Bu, 0x16u},
			{0x9Eu, 0x8Au},
			{0x9Fu, 0x80u},
			{0xA1u, 0x01u},
			{0xA2u, 0x01u},
			{0xA4u, 0x05u},
			{0xA5u, 0x8Au},
			{0xA6u, 0xF0u},
			{0xA7u, 0x0Au},
			{0xACu, 0x10u},
			{0xAEu, 0x20u},
			{0xC0u, 0x78u},
			{0xC2u, 0xF0u},
			{0xC4u, 0x79u},
			{0xCAu, 0xF0u},
			{0xCCu, 0xF2u},
			{0xCEu, 0xF1u},
			{0xD0u, 0x05u},
			{0xD2u, 0x04u},
			{0xDEu, 0x08u},
			{0xE0u, 0x04u},
			{0xE4u, 0x01u},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Fu, 0x01u},
			{0x87u, 0x02u},
			{0x8Bu, 0x04u},
			{0x8Fu, 0x01u},
			{0x97u, 0x04u},
			{0x99u, 0x01u},
			{0x9Fu, 0x08u},
			{0xA7u, 0x08u},
			{0xB1u, 0x03u},
			{0xB5u, 0x08u},
			{0xB7u, 0x04u},
			{0xBFu, 0x50u},
			{0xC0u, 0x23u},
			{0xC1u, 0x04u},
			{0xC2u, 0x06u},
			{0xC4u, 0x05u},
			{0xC6u, 0xC0u},
			{0xC7u, 0x0Eu},
			{0xC8u, 0x18u},
			{0xC9u, 0xFFu},
			{0xCAu, 0xFFu},
			{0xCBu, 0xFFu},
			{0xCCu, 0x62u},
			{0xCDu, 0xA0u},
			{0xCEu, 0xF0u},
			{0xCFu, 0x41u},
			{0xD0u, 0x0Cu},
			{0xD4u, 0x18u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDAu, 0x04u},
			{0xDBu, 0x04u},
			{0xDCu, 0x90u},
			{0xDDu, 0x11u},
			{0xDFu, 0x01u},
			{0xE6u, 0x40u},
			{0xE7u, 0x02u},
			{0xE9u, 0x10u},
			{0xEAu, 0x30u},
			{0xEBu, 0x10u},
			{0xEDu, 0x10u},
			{0xEEu, 0x10u},
			{0xEFu, 0x12u},
			{0x00u, 0x84u},
			{0x01u, 0x02u},
			{0x03u, 0x08u},
			{0x04u, 0x14u},
			{0x05u, 0x02u},
			{0x06u, 0x82u},
			{0x09u, 0x08u},
			{0x0Au, 0x04u},
			{0x0Bu, 0x80u},
			{0x0Fu, 0x28u},
			{0x17u, 0x40u},
			{0x21u, 0x01u},
			{0x22u, 0xA0u},
			{0x23u, 0x40u},
			{0x2Au, 0x04u},
			{0x2Eu, 0x84u},
			{0x2Fu, 0x48u},
			{0x31u, 0x20u},
			{0x32u, 0x4Cu},
			{0x35u, 0x04u},
			{0x38u, 0x20u},
			{0x3Bu, 0x44u},
			{0x3Cu, 0x84u},
			{0x41u, 0x14u},
			{0x43u, 0x01u},
			{0x4Au, 0x0Au},
			{0x50u, 0x10u},
			{0x52u, 0x04u},
			{0x59u, 0x01u},
			{0x62u, 0xA0u},
			{0x80u, 0x80u},
			{0x83u, 0x80u},
			{0x84u, 0x08u},
			{0x89u, 0x02u},
			{0x8Fu, 0x80u},
			{0x90u, 0x14u},
			{0x92u, 0x04u},
			{0x93u, 0x8Du},
			{0x95u, 0x02u},
			{0x99u, 0x26u},
			{0x9Au, 0x02u},
			{0x9Bu, 0x41u},
			{0x9Cu, 0x80u},
			{0x9Fu, 0x80u},
			{0xA0u, 0x40u},
			{0xA1u, 0x28u},
			{0xA3u, 0x1Eu},
			{0xA4u, 0x08u},
			{0xADu, 0x18u},
			{0xB4u, 0x10u},
			{0xB5u, 0x08u},
			{0xB6u, 0x40u},
			{0xC0u, 0xFFu},
			{0xC2u, 0x6Eu},
			{0xC4u, 0x80u},
			{0xCAu, 0xF2u},
			{0xCCu, 0x4Eu},
			{0xCEu, 0x5Eu},
			{0xD0u, 0x07u},
			{0xD2u, 0x0Cu},
			{0xD6u, 0x01u},
			{0xD8u, 0x0Cu},
			{0xE2u, 0x0Au},
			{0xE6u, 0x07u},
			{0xEAu, 0x02u},
			{0xECu, 0x08u},
			{0x01u, 0x14u},
			{0x05u, 0x10u},
			{0x06u, 0x04u},
			{0x07u, 0x0Cu},
			{0x0Au, 0x0Cu},
			{0x0Cu, 0x20u},
			{0x0Du, 0x09u},
			{0x0Fu, 0x10u},
			{0x11u, 0x1Cu},
			{0x12u, 0x18u},
			{0x13u, 0x02u},
			{0x16u, 0x14u},
			{0x17u, 0x40u},
			{0x18u, 0x01u},
			{0x1Au, 0x02u},
			{0x1Bu, 0x20u},
			{0x1Cu, 0x03u},
			{0x1Fu, 0x03u},
			{0x22u, 0x08u},
			{0x24u, 0x02u},
			{0x26u, 0x01u},
			{0x27u, 0x40u},
			{0x28u, 0x03u},
			{0x29u, 0x0Cu},
			{0x2Bu, 0x11u},
			{0x2Cu, 0x18u},
			{0x2Du, 0x10u},
			{0x2Eu, 0x04u},
			{0x31u, 0x60u},
			{0x32u, 0x1Cu},
			{0x34u, 0x03u},
			{0x36u, 0x20u},
			{0x37u, 0x1Fu},
			{0x3Au, 0x08u},
			{0x3Eu, 0x40u},
			{0x3Fu, 0x01u},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Cu, 0x11u},
			{0x5Fu, 0x01u},
			{0x81u, 0x01u},
			{0x86u, 0x01u},
			{0x88u, 0x01u},
			{0x89u, 0x01u},
			{0x92u, 0x01u},
			{0x94u, 0x01u},
			{0x95u, 0x01u},
			{0x9Du, 0x01u},
			{0xA6u, 0x01u},
			{0xA7u, 0x01u},
			{0xA9u, 0x01u},
			{0xADu, 0x01u},
			{0xB0u, 0x01u},
			{0xB3u, 0x01u},
			{0xBEu, 0x01u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDFu, 0x01u},
			{0x00u, 0x12u},
			{0x02u, 0x20u},
			{0x03u, 0x02u},
			{0x04u, 0x10u},
			{0x06u, 0x10u},
			{0x07u, 0x01u},
			{0x08u, 0x40u},
			{0x09u, 0x1Cu},
			{0x0Au, 0x80u},
			{0x0Du, 0x48u},
			{0x0Eu, 0x04u},
			{0x0Fu, 0x40u},
			{0x10u, 0x22u},
			{0x11u, 0x01u},
			{0x12u, 0x18u},
			{0x14u, 0x04u},
			{0x16u, 0x80u},
			{0x17u, 0x44u},
			{0x18u, 0x80u},
			{0x1Cu, 0x10u},
			{0x1Eu, 0x05u},
			{0x1Fu, 0x28u},
			{0x23u, 0x10u},
			{0x25u, 0x02u},
			{0x26u, 0x40u},
			{0x27u, 0x01u},
			{0x28u, 0x02u},
			{0x2Au, 0x24u},
			{0x2Bu, 0x02u},
			{0x2Eu, 0x80u},
			{0x2Fu, 0x29u},
			{0x30u, 0x40u},
			{0x32u, 0x08u},
			{0x36u, 0x41u},
			{0x37u, 0x24u},
			{0x38u, 0x21u},
			{0x39u, 0x01u},
			{0x3Cu, 0x80u},
			{0x3Du, 0x08u},
			{0x3Fu, 0x42u},
			{0x40u, 0x20u},
			{0x42u, 0x20u},
			{0x80u, 0x10u},
			{0x83u, 0x20u},
			{0x85u, 0x08u},
			{0x87u, 0x10u},
			{0x88u, 0x01u},
			{0x8Au, 0x01u},
			{0x8Cu, 0x40u},
			{0x90u, 0x21u},
			{0x92u, 0x80u},
			{0x98u, 0x40u},
			{0x9Au, 0x24u},
			{0x9Bu, 0x06u},
			{0xA0u, 0x02u},
			{0xA1u, 0x10u},
			{0xA2u, 0x08u},
			{0xA3u, 0x11u},
			{0xA4u, 0x20u},
			{0xACu, 0x20u},
			{0xAFu, 0x01u},
			{0xB5u, 0x10u},
			{0xB6u, 0x24u},
			{0xB7u, 0x02u},
			{0xC0u, 0xEFu},
			{0xC2u, 0xFFu},
			{0xC4u, 0xFFu},
			{0xCAu, 0x7Eu},
			{0xCCu, 0xFAu},
			{0xCEu, 0xD5u},
			{0xE0u, 0x80u},
			{0xE6u, 0x12u},
			{0xE8u, 0x10u},
			{0xECu, 0x50u},
			{0x80u, 0x12u},
			{0x82u, 0x40u},
			{0x83u, 0x10u},
			{0x88u, 0x40u},
			{0x8Cu, 0x01u},
			{0x8Eu, 0x08u},
			{0x9Bu, 0x04u},
			{0xE0u, 0x80u},
			{0xE4u, 0x50u},
			{0x9Bu, 0x04u},
			{0xEAu, 0x40u},
			{0xEEu, 0x20u},
			{0x8Fu, 0x04u},
			{0xE4u, 0x10u},
			{0x01u, 0x01u},
			{0x02u, 0x01u},
			{0x04u, 0x01u},
			{0x05u, 0x01u},
			{0x0Au, 0x01u},
			{0x0Cu, 0x01u},
			{0x11u, 0x01u},
			{0x18u, 0x01u},
			{0x19u, 0x01u},
			{0x28u, 0x01u},
			{0x2Cu, 0x01u},
			{0x31u, 0x01u},
			{0x36u, 0x01u},
			{0x3Fu, 0x01u},
			{0x54u, 0x01u},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Bu, 0x0Cu},
			{0x5Fu, 0x01u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDFu, 0x01u},
			{0x00u, 0x14u},
			{0x01u, 0x0Bu},
			{0x02u, 0x51u},
			{0x04u, 0x14u},
			{0x07u, 0xC0u},
			{0x08u, 0x10u},
			{0x0Cu, 0x10u},
			{0x0Fu, 0x28u},
			{0x12u, 0x04u},
			{0x13u, 0x80u},
			{0x16u, 0x42u},
			{0x19u, 0x40u},
			{0x22u, 0x01u},
			{0x2Au, 0x57u},
			{0x2Bu, 0x10u},
			{0x2Eu, 0x02u},
			{0x2Fu, 0x04u},
			{0x33u, 0x69u},
			{0x35u, 0x08u},
			{0x37u, 0x40u},
			{0x38u, 0x12u},
			{0x3Bu, 0x04u},
			{0x3Du, 0x01u},
			{0x3Fu, 0x28u},
			{0x5Au, 0x40u},
			{0x7Bu, 0x02u},
			{0x85u, 0x40u},
			{0x90u, 0x16u},
			{0x92u, 0x40u},
			{0x93u, 0x0Cu},
			{0x96u, 0x02u},
			{0x99u, 0x02u},
			{0x9Au, 0x02u},
			{0x9Bu, 0x41u},
			{0xA3u, 0x3Eu},
			{0xACu, 0x08u},
			{0xADu, 0x04u},
			{0xAFu, 0x41u},
			{0xC0u, 0x7Fu},
			{0xC2u, 0x62u},
			{0xC4u, 0x93u},
			{0xCAu, 0xAFu},
			{0xCCu, 0x5Fu},
			{0xCEu, 0xE7u},
			{0xD6u, 0x08u},
			{0xDEu, 0x08u},
			{0xE8u, 0x10u},
			{0xEAu, 0x08u},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Fu, 0x01u},
			{0x80u, 0x40u},
			{0x81u, 0x02u},
			{0x84u, 0x1Cu},
			{0x85u, 0x33u},
			{0x86u, 0xE2u},
			{0x87u, 0x0Cu},
			{0x89u, 0x0Cu},
			{0x8Au, 0x04u},
			{0x8Cu, 0x1Cu},
			{0x8Eu, 0xE1u},
			{0x8Fu, 0x13u},
			{0x91u, 0x3Fu},
			{0x92u, 0xE3u},
			{0x94u, 0x18u},
			{0x95u, 0x03u},
			{0x98u, 0xE7u},
			{0x99u, 0x04u},
			{0x9Au, 0x18u},
			{0x9Cu, 0x84u},
			{0x9Du, 0x08u},
			{0xA0u, 0x10u},
			{0xA1u, 0x01u},
			{0xA4u, 0x08u},
			{0xA8u, 0xFFu},
			{0xA9u, 0x1Cu},
			{0xABu, 0x23u},
			{0xACu, 0xC0u},
			{0xADu, 0x0Fu},
			{0xAFu, 0x30u},
			{0xB0u, 0xC0u},
			{0xB3u, 0x1Cu},
			{0xB4u, 0x1Fu},
			{0xB5u, 0x0Fu},
			{0xB6u, 0x38u},
			{0xB7u, 0x20u},
			{0xB9u, 0x80u},
			{0xBAu, 0xA0u},
			{0xBBu, 0x20u},
			{0xD6u, 0x02u},
			{0xD7u, 0x13u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDBu, 0x04u},
			{0xDCu, 0x11u},
			{0xDDu, 0x10u},
			{0xDFu, 0x01u},
			{0x01u, 0xA0u},
			{0x03u, 0xA0u},
			{0x04u, 0x14u},
			{0x05u, 0x02u},
			{0x06u, 0x01u},
			{0x0Bu, 0x95u},
			{0x0Fu, 0x28u},
			{0x10u, 0xA9u},
			{0x16u, 0x02u},
			{0x18u, 0x02u},
			{0x19u, 0x91u},
			{0x1Bu, 0x20u},
			{0x21u, 0x10u},
			{0x22u, 0x44u},
			{0x23u, 0x04u},
			{0x29u, 0x90u},
			{0x2Bu, 0x80u},
			{0x2Du, 0x02u},
			{0x2Fu, 0x08u},
			{0x30u, 0xA0u},
			{0x31u, 0x08u},
			{0x33u, 0x01u},
			{0x35u, 0x04u},
			{0x37u, 0x40u},
			{0x3Bu, 0x95u},
			{0x3Cu, 0x04u},
			{0x3Eu, 0x02u},
			{0x3Fu, 0x20u},
			{0x46u, 0x01u},
			{0x47u, 0x40u},
			{0x5Au, 0x02u},
			{0x69u, 0x40u},
			{0x6Bu, 0x28u},
			{0x70u, 0xA0u},
			{0x73u, 0x10u},
			{0x84u, 0x01u},
			{0x85u, 0x08u},
			{0x8Bu, 0x08u},
			{0x8Du, 0x40u},
			{0x8Fu, 0x30u},
			{0x90u, 0x14u},
			{0x92u, 0x40u},
			{0x93u, 0x09u},
			{0x95u, 0x28u},
			{0x96u, 0x88u},
			{0x99u, 0x26u},
			{0x9Au, 0x02u},
			{0x9Bu, 0x41u},
			{0x9Du, 0x01u},
			{0xA3u, 0x9Eu},
			{0xA9u, 0x20u},
			{0xAAu, 0x40u},
			{0xAEu, 0x02u},
			{0xC0u, 0xFFu},
			{0xC2u, 0x6Fu},
			{0xC4u, 0x8Fu},
			{0xCAu, 0xADu},
			{0xCCu, 0x5Fu},
			{0xCEu, 0xEFu},
			{0xD6u, 0x01u},
			{0xE2u, 0x02u},
			{0xEAu, 0x02u},
			{0xEEu, 0x02u},
			{0x00u, 0x10u},
			{0x04u, 0x0Au},
			{0x05u, 0x20u},
			{0x06u, 0x24u},
			{0x07u, 0x10u},
			{0x08u, 0x23u},
			{0x09u, 0x01u},
			{0x0Au, 0x04u},
			{0x0Bu, 0x0Eu},
			{0x0Fu, 0x0Cu},
			{0x11u, 0x10u},
			{0x13u, 0x60u},
			{0x14u, 0x03u},
			{0x15u, 0x40u},
			{0x16u, 0x04u},
			{0x17u, 0x10u},
			{0x18u, 0x10u},
			{0x19u, 0x0Cu},
			{0x1Bu, 0x03u},
			{0x1Cu, 0x10u},
			{0x1Du, 0x70u},
			{0x21u, 0x70u},
			{0x22u, 0x08u},
			{0x24u, 0x40u},
			{0x26u, 0x05u},
			{0x27u, 0x03u},
			{0x28u, 0x23u},
			{0x29u, 0x01u},
			{0x2Au, 0x0Cu},
			{0x2Bu, 0x06u},
			{0x2Fu, 0x08u},
			{0x30u, 0x60u},
			{0x32u, 0x0Fu},
			{0x33u, 0x70u},
			{0x34u, 0x10u},
			{0x35u, 0x0Fu},
			{0x38u, 0x02u},
			{0x3Au, 0x08u},
			{0x3Bu, 0x20u},
			{0x58u, 0x04u},
			{0x59u, 0x04u},
			{0x5Cu, 0x11u},
			{0x5Fu, 0x01u},
			{0x84u, 0x02u},
			{0x88u, 0x03u},
			{0x94u, 0x03u},
			{0xA6u, 0x01u},
			{0xB4u, 0x03u},
			{0xB8u, 0x20u},
			{0xBEu, 0x10u},
			{0xC0u, 0x02u},
			{0xC7u, 0x40u},
			{0xC9u, 0xFFu},
			{0xCAu, 0x07u},
			{0xCBu, 0xFFu},
			{0xCCu, 0x40u},
			{0xCDu, 0x20u},
			{0xCEu, 0xF0u},
			{0xCFu, 0x05u},
			{0xD0u, 0x08u},
			{0xD8u, 0x04u},
			{0xD9u, 0x04u},
			{0xDAu, 0x04u},
			{0xDDu, 0x01u},
			{0xDFu, 0x01u},
			{0xE0u, 0x40u},
			{0xE1u, 0xA8u},
			{0xE2u, 0x40u},
			{0xE3u, 0x20u},
			{0x00u, 0x11u},
			{0x02u, 0x20u},
			{0x04u, 0x18u},
			{0x06u, 0x40u},
			{0x08u, 0x6Au},
			{0x09u, 0x08u},
			{0x0Du, 0x40u},
			{0x0Eu, 0x08u},
			{0x0Fu, 0x20u},
			{0x10u, 0x22u},
			{0x12u, 0x08u},
			{0x13u, 0x02u},
			{0x14u, 0x08u},
			{0x16u, 0x90u},
			{0x18u, 0x04u},
			{0x1Cu, 0x80u},
			{0x1Du, 0x28u},
			{0x1Fu, 0x08u},
			{0x24u, 0x08u},
			{0x26u, 0x20u},
			{0x27u, 0x20u},
			{0x28u, 0x40u},
			{0x29u, 0x04u},
			{0x2Au, 0x20u},
			{0x2Cu, 0xA0u},
			{0x2Fu, 0x09u},
			{0x30u, 0x02u},
			{0x32u, 0x08u},
			{0x36u, 0x20u},
			{0x37u, 0x85u},
			{0x38u, 0x01u},
			{0x3Au, 0x04u},
			{0x3Cu, 0x90u},
			{0x3Eu, 0x84u},
			{0x40u, 0x04u},
			{0x50u, 0x20u},
			{0x52u, 0x10u},
			{0x53u, 0x01u},
			{0x87u, 0x21u},
			{0x88u, 0x84u},
			{0x8Au, 0x40u},
			{0x8Cu, 0x02u},
			{0x8Du, 0x44u},
			{0x8Eu, 0x04u},
			{0x8Fu, 0x80u},
			{0x90u, 0x11u},
			{0x92u, 0x04u},
			{0x95u, 0x80u},
			{0x97u, 0x02u},
			{0x98u, 0x60u},
			{0x9Au, 0x24u},
			{0x9Bu, 0x06u},
			{0x9Cu, 0x06u},
			{0x9Fu, 0x20u},
			{0xA0u, 0x02u},
			{0xA2u, 0x08u},
			{0xA3u, 0x10u},
			{0xA4u, 0x60u},
			{0xA5u, 0x08u},
			{0xA6u, 0x20u},
			{0xADu, 0x02u},
			{0xB6u, 0x21u},
			{0xB7u, 0x40u},
			{0xC0u, 0x7Eu},
			{0xC2u, 0xEFu},
			{0xC4u, 0x7Fu},
			{0xCAu, 0xF7u},
			{0xCCu, 0xF3u},
			{0xCEu, 0x73u},
			{0xD0u, 0x04u},
			{0xE0u, 0x50u},
			{0xE4u, 0x90u},
			{0xEEu, 0x02u},
			{0xADu, 0x20u},
			{0xE8u, 0x10u},
			{0x13u, 0x04u},
			{0x16u, 0x80u},
			{0x32u, 0x20u},
			{0x36u, 0x40u},
			{0x39u, 0x04u},
			{0x3Eu, 0x80u},
			{0xC4u, 0x30u},
			{0xCCu, 0x30u},
			{0xCEu, 0x60u},
			{0x86u, 0x20u},
			{0x95u, 0x04u},
			{0xA6u, 0x60u},
			{0xAFu, 0x04u},
			{0xE6u, 0x40u},
			{0xE8u, 0x40u},
			{0x95u, 0x04u},
			{0xA6u, 0x40u},
			{0x85u, 0x04u},
			{0x86u, 0x40u},
			{0x95u, 0x04u},
			{0xA6u, 0x40u},
			{0xE2u, 0x10u},
			{0xE6u, 0x40u},
			{0x20u, 0x40u},
			{0x94u, 0x40u},
			{0xA4u, 0x20u},
			{0xB0u, 0x20u},
			{0xB4u, 0x40u},
			{0xC8u, 0x02u},
			{0xEAu, 0x02u},
			{0xEEu, 0x04u},
			{0xA4u, 0x20u},
			{0x0Bu, 0x40u},
			{0x84u, 0x04u},
			{0x8Bu, 0x10u},
			{0xA4u, 0x20u},
			{0xC2u, 0x08u},
			{0xE4u, 0x01u},
			{0x24u, 0x08u},
			{0x9Au, 0x40u},
			{0xAEu, 0x40u},
			{0xC8u, 0x20u},
			{0xEEu, 0x40u},
			{0x52u, 0x80u},
			{0x56u, 0x40u},
			{0x86u, 0x80u},
			{0x9Au, 0x40u},
			{0xB4u, 0x04u},
			{0xD4u, 0x60u},
			{0xE6u, 0x10u},
			{0x1Cu, 0x08u},
			{0x34u, 0x02u},
			{0x93u, 0x10u},
			{0xA4u, 0x24u},
			{0xAFu, 0x40u},
			{0xC6u, 0x01u},
			{0xCCu, 0x01u},
			{0x10u, 0x20u},
			{0x73u, 0x10u},
			{0x93u, 0x10u},
			{0xA4u, 0x20u},
			{0xB4u, 0x02u},
			{0xC4u, 0x08u},
			{0xDCu, 0x01u},
			{0xE8u, 0x08u},
			{0x00u, 0x03u},
			{0x01u, 0x01u},
			{0x08u, 0x03u},
			{0x09u, 0x01u},
			{0x0Au, 0x03u},
			{0x0Bu, 0x01u},
			{0x0Cu, 0x03u},
			{0x10u, 0x03u},
			{0x1Au, 0x03u},
			{0x1Cu, 0x03u},
			{0x00u, 0x0Bu},
			{0x10u, 0x0Au},
		};



		CYPACKED typedef struct {
			void CYFAR *address;
			uint16 size;
		} CYPACKED_ATTR cfg_memset_t;

		static const cfg_memset_t CYCODE cfg_memset_list[] = {
			/* address, size */
			{(void CYFAR *)(CYREG_PRT2_DR), 16u},
			{(void CYFAR *)(CYREG_PRT4_DR), 48u},
			{(void CYFAR *)(CYDEV_UCFG_B0_P0_U0_BASE), 4096u},
			{(void CYFAR *)(CYDEV_UCFG_B1_P2_U0_BASE), 2048u},
			{(void CYFAR *)(CYDEV_UCFG_DSI0_BASE), 2560u},
			{(void CYFAR *)(CYDEV_UCFG_DSI12_BASE), 512u},
			{(void CYFAR *)(CYREG_BCTL0_MDCLK_EN), 32u},
		};

		uint8 CYDATA i;

		/* Zero out critical memory blocks before beginning configuration */
		for (i = 0u; i < (sizeof(cfg_memset_list)/sizeof(cfg_memset_list[0])); i++)
		{
			const cfg_memset_t CYCODE * CYDATA ms = &cfg_memset_list[i];
			CYMEMZERO(ms->address, (size_t)(uint32)(ms->size));
		}

		cfg_write_bytes32(cy_cfg_addr_table, cy_cfg_data_table);

		/* Perform normal device configuration. Order is not critical for these items. */
		CYMEMZERO((void CYFAR *)(CYREG_PHUB_CFGMEM0_CFG0), 4u);
		CYCONFIGCPYCODE((void CYFAR *)(CYREG_PHUB_CFGMEM1_CFG0), (const void CYCODE *)(BS_PHUB_CFGMEM1_VAL), 4u);

		/* Enable digital routing */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL) | 0x02u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0) | 0x40u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2) | 0x10u);
	}


	/* Perform second pass device configuration. These items must be configured in specific order after the regular configuration is done. */
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT0_DM0), (const void CYCODE *)(BS_IOPINS0_0_VAL), 8u);
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT12_DR), (const void CYCODE *)(BS_IOPINS0_7_VAL), 10u);
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT15_DR), (const void CYCODE *)(BS_IOPINS0_8_VAL), 10u);
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT1_DM0), (const void CYCODE *)(BS_IOPINS0_1_VAL), 8u);
	CYCONFIGCPYCODE((void CYFAR *)(CYREG_PRT3_DR), (const void CYCODE *)(BS_IOPINS0_3_VAL), 10u);
	/* Switch Boost to the precision bandgap reference from its internal reference */
	CY_SET_REG8((void CYXDATA *)CYREG_BOOST_CR2, (CY_GET_REG8((void CYXDATA *)CYREG_BOOST_CR2) | 0x08u));

	/* Set Flash Cycles based on max possible frequency in case a glitch occurs during ClockSetup(). */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0x61u : 0x60u));
	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();
	/* Set Flash Cycles based on newly configured 48.00MHz Bus Clock. */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0xC1u : 0xC0u));

	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (const void CYFAR *)CYDEV_PM_ACT_BASE, 14u);
}
