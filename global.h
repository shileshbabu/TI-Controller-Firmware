#ifndef _GLOBAL_H
#define _GLOBAL_H
/*******************************************************************************
* Filename      : GLOBAL.H
* Module        : global
* Project       : Demo
* Author	: Shilesh Babu
*-------------------------------------------------------------------------------
* Description   : This file defines all types and constants which are
*                 common to the whole module library.
*                 No symbol defined in this file must be redefined !
*-------------------------------------------------------------------------------
* Processor(s)  : MSP430FR68xx
* Compiler(s)   : CCE
*-------------------------------------------------------------------------------
$Header$
*******************************************************************************/
/*Include standerd c libbray*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
* Defines
*******************************************************************************/
#define FALSE           0
#define TRUE            1

#define	SET             1
#define	CLEAR           0

#define	GLB_VALID       1
#define	GLB_INVALID     2

#define	BLOCKA	1
#define	BLOCKB	2
#define	BLOCKC	3
#define	BLOCKD	4




#define ArrayOf(Type, Var) ((Type *) & Var)	/* return the address of variable */
/* Macros to pass two 16-bit arguments in a single 32-bit argument. */
#define PackArgs( Arg1, Arg2 ) ( (Arg1) | ((tUI32) (Arg2) << 16) )

/* An integer that is a power of 2 i.e. a mask with one bit set */
#define mBit32( Power ) ( 1uL << (Power) )
#define mBit16( Power ) ( 1u  << (Power) )

/* Macro Defination for Byte & Word operation */
#define GLB_HIBYTE(w)     ( (ubyte) (((uword)(w)) >> 8) )
#define GLB_LOBYTE(w)     ( (ubyte) (((uword)(w)) &  0xFF) )
#define GLB_WORD(hib,lob)   ( (((uword)(hib)) << 8)  + ((uword)(lob)) )
/*******************************************************************************
* Code enable/disbale related macro Defines
*******************************************************************************/


/*******************************************************************************
* Type definitions
*******************************************************************************/
/* These  defined types shall be used instead of the basic C types,           */
/* whenever a variable of 1..4 signed or unsigned byte(s) is required.        */
/* Reason :                                                                   */
/* The length of some basic C types is not strictly defined in ANSI C, thus   */
/* allowing different lengths in different implementations (= compilers).     */
/* In case of any future changes, only these defined types will have to       */
/* be changed here, but all the already written C code can remain unchanged.  */

typedef unsigned char  bool;      /* 1 bit of Bit Area, type identifier: bl   */
typedef signed char    sbyte;     /* 1 byte signed,   type identifier: sb     */
typedef unsigned char  ubyte;     /* 1 byte unsigned, type identifier: ub     */
typedef signed short   sword;     /* 2 byte signed,   type identifier: sw     */
typedef unsigned short uword;     /* 2 byte unsigned, type identifier: uw     */
typedef signed long    slword;    /* 4 byte signed,   type identifier: slw    */
typedef unsigned long  ulword;    /* 4 byte unsigned, type identifier: ulw    */

/* The following types provide automatic usage of loop counters with          */
/* optimum length. Their lenghts depend on the register size of the used      */
/* processor. REGISTER_SIZE defined in conditn.h.                             */
typedef sbyte smctr;
typedef ubyte umctr;

/* The following type should be used when functions are accessed via an       */
/* of their addresses.                                                        */

typedef void  (*func_array)(void);
/* Structure Type definition for Time */
typedef struct
{
  ubyte	ubSecond;
  ubyte ubMinute;
  ubyte ubHour;
  ubyte ubDate;
  ubyte ubMonth;
  uword uwYear;
}sTime;

typedef struct {
	ubyte sof;
	ubyte cmd;
	ubyte data[12];
	uword crc;

}SCI_CMDFrame;

typedef struct
{
	ubyte sof;
	ubyte str;
	ubyte data[12];
	uword crc;
}SCI_STRFrame;


/* Union Type definition for Communication flags */
typedef union
{
  ubyte ubFlagArray[4];
  ulword ulFlagReg;
}SCI_Flags;


typedef struct
{
	bool cntbuffer_status1;
	ubyte cntbuffer_status2;
	ubyte flag;
	ubyte dma_status;
	ubyte * crt_ptr1;
	ubyte * crt_ptr2;
	ubyte * crt_ptr3;
}mem_status_t;

typedef enum {
	MEM_IDLE = 1,
	MEM_FREE,
	MEM_BUSY
}mem_t;

/******************************* END OF FILE **********************************/
#endif                                                           /* _GLOBAL_H */
/*******************************************************************************
*
********************************* END OF FILE *********************************/
