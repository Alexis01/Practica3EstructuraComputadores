extern char Image_RO_Limit[];
extern char Image_RO_Base[];
extern char Image_RW_Limit[];
extern char Image_RW_Base[];
extern char Image_ZI_Limit[];
extern char Image_ZI_Base[];

#include "p3a.h"

// Declaraci�n de funciones 
int Main(void);

// Definici�n de funciones
int Main(void)
{
    sys_init(); // Inicializa puertos e interrupciones del 44BOX a un modo seguro 
	
	init_int(); // Configura las interrupciones necesarias para esta pr�ctica
    
    while(1);
    
    return;
}

