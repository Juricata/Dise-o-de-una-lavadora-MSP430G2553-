/*
 * LCD.c
 *
 *  Created on: 28/09/2026
 *      Author: Julia Elizabeth Cuesta Quezada
 *              Dania Guadalupe Rosales Trujillos
 */

#include "lcd.h"
#include <msp430.h>

// pines del lcd
#define RS BIT0
#define E  BIT1
#define D4 BIT2
#define D5 BIT3
#define D6 BIT4
#define D7 BIT5

// esperar una cantida aproximada de milisegundos
void esperar(int milisegundos){
    volatile int j;
    while(milisegundos--){
        for(j = 0; j < 1000; j++);
    }
}
// activar el pulso de enable
void enable(void){
    P1OUT |= E;
    P1OUT &= ~E;
}
// comandos en la lcd (rs = 0)
void lcd_comando(int comando){
    P1OUT = ((comando>>2) & 0x3C); // colocar primer dato entre los bits 2 - 6
    enable();
    esperar(1);

    P1OUT = ((comando<<2) & 0x3C);
    enable();
    esperar(5);
}
// inicializacion de la lcd (prender pantalla, ajuste a modo de 4 bits)
void lcd_init (void){

    P1DIR = 0x3F; // inicializa los primeros 6 bits para lcd

    lcd_comando(0x03);
    esperar(5);
    lcd_comando(0x03);
    esperar(5);
    lcd_comando(0x03);
    esperar(5);
    lcd_comando(0x02);
    esperar(5);
    lcd_comando(0x28);
    lcd_comando(0x0C);
    lcd_comando(0x06);
    lcd_comando(0x01);
}
// lcd impresiones de pantalla
void lcd_letra(int letra){

    P1OUT = ((letra>>2) & 0x3C)|RS; // colocar primer dato entre los bits 2 - 6
    enable();
    esperar(1);

    P1OUT = ((letra<<2) & 0x3C)|RS;
    enable();
    esperar(5);
    P1OUT &=~ RS;

}

// agregar nuevo simbolo en la cgram
void lcd_nuevosim(int posicioncgram, int *fila){
    int i;

    lcd_comando(posicioncgram);

    for(i = 0; i < 8; i++){
        lcd_letra(fila[i]);
    }
}







