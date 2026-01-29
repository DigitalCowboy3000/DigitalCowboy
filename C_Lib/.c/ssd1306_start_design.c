/*------------------------------------------------------------------------
Prototype
Prototype.c
Jonas Dubey 
Yverdon-les-bains

uc: STM32 G071RBT6

Création		: 29.01.26
Révision		: -

Description  :  
--------------------------------------------------------------------------*/	
#include "ssd1306_start_design.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"
#include "ssd1306_fonts.h"
#include "stm32g0xx_hal.h"


// Equivalences

// Variables globales

void ssd1306_start_fill_cube(void);
/*------------------------------------------------------------------------
Fonction  :
Description  :
Entrées  :  -
Sorties  :  -
--------------------------------------------------------------------------*/
{
  unsigned char x , y , i , j;
  
  for( y = 0; y < 63; y =y+8 )
  {
	  for( x = 0; x < 127; x =x+8  )
	  {
		  for ( i = 0; i < 8; i++)
		  {
			  for ( j = 0; j < 8; j++)
			  {
				  ssd1306_DrawPixel(x + j, y + i, White);
			  }
		  }
		  ssd1306_UpdateScreen();
	  }
  }
}

void ssd1306_start_contrast_waiting(void);
/*------------------------------------------------------------------------
Fonction  :
Description  :
Entrées  :  -
Sorties  :  -
--------------------------------------------------------------------------*/
{
  unsigned char contrast, i;
  
  for(i = 0; i < 5; i++)
  {
	  for( contrast = 0x81; contrast > 0; contrast-- )
	  {
		  ssd1306_SetContrast(contrast);
		  HAL_Delay(5);
	  }

	  for( contrast = 0; contrast < 0x81; contrast++ )
	  {
		  ssd1306_SetContrast(contrast);
		  HAL_Delay(5);
	  }
  }
}
