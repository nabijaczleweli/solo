//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library includes]
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_assert.h"
#include "em_cryotimer.h"
#include "em_crypto.h"
#include "em_gpio.h"
#include "em_ldma.h"
#include "em_usart.h"
// [Library includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	CHIP_Init();

	EMU_enter_DefaultMode_from_RESET();
	CMU_enter_DefaultMode_from_RESET();
	USART0_enter_DefaultMode_from_RESET();
	USART1_enter_DefaultMode_from_RESET();
	LDMA_enter_DefaultMode_from_RESET();
	CRYOTIMER_enter_DefaultMode_from_RESET();
	PORTIO_enter_DefaultMode_from_RESET();
	// [Config Calls]$

}

//================================================================================
// EMU_enter_DefaultMode_from_RESET
//================================================================================
extern void EMU_enter_DefaultMode_from_RESET(void) {

	// $[EMU Initialization]
	/* Initialize DCDC regulator */
	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;

	dcdcInit.powerConfig = emuPowerConfig_DcdcToDvdd;
	dcdcInit.dcdcMode = emuDcdcMode_LowNoise;
	dcdcInit.mVout = 1800;
	dcdcInit.em01LoadCurrent_mA = 15;
	dcdcInit.em234LoadCurrent_uA = 10;
	dcdcInit.maxCurrent_mA = 200;
	dcdcInit.anaPeripheralPower = emuDcdcAnaPeripheralPower_DCDC;
	dcdcInit.reverseCurrentControl = 160;

	EMU_DCDCInit(&dcdcInit);
	/* Initialize EM2/EM3 mode */
	EMU_EM23Init_TypeDef em23Init = EMU_EM23INIT_DEFAULT;

	em23Init.em23VregFullEn = 0;

	EMU_EM23Init(&em23Init);
	/* Initialize EM4H/S mode */
	EMU_EM4Init_TypeDef em4Init = EMU_EM4INIT_DEFAULT;

	em4Init.retainLfrco = 0;
	em4Init.retainLfxo = 0;
	em4Init.retainUlfrco = 0;
	em4Init.em4State = emuEM4Shutoff;
	em4Init.pinRetentionMode = emuPinRetentionDisable;

	EMU_EM4Init(&em4Init);
	// [EMU Initialization]$

}

//================================================================================
// LFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void LFXO_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// CMU_enter_DefaultMode_from_RESET
//================================================================================
extern void CMU_enter_DefaultMode_from_RESET(void) {

	// $[High Frequency Clock Setup]
	/* Initializing HFXO */
	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;

	CMU_HFXOInit(&hfxoInit);

	/* Setting system HFRCO frequency */
	CMU_HFRCOFreqSet (cmuHFRCOFreq_38M0Hz);

	/* Using HFRCO as high frequency clock, HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	// [High Frequency Clock Setup]$

	// $[LE clocks enable]
	/* Enable LFRCO oscillator, and wait for it to be stable */
	CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);

	// [LE clocks enable]$

	// $[LFACLK Setup]
	/* LFACLK is disabled */
	// [LFACLK Setup]$
	// $[LFBCLK Setup]
	/* LFBCLK is disabled */
	// [LFBCLK Setup]$
	// $[LFECLK Setup]
	/* LFECLK is disabled */
	// [LFECLK Setup]$
	// $[Peripheral Clock enables]
	/* Enable clock for HF peripherals */
	CMU_ClockEnable(cmuClock_HFPER, true);

	/* Enable clock for CRYOTIMER */
	CMU_ClockEnable(cmuClock_CRYOTIMER, true);

	/* Enable clock for LDMA */
	CMU_ClockEnable(cmuClock_LDMA, true);

	/* Enable clock for USART0 */
	CMU_ClockEnable(cmuClock_USART0, true);

	/* Enable clock for USART1 */
	CMU_ClockEnable(cmuClock_USART1, true);

	/* Enable clock for GPIO by default */
	CMU_ClockEnable(cmuClock_GPIO, true);

	// [Peripheral Clock enables]$

	// $[Clock output]
	/* Disable CLKOUT0 output */
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_CLKOUTSEL0_MASK)
			| CMU_CTRL_CLKOUTSEL0_DISABLED;
	/* Disable CLKOUT1 output */
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_CLKOUTSEL1_MASK)
			| CMU_CTRL_CLKOUTSEL1_DISABLED;

	// [Clock output]$

	// $[CMU_IO]
	/* Disable CLKOUT0 pin */
	CMU->ROUTEPEN &= ~CMU_ROUTEPEN_CLKOUT0PEN;

	/* Disable CLKOUT1 pin */
	CMU->ROUTEPEN &= ~CMU_ROUTEPEN_CLKOUT1PEN;

	// [CMU_IO]$

}

//================================================================================
// ADC0_enter_DefaultMode_from_RESET
//================================================================================
extern void ADC0_enter_DefaultMode_from_RESET(void) {

	// $[ADC0_Init]
	// [ADC0_Init]$

	// $[ADC0_InputConfiguration]
	// [ADC0_InputConfiguration]$

}

//================================================================================
// ACMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP0_enter_DefaultMode_from_RESET(void) {

	// $[ACMP0_Init]
	// [ACMP0_Init]$

	// $[ACMP0_IO]
	// [ACMP0_IO]$

}

//================================================================================
// ACMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP1_enter_DefaultMode_from_RESET(void) {

	// $[ACMP1_Init]
	// [ACMP1_Init]$

	// $[ACMP1_IO]
	// [ACMP1_IO]$

}

//================================================================================
// IDAC0_enter_DefaultMode_from_RESET
//================================================================================
extern void IDAC0_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// RTCC_enter_DefaultMode_from_RESET
//================================================================================
extern void RTCC_enter_DefaultMode_from_RESET(void) {

	// $[Compare/Capture Channel 0 init]
	// [Compare/Capture Channel 0 init]$

	// $[Compare/Capture Channel 1 init]
	// [Compare/Capture Channel 1 init]$

	// $[Compare/Capture Channel 2 init]
	// [Compare/Capture Channel 2 init]$

	// $[RTCC init]
	// [RTCC init]$

}

//================================================================================
// USART0_enter_DefaultMode_from_RESET
//================================================================================
extern void USART0_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.enable = usartDisable;
	initasync.baudrate = 115200;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(USART0, &initasync);
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART0, &initprs);
	// [USART_InitPrsTrigger]$

	// $[USART_InitIO]
	/* Disable CLK pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_CLKLOC_MASK))
			| USART_ROUTELOC0_CLKLOC_LOC0;
	USART0->ROUTEPEN = USART0->ROUTEPEN & (~USART_ROUTEPEN_CLKPEN);

	/* Disable CS pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_CSLOC_MASK))
			| USART_ROUTELOC0_CSLOC_LOC0;
	USART0->ROUTEPEN = USART0->ROUTEPEN & (~USART_ROUTEPEN_CSPEN);

	/* Set up CTS pin */
	USART0->ROUTELOC1 = (USART0->ROUTELOC1 & (~_USART_ROUTELOC1_CTSLOC_MASK))
			| USART_ROUTELOC1_CTSLOC_LOC30;
	USART0->ROUTEPEN = USART0->ROUTEPEN | USART_ROUTEPEN_CTSPEN;

	/* Set up RTS pin */
	USART0->ROUTELOC1 = (USART0->ROUTELOC1 & (~_USART_ROUTELOC1_RTSLOC_MASK))
			| USART_ROUTELOC1_RTSLOC_LOC30;
	USART0->ROUTEPEN = USART0->ROUTEPEN | USART_ROUTEPEN_RTSPEN;

	/* Set up RX pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_RXLOC_MASK))
			| USART_ROUTELOC0_RXLOC_LOC0;
	USART0->ROUTEPEN = USART0->ROUTEPEN | USART_ROUTEPEN_RXPEN;

	/* Set up TX pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_TXLOC_MASK))
			| USART_ROUTELOC0_TXLOC_LOC0;
	USART0->ROUTEPEN = USART0->ROUTEPEN | USART_ROUTEPEN_TXPEN;

	// [USART_InitIO]$

	// $[USART_Misc]
	/* Disable CTS */
	USART0->CTRLX = USART0->CTRLX & (~USART_CTRLX_CTSEN);
	/* Set CTS active low */
	USART0->CTRLX = USART0->CTRLX & (~USART_CTRLX_CTSINV);
	/* Set RTS active low */
	USART0->CTRLX = USART0->CTRLX & (~USART_CTRLX_RTSINV);
	/* Set CS active low */
	USART0->CTRL = USART0->CTRL & (~USART_CTRL_CSINV);
	/* Set TX active high */
	USART0->CTRL = USART0->CTRL & (~USART_CTRL_TXINV);
	/* Set RX active high */
	USART0->CTRL = USART0->CTRL & (~USART_CTRL_RXINV);
	// [USART_Misc]$

	// $[USART_Enable]

	/* Enable USART if opted by user */
	USART_Enable(USART0, usartEnable);
	// [USART_Enable]$

}

//================================================================================
// USART1_enter_DefaultMode_from_RESET
//================================================================================
extern void USART1_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;

	initsync.enable = usartDisable;
	initsync.baudrate = 130000;
	initsync.databits = usartDatabits8;
	initsync.master = 1;
	initsync.msbf = 1;
	initsync.clockMode = usartClockMode0;
#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable = 0;
	initsync.prsRxCh = 0;
	initsync.autoTx = 0;
#endif

	USART_InitSync(USART1, &initsync);
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART1, &initprs);
	// [USART_InitPrsTrigger]$

	// $[USART_InitIO]
	/* Set up CLK pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_CLKLOC_MASK))
			| USART_ROUTELOC0_CLKLOC_LOC11;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_CLKPEN;

	/* Disable CS pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_CSLOC_MASK))
			| USART_ROUTELOC0_CSLOC_LOC0;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_CSPEN);

	/* Disable CTS pin */
	USART1->ROUTELOC1 = (USART1->ROUTELOC1 & (~_USART_ROUTELOC1_CTSLOC_MASK))
			| USART_ROUTELOC1_CTSLOC_LOC0;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_CTSPEN);

	/* Disable RTS pin */
	USART1->ROUTELOC1 = (USART1->ROUTELOC1 & (~_USART_ROUTELOC1_RTSLOC_MASK))
			| USART_ROUTELOC1_RTSLOC_LOC0;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_RTSPEN);

	/* Set up RX pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_RXLOC_MASK))
			| USART_ROUTELOC0_RXLOC_LOC11;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_RXPEN;

	/* Set up TX pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_TXLOC_MASK))
			| USART_ROUTELOC0_TXLOC_LOC11;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_TXPEN;

	// [USART_InitIO]$

	// $[USART_Misc]
	/* Disable CTS */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_CTSEN);
	/* Set CTS active low */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_CTSINV);
	/* Set RTS active low */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_RTSINV);
	/* Set CS active low */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_CSINV);
	/* Set TX active high */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_TXINV);
	/* Set RX active high */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_RXINV);
	// [USART_Misc]$

	// $[USART_Enable]

	/* Enable USART if opted by user */
	USART_Enable(USART1, usartEnable);
	// [USART_Enable]$

}

//================================================================================
// LEUART0_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART0_enter_DefaultMode_from_RESET(void) {

	// $[LEUART0 initialization]
	// [LEUART0 initialization]$

}

//================================================================================
// WDOG0_enter_DefaultMode_from_RESET
//================================================================================
extern void WDOG0_enter_DefaultMode_from_RESET(void) {

	// $[WDOG Initialization]
	// [WDOG Initialization]$

}

//================================================================================
// I2C0_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C0_enter_DefaultMode_from_RESET(void) {

	// $[I2C0 I/O setup]
	// [I2C0 I/O setup]$

	// $[I2C0 initialization]
	// [I2C0 initialization]$

}

//================================================================================
// GPCRC_enter_DefaultMode_from_RESET
//================================================================================
extern void GPCRC_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// LDMA_enter_DefaultMode_from_RESET
//================================================================================
extern void LDMA_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// TIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER0_enter_DefaultMode_from_RESET(void) {

	// $[TIMER0 I/O setup]
	// [TIMER0 I/O setup]$

	// $[TIMER0 initialization]
	// [TIMER0 initialization]$

	// $[TIMER0 CC0 init]
	// [TIMER0 CC0 init]$

	// $[TIMER0 CC1 init]
	// [TIMER0 CC1 init]$

	// $[TIMER0 CC2 init]
	// [TIMER0 CC2 init]$

	// $[TIMER0 DTI init]
	// [TIMER0 DTI init]$

}

//================================================================================
// TIMER1_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER1_enter_DefaultMode_from_RESET(void) {

	// $[TIMER1 I/O setup]
	// [TIMER1 I/O setup]$

	// $[TIMER1 initialization]
	// [TIMER1 initialization]$

	// $[TIMER1 CC0 init]
	// [TIMER1 CC0 init]$

	// $[TIMER1 CC1 init]
	// [TIMER1 CC1 init]$

	// $[TIMER1 CC2 init]
	// [TIMER1 CC2 init]$

	// $[TIMER1 CC3 init]
	// [TIMER1 CC3 init]$

}

//================================================================================
// LETIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void LETIMER0_enter_DefaultMode_from_RESET(void) {

	// $[LETIMER0 Compare Values]
	// [LETIMER0 Compare Values]$

	// $[LETIMER0 Repeat Values]
	// [LETIMER0 Repeat Values]$

	// $[LETIMER0 Initialization]
	// [LETIMER0 Initialization]$

	// $[LETIMER0 PRS Input Triggers]
	// [LETIMER0 PRS Input Triggers]$

	// $[LETIMER0 I/O setup]
	// [LETIMER0 I/O setup]$

}

//================================================================================
// CRYOTIMER_enter_DefaultMode_from_RESET
//================================================================================
extern void CRYOTIMER_enter_DefaultMode_from_RESET(void) {

	// $[CRYOTIMER_Init]
	CRYOTIMER_Init_TypeDef cryoInit = CRYOTIMER_INIT_DEFAULT;

	/* General settings */
	cryoInit.enable = 1;
	cryoInit.debugRun = 0;
	cryoInit.em4Wakeup = 0;

	/* Clocking settings */
	/* With a frequency of 32768Hz on LFRCO, this will result in a 0.98 ms timeout */
	cryoInit.osc = cryotimerOscLFRCO;
	cryoInit.presc = cryotimerPresc_32;
	cryoInit.period = cryotimerPeriod_1;
	CRYOTIMER_Init(&cryoInit);
	// [CRYOTIMER_Init]$

}

//================================================================================
// PCNT0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT0_enter_DefaultMode_from_RESET(void) {

	// $[PCNT0 I/O setup]
	// [PCNT0 I/O setup]$

	// $[PCNT0 initialization]
	// [PCNT0 initialization]$

}

//================================================================================
// PRS_enter_DefaultMode_from_RESET
//================================================================================
extern void PRS_enter_DefaultMode_from_RESET(void) {

	// $[PRS initialization]
	// [PRS initialization]$

}

//================================================================================
// PORTIO_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTIO_enter_DefaultMode_from_RESET(void) {

	// $[Port A Configuration]

	/* Pin PA0 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortA, 0, gpioModePushPull, 0);

	/* Pin PA1 is configured to Input enabled with pull-up */
	GPIO_PinModeSet(gpioPortA, 1, gpioModeInputPull, 1);

	/* Pin PA3 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortA, 3, gpioModePushPull, 0);

	/* Pin PA5 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortA, 5, gpioModePushPull, 1);
	// [Port A Configuration]$

	// $[Port B Configuration]
	// [Port B Configuration]$

	// $[Port C Configuration]

	/* Pin PC6 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 1);

	/* Pin PC7 is configured to Input enabled with pull-up */
	GPIO_PinModeSet(gpioPortC, 7, gpioModeInputPull, 1);

	/* Pin PC8 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortC, 8, gpioModePushPull, 1);

	/* Pin PC9 is configured to Input enabled with pull-up */
	GPIO_PinModeSet(gpioPortC, 9, gpioModeInputPull, 1);

	/* Pin PC10 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortC, 10, gpioModePushPull, 1);
	// [Port C Configuration]$

	// $[Port D Configuration]

	/* Pin PD10 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 10, gpioModePushPull, 1);
	// [Port D Configuration]$

	// $[Port E Configuration]
	// [Port E Configuration]$

	// $[Port F Configuration]

	/* Pin PF4 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0);

	/* Pin PF5 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 0);
	// [Port F Configuration]$

}

