#define _PRINTF_WRITE_C
/***************************************************************************@DA*
* Filename          : printf_write.c
* Module            : TSK
* Project           : Demo
* Author	    : Shilesh Babu
*-------------------------------------------------------------------------------
*-------------------------------------------------------------------------------
* Description       : This module handles the print tasks to be handled
*-------------------------------------------------------------------------------
* Processor(s)      : MSP430FR6XX
* Compiler(s)       : CCE
*-------------------------------------------------------------------------------*/
#if (UART_DEBUG == TRUE)
#include "project.h"
#include <stdio.h>
#include <string.h>

#define UART_DEBUG_PORT (1)


int fputc(int _c, register FILE *_fp);
int fputs(const char *_ptr, register FILE *_fp);


void PRINT_vInit(void);


void PRINT_vInit(void)
{
#if UART_DEBUG == TRUE
#if (UART_DEBUG_PORT == 0x01)
	  /* UART USCI0_A0 P3.4 -> UCATX P3.5 -> UCARX */
		P3SEL0 |= BIT4 | BIT5;
		//P3SEL1 &=~ BIT4 | BIT5;
    /*UART configuration for USCI0 channle */
		UCA1CTLW0 = UCSWRST;           /* Put eUSCI in reset */
		UCA1CTLW0 |= UCSSEL__SMCLK;    /* CLK = SMCLK */
    /*Calcculation for baudrate */
    /*For 115200 Baudrate*/
		UCA1BR0 =4;
		UCA1MCTLW |= UCOS16 | UCBRF_5 | 0x5500;
		UCA1BR1 = 0x00;
		UCA1CTLW0 &= ~UCSWRST;
		UCA1IFG = 0;
#else
				P2SEL0 |= BIT0 | BIT1;
				P2SEL1 &=~ BIT0 | BIT1;
		      /*UART configuration for USCI0 channle */
		      UCA0CTLW0 = UCSWRST;           /* Put eUSCI in reset */
		      UCA0CTLW0 |= UCSSEL__SMCLK;    /* CLK = SMCLK */
		      /*Calcculation for baudrate */
		      /*For 115200 Baudrate*/
		      UCA0BR0 =4;
		      UCA0MCTLW |= UCOS16 | UCBRF_5 | 0x5500;
		      UCA0BR1 = 0x00;
		      UCA0CTLW0 &= ~UCSWRST;
		      UCA0IE |= UCRXIE;
		      UCA0IFG = 0;


#endif
#endif

}


int fputc(int _c, register FILE *_fp)
{
#if (UART_DEBUG_PORT == 0x01)

		UCA1TXBUF = (unsigned char) _c;
		while(!(UCA1IFG&UCTXIFG));

#else
				UCA0TXBUF = (unsigned char) _c;
				while(!(UCA0IFG&UCTXIFG));

#endif
		 return((unsigned char)_c);
}


int fputs(const char *_ptr, register FILE *_fp)
{

	 unsigned int i, len;

	  len = strlen(_ptr);


	  for(i=0 ; i<len ; i++)
	  {
#if (UART_DEBUG_PORT == 0x01)
		  while(!(UCA1IFG&UCTXIFG));
	    UCA1TXBUF = (unsigned char) _ptr[i];
#else
		  while(!(UCA0IFG&UCTXIFG));
		    UCA0TXBUF = (unsigned char) _ptr[i];
#endif
	  }


	  return len;
}
#endif

