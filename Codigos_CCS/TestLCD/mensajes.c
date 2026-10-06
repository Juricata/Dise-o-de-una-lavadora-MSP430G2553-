/*
 * mensajes.c
 *
 *  Created on: 04/10/2026
 *      Author: Julia y Dania
 */
//Funciones de la lcd para cada mensaje:
#include <msp430.h>
#include "segundos.h"
#include "LCD.h"

#define GUION 0x2D
#define UNO 0x31
#define DOS 0x32
#define TRES 0x33
#define DOSPUNTOS 0x3A
#define A 0x41
#define B 0x42
#define CE 0x43
#define E 0x45
#define I 0x49
#define L 0x4C
#define M 0x4D
#define R 0x52
#define VE 0x56
#define X 0x58
#define a 0x61
#define c 0x63
#define d 0x64
#define e 0x65
#define g 0x67
#define i 0x69
#define j 0x6A
#define l 0x6C
#define m 0x6D
#define n 0x6E
#define o 0x6F
#define p 0x70
#define r 0x72
#define t 0x74
#define v 0x76
#define x 0x78
void mensaje_encendido(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(B);
    lcd_letra(i);
    lcd_letra(e);
    lcd_letra(n);
    lcd_letra(v);
    lcd_letra(e);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(UNO);
    lcd_letra(GUION);
    lcd_letra(R);
    lcd_letra(M);
    lcd_letra(0x20);
    lcd_letra(DOS);
    lcd_letra(GUION);
    lcd_letra(L);
    lcd_letra(VE);
    lcd_letra(0x20);
    lcd_letra(TRES);
    lcd_letra(GUION);
    lcd_letra(E);
    lcd_letra(X);

    espera_init(1);
    espera(10);

}

void mensaje_apagado(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(A);
    lcd_letra(p);
    lcd_letra(a);
    lcd_letra(g);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(a);

    espera_init(1);
    espera(10);
}

void mensaje_alto(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(VE);
    lcd_letra(e);
    lcd_letra(l);
    lcd_letra(DOSPUNTOS);
    lcd_letra(0x20);
    lcd_letra(A);
    lcd_letra(l);
    lcd_letra(t);
    lcd_letra(a);

    espera_init(1);
    espera(5);
}

void mensaje_bajo(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(VE);
    lcd_letra(e);
    lcd_letra(l);
    lcd_letra(DOSPUNTOS);
    lcd_letra(0x20);
    lcd_letra(B);
    lcd_letra(a);
    lcd_letra(j);
    lcd_letra(a);

    espera_init(1);
    espera(5);
}

void mensaje_remojado(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(I);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(i);
    lcd_letra(a);
    lcd_letra(n);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(R);
    lcd_letra(e);
    lcd_letra(m);
    lcd_letra(o);
    lcd_letra(j);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);

    espera_init(1);
    espera(5);
}

void mensaje_lavado(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(I);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(i);
    lcd_letra(a);
    lcd_letra(n);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(L);
    lcd_letra(a);
    lcd_letra(v);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);

    espera_init(1);
    espera(5);
}

void mensaje_exprimido(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(I);
    lcd_letra(n);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(i);
    lcd_letra(a);
    lcd_letra(n);
    lcd_letra(d);
    lcd_letra(o);
    lcd_letra(DOSPUNTOS);

    lcd_comando(0xC0);
    lcd_letra(E);
    lcd_letra(x);
    lcd_letra(p);
    lcd_letra(r);
    lcd_letra(i);
    lcd_letra(m);
    lcd_letra(i);
    lcd_letra(d);
    lcd_letra(o);


    espera_init(1);
    espera(5);
}

void mensaje_final_ciclo(void){
    lcd_limpiar();
    lcd_letra(0x20);
    lcd_letra(0x20);
    lcd_letra(CE);
    lcd_letra(i);
    lcd_letra(c);
    lcd_letra(l);
    lcd_letra(o);
    lcd_letra(0x20);
    lcd_letra(t);
    lcd_letra(e);
    lcd_letra(r);
    lcd_letra(m);
    lcd_letra(i);
    lcd_letra(n);
    lcd_letra(a);
    lcd_letra(d);
    lcd_letra(o);

    espera_init(1);
    espera(5);
}



