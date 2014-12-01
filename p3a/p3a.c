#include "p3a.h"

// VARIABLES GLOBALES

// 8SEG-LED - Tabla de símbolos digitales
int Symbol[] = { DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7,
    			 DIGIT_8, DIGIT_9, DIGIT_A, DIGIT_B, DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F};

// Dirección de control del teclado
volatile UCHAR *keyboard_base = (UCHAR *)0x06000000;

void init_int()
{
  // Habilitamos las interrupciones, IRQ con vectores
   rINTMOD =0x0;
   rINTCON =0x1;
  /// Desenmascaramos EINT1
  rINTMSK =~(BIT_GLOBAL|BIT_EINT1);
  /// Establecemos la función keyboard_int como ISR para EINT1
  pISR_EINT1 = (int) keyboard_int;
  
  rEXTINT = (rEXTINT|0x20); // EINT1 -> flanco de bajada
  rI_ISPC = BIT_EINT1; // Limpiamos el bit de EINT1 pendiente
}

// Funciones para el display 8 segmentos

void dec_to_hex_in8leds(int value) {
  /** Mostrar el valor sólo si value>=0 y value<16 **/
  if(value >=0 && value<16){
  		LED8ADDR=~Symbol[value];
  }
}

// Funciones para el teclado

void keyboard_int(void)
{
	int value;
	rI_ISPC = BIT_EINT1;			// impiamos el bit de EINT1 pendiente
	
	value = key_read();
	if(value > -1)
	 {
		dec_to_hex_in8leds(value);
     }

}
//devuelve el valor de la columna asociado
int detectaColumna(char temp){
	temp &= KEY_VALUE_MASK;
	switch(temp){
		case 0xE:
			return 12;
		case 0xD:
			return 8;
		case 0xB:
			return 4;
		case 0x7:
			return 0;
	}
}

inline int key_read()
{
  int value;
  char temp;
  // Leemos la primera columna  
  temp = *(keyboard_base+0xfd);
  if(( temp & KEY_VALUE_MASK) != KEY_VALUE_MASK) 	{ 
    /** Averiguar qué columna ha sido **/
    return detectaColumna(temp);
  }
  //leemos la segunda columna
  temp=*(keyboard_base+0xfb);
  if(( temp & KEY_VALUE_MASK) != KEY_VALUE_MASK){
  	return 1+detectaColumna(temp);
  }
  //leemos la tercera columna
  temp=*(keyboard_base+0xf7);
  if(( temp & KEY_VALUE_MASK) != KEY_VALUE_MASK){
  	return 2+detectaColumna(temp);
  }
  //leemos la cuarta columna
  temp=*(keyboard_base+0xef);
   if(( temp & KEY_VALUE_MASK) != KEY_VALUE_MASK){
  	return 3+detectaColumna(temp);
  }
  /** Hacer lo mismo con el resto de filas **/
  return -1;
}
