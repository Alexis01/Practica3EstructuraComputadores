#ifndef __P3B_H__
#define __P3B_H__

// Ficheros a incluir
#include "44b.h"
#include "44blib.h"
#include "def.h"

// 8SEG-LED
#define SEGMENT_A 0x80
#define SEGMENT_B 0x40
/** Definir desde SEGMENT_C a SEGMENT_F **/
#define SEGMENT_G 0x01
#define SEGMENT_P 0x10

#define DIGIT_F	(SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_F)
/** Definir desde DIGIT_E hasta DIGIT_1 **/
#define DIGIT_0	(SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_G)

// TECLADO
#define KEY_VALUE_MASK	0x0f

// Declaración de funciones

void init_int();

void dec_to_hex_in8leds(int value);

void keyboard_int(void) __attribute__ ((interrupt ("IRQ")));

void timer_int(void) __attribute__ ((interrupt ("IRQ")));

void leds_switch();

void leds_display(int LedStatus);


#endif /* __P3B_H__ */
