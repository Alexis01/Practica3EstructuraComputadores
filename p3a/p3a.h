#ifndef __P3A_H__
#define __P3A_H__

// Ficheros a incluir
#include "44b.h"
#include "44blib.h"
#include "def.h"

// 8SEG-LED
#define SEGMENT_A 0x80
#define SEGMENT_B 0x40
/** Definir desde SEGMENT_C a SEGMENT_F **/
#define SEGMENT_C 0x20
#define SEGMENT_D 0x8
#define SEGMENT_E 0x4
#define SEGMENT_F 0x2
#define SEGMENT_G 0x01
#define SEGMENT_P 0x10

#define DIGIT_F	(SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_F)
/** Definir desde DIGIT_E hasta DIGIT_1 **/
#define DIGIT_E (SEGMENT_A | SEGMENT_G | SEGMENT_F | SEGMENT_E | SEGMENT_D)
#define DIGIT_D (SEGMENT_E | SEGMENT_D | SEGMENT_F | SEGMENT_C | SEGMENT_B)
#define DIGIT_C (SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_D)
#define DIGIT_B (SEGMENT_G | SEGMENT_F | SEGMENT_E | SEGMENT_C | SEGMENT_D)
#define DIGIT_A (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_E | SEGMENT_F | SEGMENT_G)
#define DIGIT_9 (SEGMENT_G | SEGMENT_A | SEGMENT_F | SEGMENT_B | SEGMENT_C)
#define DIGIT_8 (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G)
#define DIGIT_7 (SEGMENT_A | SEGMENT_B | SEGMENT_C)
#define DIGIT_6 (SEGMENT_A | SEGMENT_G | SEGMENT_F | SEGMENT_E | SEGMENT_C | SEGMENT_D)
#define DIGIT_5 (SEGMENT_A | SEGMENT_G | SEGMENT_F | SEGMENT_C | SEGMENT_D)
#define DIGIT_4 (SEGMENT_G | SEGMENT_F | SEGMENT_B | SEGMENT_C)
#define DIGIT_3 (SEGMENT_A | SEGMENT_B | SEGMENT_F | SEGMENT_C | SEGMENT_D)
#define DIGIT_2 (SEGMENT_A | SEGMENT_B | SEGMENT_F | SEGMENT_E | SEGMENT_D)
#define DIGIT_1 (SEGMENT_B | SEGMENT_C)
#define DIGIT_0	(SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_G)

// TECLADO
#define KEY_VALUE_MASK	0x0f

// Declaración de funciones

void init_int();

void dec_to_hex_in8leds(int value);

void keyboard_int(void) __attribute__ ((interrupt ("IRQ")));


#endif /* __P3A_H__ */
