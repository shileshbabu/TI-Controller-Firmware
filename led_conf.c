#define _LED_CONF_C
/****************************************************************************
* Filename          : led_conf.c
* Module            : LED  (TLC59116F)
* Project           : Demo
* Author	    : Shilesh Babu
*-------------------------------------------------------------------------------
* Description       : This module enables the use of LED Module
*-------------------------------------------------------------------------------
* Processor(s)      : MSP430FR68xx
* Compiler(s)       : CCE Version: V6.1.1.00022(GCC)
*-------------------------------------------------------------------------------
$Header$
*******************************************************************************/

/*******************************************************************************
* Project Includes
*******************************************************************************/

#include "project.h"
#include "tsk_prot.h"


static ubyte dbuff[4];
/*Function to Calculate the Brightness for LED*/

ubyte LED_GetBrightCount(ulword ulbright)
{
	ubyte ultemp;
	ultemp = ((ulbright*256)/100);
	return ultemp;
};
/*Initialization for LED*/
void Led_Init()
{
	dbuff[0]=TLC59116_MODE1;
	dbuff[1]=0x00;
	if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);			// Default Configuration. OSci ON and LED all call

	dbuff[0]=TLC59116_MODE2;
	dbuff[1]=0x20;//0x20;//0x28;
	if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);			// Group Control Period
}
/*LED all stop and Reset*/
void Led_All_Stop()
{
	dbuff[0]=TLC59116_LEDOUT0;							// Turning OFF all LED On This command
	dbuff[1]=0x00;
	if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

	dbuff[0]=TLC59116_LEDOUT1;							// Turning OFF all LED On This command
	dbuff[1]=0x00;
	if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);


	dbuff[0]=TLC59116_LEDOUT2;							// Turning OFF all LED On This command
	dbuff[1]=0x00;
	if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

	dbuff[0]=TLC59116_LEDOUT3;							// Turning OFF all LED On This command
	dbuff[1]=0x00;
	if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

}

void led_select(ubyte id, ubyte select)
{
	switch (id)									 					// Switch according the Led Color
	{
		case cyan:
			dbuff[0]=TLC59116_LEDOUT0;
			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT);

			if(!(I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT)))
				I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT);

			dbuff[1] = ((dbuff[1] & 0xF3) | (select << 2));
			dbuff[1] = ((dbuff[1] & 0xCF) | (select << 4));

			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

			break;
		case blue:
			dbuff[0]=TLC59116_LEDOUT0;
			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT);

			if(!(I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT)))
				I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT);

			dbuff[1] = ((dbuff[1] & 0x3F) | (select << 6));

			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

			break;
		case orange:
			dbuff[0]=TLC59116_LEDOUT1;
			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT);

			if(!(I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT)))
				I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT);

			 dbuff[1] = ((dbuff[1] & 0xFC) | (select << 0));

			 if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			 	I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

	 		break;
		case red:
			dbuff[0]=TLC59116_LEDOUT1;
			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT);

			if(!(I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT)))
				I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT);

 			 dbuff[1] = ((dbuff[1] & 0xF3) | (select << 2));

			 if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
			 	I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

	 		break;
		case green:
			dbuff[0]=TLC59116_LEDOUT1;
			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT);

			if(!(I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT)))
				I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT);

			dbuff[1] = ((dbuff[1] & 0xCF) | (select << 4));

			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

			break;
		case yellow:
			dbuff[0]=TLC59116_LEDOUT1;
			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,&dbuff[0],I2CTIMEOUT);

			if(!(I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT)))
				I2CM_vI2CReadTimeout(I2CM2_CHANNEL,TLC59116_ADDR,1,(ubyte *)&dbuff[1],I2CTIMEOUT);

			dbuff[1] = ((dbuff[1] & 0x3F) | (select << 6));

			if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

			break;
	}
}

void LED_SetColor(TLC59116Config_t *ledcolor)
{
		switch (ledcolor->id)									 					// Switch according the Led Color
		{
			case cyan:
				led_select(ledcolor->id, 0x00);

				dbuff[0]=TLC59116_PWM1;											//RED Led
				dbuff[1]=ledcolor->brightness;												//LED on at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				dbuff[0]=TLC59116_PWM2;											// Green Led On
				dbuff[1]=ledcolor->brightness;												//LED on at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				if ((0 != ledcolor->period) && (255 != ledcolor->period))
				{
					dbuff[0]=TLC59116_GRPPWM;
					dbuff[1]=ledcolor->period;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
							I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					dbuff[0]=TLC59116_GRPFREQ;
					dbuff[1]=ledcolor->duration;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
							I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					led_select(ledcolor->id, 0x03);
				}
				else
				{
					led_select(ledcolor->id, 0x02);
				}

				break;

			case blue:															//Register for the blue
				led_select(ledcolor->id, 0x00);

				dbuff[0]=TLC59116_PWM3;//check now
				dbuff[1]=ledcolor->brightness;													//LED On at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				if ((0 != ledcolor->period) && (255 != ledcolor->period)) //TO
				{
					dbuff[0]=TLC59116_GRPPWM;
					dbuff[1]=ledcolor->period;												//Duration
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					dbuff[0]=TLC59116_GRPFREQ;
					dbuff[1]=ledcolor->duration;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					led_select(ledcolor->id, 0x03);
				}
				else
				{
					led_select(ledcolor->id, 0x02);
				}

				break;

			case orange:														//Register for the orange
				led_select(ledcolor->id, 0x00);

				dbuff[0]=TLC59116_PWM4;
				dbuff[1]=ledcolor->brightness;//0xff;											//LED On at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				if ((0 != ledcolor->period) && (255 != ledcolor->period)) //TO
				{
					dbuff[0]=TLC59116_GRPPWM;
					dbuff[1]=ledcolor->period;												//Duration
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					dbuff[0]=TLC59116_GRPFREQ;
					dbuff[1]=ledcolor->duration;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					led_select(ledcolor->id, 0x03);
				}
				else
				{
					led_select(ledcolor->id, 0x02);
				}

				break;
			case red:										  			 		//Register for the red
				led_select(ledcolor->id, 0x00);

				dbuff[0]=TLC59116_PWM5;
				dbuff[1]=ledcolor->brightness;//0xff;											//LED On at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				if ((0 != ledcolor->period) && (255 != ledcolor->period)) //TO
				{
					dbuff[0]=TLC59116_GRPPWM;
					dbuff[1]=ledcolor->period;												//Duration
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					dbuff[0]=TLC59116_GRPFREQ;
					dbuff[1]=ledcolor->duration;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					led_select(ledcolor->id, 0x03);
				}
				else
				{
					led_select(ledcolor->id, 0x02);
				}

				break;
			case green:															//Register for the Green
				led_select(ledcolor->id, 0x00);

				dbuff[0]=TLC59116_PWM6;
				dbuff[1]=ledcolor->brightness;												//LED On at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				if ((0 != ledcolor->period) && (255 != ledcolor->period)) //TO
				{
					dbuff[0]=TLC59116_GRPPWM;
					dbuff[1]=ledcolor->period;												//Duration
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);
					dbuff[0]=TLC59116_GRPFREQ;
					dbuff[1]=ledcolor->duration;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					led_select(ledcolor->id, 0x03);
				}
				else
				{
					led_select(ledcolor->id, 0x02);
				}

				break;

			case yellow:														//Set Register for the Yellow
				led_select(ledcolor->id, 0x00);

				dbuff[0]=TLC59116_PWM7;
				dbuff[1]=ledcolor->brightness;													//LED On at Full Brightness
				if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
					I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

				if ((0 != ledcolor->period) && (255 != ledcolor->period)) //TO
				{
					dbuff[0]=TLC59116_GRPPWM;
					dbuff[1]=ledcolor->duration;												//Duration
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					dbuff[0]=TLC59116_GRPFREQ;
					dbuff[1]=ledcolor->period;
					if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
						I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);

					led_select(ledcolor->id, 0x03);
				}
				else
				{
					led_select(ledcolor->id, 0x02);
				}

				break;
		}

}

void IrLed_on(ubyte value)
{
	if (value ==1)
	{
		dbuff[0]=TLC59116_LEDOUT2;
		dbuff[1]=0x15;													//IR-LED On at Full Brightness
		if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);
	}
	else
	{
		dbuff[0]=TLC59116_LEDOUT2;
		dbuff[1]=0x00;												//IR-LED Off
		if(!(I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT)))
				I2CM_vI2CWriteTimeout(I2CM2_CHANNEL,TLC59116_ADDR,2,dbuff,I2CTIMEOUT);
	}
}
