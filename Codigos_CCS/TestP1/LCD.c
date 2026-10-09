/*
 * LCD.c
 *
 *  Created on: 28/09/2026
 *      Author: Julia Elizabeth Cuesta Quezada
 *              Dania Guadalupe Rosales Trujillos
 */

#include "lcd.h"
#include "segundos.h"
#include <msp430.h>

// pines del lcd
#define RS BIT0
#define E  BIT1
#define D4 BIT4
#define D5 BIT5
#define D6 BIT6
#define D7 BIT7

// activar el pulso de enable
void enable(void){
    P2OUT |= E;
    P2OUT &= ~E;
}
// comandos en la lcd (rs = 0)
void lcd_comando(int comando){
    P2OUT &= ~RS;
    P1OUT = ((comando) & (D4|D5|D6|D7)); // colocar los datos de los pines
    enable();
    espera_init(0);
    espera(1);

    P1OUT = ((comando<<4) & (D4|D5|D6|D7));
    enable();
    espera_init(0);
    espera(2);
}
// limpia pantalla y regresa cursor
void lcd_limpiar(void){
    lcd_comando(0x01);
    lcd_comando(0x80);
}
// inicializacion de la lcd (prender pantalla, ajuste a modo de 4 bits)
void lcd_init (void){
  // milisegundos
    P2DIR |= RS|E; // inicializa los primeros 2 bits para lcd control
    P1DIR |= D4|D5|D6|D7; // inicializa los pines de datos
    espera_init(2);
    espera(15);
    lcd_comando(0x03);
    espera_init(2);
    espera(5);
    lcd_comando(0x03);
    espera_init(2);
    espera(1);
    lcd_comando(0x03);
    espera_init(2);
    espera(1);
    lcd_comando(0x02);
    espera_init(2);
    espera(1);

    lcd_comando(0x28);
    lcd_comando(0x0C);
    lcd_comando(0x06);
    lcd_comando(0x01);
}
// lcd impresiones de pantalla
void lcd_letra(int letra){

    P1OUT = (letra) & (D4|D5|D6|D7);    // colocar dato
    P2OUT |= RS;
    enable();
    espera_init(0);
    espera(1);

    P1OUT = (letra<<4) & (D4|D5|D6|D7);
    P2OUT |= RS;
    enable();
    espera_init(0);
    espera(2);
    P2OUT &=~ RS;

}

// agregar nuevo simbolo en la cgram
void lcd_nuevosim(int posicioncgram, int *fila){
    int i;

    lcd_comando(posicioncgram);

    for(i = 0; i < 8; i++){
        lcd_letra(fila[i]);
    }
}







