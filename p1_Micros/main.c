#include <msp430.h>
#include "segundos.h"
#include "motor.h"
#include "botones.h"
//codigo padre en donde se ejecutan todas las funciones, librerias antes creadas
//solamnete el motor todavia no la lcd
volatile int sistema_encendido = 1; // Lo dejamos en 1 para probar directo sin presionar ON

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;

    //comienza el Timer en milisegundos
    espera_init(2);

    //se inician los perifericos
    //**prueba solo del motr no esta la LCD
    motor_init();
    botones_init();

    __enable_interrupt(); //se comienzan las interrupciones

    while (1) {
        // se espera hasta que se precione un boton en el circuito
    }
}

// interrupciones en los puerto  para ON/OFF Y Velocidades
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void) {
    if (P1IFG & BIT6) {
        sistema_encendido = !sistema_encendido;
        P1IFG &= ~BIT6;
    }
    if (P1IFG & BIT7) {
        P1IFG &= ~BIT7;
    }
}

// interrupciones P2 Lavado
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void) {
    if (sistema_encendido) {
        if (P2IFG & BIT4) {
            remojado(); // Prueba en el ciclo remojado
            P2IFG &= ~BIT4;
        }
        if (P2IFG & BIT5) {
            lavado();   // Prueba el ciclo de lavado
            P2IFG &= ~BIT5;
        }
        if (P2IFG & BIT6) {
            exprimido(); // Prueba el ciclo de exprimido
            P2IFG &= ~BIT6;
        }
    } else {
        P2IFG &= ~(BIT4 | BIT5 | BIT6);
    }
}
