#include <msp430.h> 
#include "segundos.h"
#include "motor.h"
#include "botones.h"
#include "LCD.h"
#include "mensajes.h"
/**
 * main.c
 */
// Mensajes de la LCD


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	lcd_init(); // De la libreria LCD-> Funcion para configuracion y prendido inicial de LCD
	
	mensaje_encendido();
	mensaje_apagado();
	mensaje_alto();
	mensaje_bajo();
	mensaje_remojado();
	mensaje_lavado();
	mensaje_final_ciclo();

	return 0;
}




