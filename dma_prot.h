#ifndef _DMA_PROT_H
#define _DMA_PROT_H
/*******************************************************************************
* Filename          : dma_prot.h
* Module            : DMA
* Project           : Demo
* Author	    : Shilesh Babu
*-------------------------------------------------------------------------------
* Description       : This module handles the tasks.
*-------------------------------------------------------------------------------
* Processor(s)      : MSP430FR6XX
* Compiler(s)       : CCE
*-------------------------------------------------------------------------------
$Header$
*******************************************************************************/ 

typedef struct
{
	uword destination;
	uword source;
	uword  size;
}DMA_Config_t;

//void DMA_DMAUartInit(DMA_Config_t * dmaparms);
void DMA_DMAUartInit();
/******************************************************************************* 
* Defines 
*******************************************************************************/ 
#endif  /*_DMA_PROT_H  */
/*******************************************************************************
* Change History:
$Log$
*
********************************* END OF FILE *********************************/

