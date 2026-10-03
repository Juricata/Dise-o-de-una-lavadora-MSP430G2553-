#ifndef MOTOR_H_
#define MOTOR_H_

#include <msp430.h>
#include "segundos.h"

//puertos 
//P2.0
//P2.1 
//P2.2
//P2.3

#define M_DIR   P2DIR
#define M_OUT   P2OUT
#define M_MASK  (BIT4 | BIT5 | BIT7 | BIT6)

//funciones
void motor_init(void);
void motor_derecha(unsigned int pasos, unsigned int vel);
void motor_izquierda(unsigned int pasos, unsigned int vel);

// Ciclos de la lavadora
void remojado(void);
void lavado(void);
void exprimido(void);

#endif
