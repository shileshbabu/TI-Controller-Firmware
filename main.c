/***************************************************************************@DA*
* Filename          : main.c
* Module            : MAIN
* Project           : Demo
* Author	    : Shilesh Babu
*-------------------------------------------------------------------------------
* Description       : This file is the entry point of main function
*-------------------------------------------------------------------------------
* Processor(s)      : MSP430FR6XX
* Compiler(s)       : CCE
*-------------------------------------------------------------------------------
$Header$
***************************************************************************@DE*/


#include "project.h"
#include "sci_prot.h"
#include "tsk_prot.h"


extern volatile uword TSK_uwTskStatus;
/*
 *
 * main.c
 */
int main(void)
{

	WDTCTL = WDTPW | WDTHOLD; 			 /* Stop watchdog timer*/
	PM5CTL0 &= ~LOCKLPM5; 				/* low power mode disable  */
    CSCTL0_H = CSKEY >> 8;               /* Unlock CS registers */
	CSCTL1 = DCOFSEL_6;                  /*  Set DCO to 8MHz */
	CSCTL2 = SELA__VLOCLK | SELS__DCOCLK | SELM__DCOCLK;  /* Set SMCLK = MCLK = DCO */
	CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;     /* Set all dividers to 1 */
	CSCTL0_H = 0;                             /* Lock CS registers */
//	Led_Reset();
	INT_DefaultIntClear();
	TSK_vRAMInit();
	SCI_vUARTInit();
	TMR_vTMRInit();
	//Led_Init();
	INT_DefaultInit();

	 __bis_SR_register(GIE); 				 /* Enabling Global Interruot */
	 SCI_DefInit();

	 I2CM_I2CReset(I2CM1_CHANNEL,15);
	 I2CM_I2CReset(I2CM2_CHANNEL,15);

	 ubyte buffer[6];

	while(1)
	{
		if (TSK_uwTskStatus != CLEAR)
			TSK_vTskHandler(TSK_uwTskStatus);
		__no_operation();
	}
}
