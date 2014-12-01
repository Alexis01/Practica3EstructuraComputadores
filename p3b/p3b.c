#include "p3b.h"

// VARIABLES GLOBALES

// 8SEG-LED - Tabla de símbolos digitales
int Symbol[] = { DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7,
    			 DIGIT_8, DIGIT_9, DIGIT_A, DIGIT_B, DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F};

// TECLADO - Dirección de control
volatile UCHAR *keyboard_base = (UCHAR *)0x06000000;

// LEDS - Variable global para controlar el estado de los leds
int led_state;

void init_int()
{
  // Habilitamos las interrupciones, IRQ con vectores
  /// rINTMOD = ¿?;
  /// rINTCON = ¿?;
  /// Desenmascaramos EINT1 y TIMER0
  /// Establecemos la función keyboard_int como ISR para EINT1
  /// Establecemos la función timer_int como ISR para TIMER0
  rEXTINT = rEXTINT|0x20; // EINT1 -> flanco de bajada
  // Configuramos el timer 0
  rTCFG0 = 255;
  rTCFG1 = 0x1;
  rTCNTB0 = 655352;
  rTCMPB0 = 128002;
  // Actualizamos TCNO0
  rTCON = 0x6;
  // Habilitamos el TIMER
  rTCON  = 0x19;
   
  rI_ISPC = BIT_EINT1|BIT_TIMER0; // Limpiamos los bits de EINT1 y TIMER0 pendientes	
}

// Funciones para el display 8 segmentos

void dec_to_hex_in8leds(int value) {
  /** Mostrar el valor sólo si value>=0 y value<16 **/
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

inline int key_read()
{
  int value;
  char temp;
  // Leemos fila J7_4 
  temp = *(keyboard_base+0xfd);
  if(( temp & KEY_VALUE_MASK) != KEY_VALUE_MASK) 	{ 
    /** Averiguar qué columna ha sido **/
    return value;
  }
  /** Hacer lo mismo con el resto de filas **/
  return -1;
}

// Funciones para el TIMER0
void timer_int(void)
{
  	leds_switch();
    /// rI_ISPC=¿?; // Limpiamos el bit de interrupción pendiente
}

// Funciones para los LEDS
void leds_switch()
{
  /** Actualizar la variable led_state acorde a su valor anterior **/
  leds_display(led_state);
}

void leds_display(int LedStatus)
{
  led_state = LedStatus;
  /** Actualizar el valor de rPDATB acorde a LedStatus **/
  // Ejemplo: if((LedStatus&0x01)==0x01) rPDATB=rPDATB&0x5ff;
}
