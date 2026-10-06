#ifndef MOTOR_H_
#define MOTOR_H_

#include <msp430.h>
#include "segundos.h"

//puertos 
//P2.0
//P2.1 
//P2.2
//P2.3
/*
#define M_DIR   P2DIR
#define M_OUT   P2OUT
#define M_MASK  (BIT2 | BIT3 | BIT4 | BIT5)
*/

#define M_DIR   P1DIR
#define M_OUT   P1OUT
#define M_MASK  (BIT0 | BIT1 | BIT2 | BIT3)
//funciones
void motor_init(void);
void motor_derecha(unsigned int pasos, unsigned int vel);
void motor_izquierda(unsigned int pasos, unsigned int vel);

// Ciclos de la lavadora
void remojado(unsigned int vel);
void lavado(unsigned int vel);
void exprimido(unsigned int vel);

#endif
