#include <msp430.h>
#include "segundos.h"
#include "motor.h"
#include "botones.h"
#include "LCD.h"
#include "mensajes.h"

#define J 0x4A
#define u 0x75
#define l 0x6C
#define i 0x69
#define a 0x61

/**
 * main.c
 */
//char solo usa 1 byte, ahorro de memoria para usar banderas con 1 bit
volatile char sistema_encendido = 1; // 1 -> Encendido; 0 -> Apagado
volatile char velocidad_iniciada = 0; // 1-> Alto; 0 -> Bajo
// Banderas para cada ciclo
volatile char hacer_remojado = 1; // 1 -> Encendido; 0 -> Apagado
volatile char hacer_lavado = 1; // 1 -> Encendido; 0 -> Apagado
volatile char hacer_exprimido = 1; // 1 -> Encendido; 0 -> Apagado

unsigned int velocidad = 15; // Inicio en modo bajo

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //se inician los perifericos
    motor_init();   // De la libreria motor -> Funcion para configuracion de salidas del motor
    botones_init(); // De la libreria botones -> Funcion de configuracion de botones GPIO de entrada en modo Pull down
    lcd_init(); // De la libreria LCD-> Funcion para configuracion y prendido inicial de LCD

    __bis_SR_register(GIE); //se comienzan las interrupciones

    while (1) {

        // se espera hasta que se precione un boton en el circuito
        /*if(velocidad_iniciada){
            mensaje_alto();
        }else{
            mensaje_bajo();
        }
        espera(1);
        if (hacer_remojado){    // Prueba en el ciclo remojado
            hacer_remojado = 0;
            mensaje_remojado();
            remojado(velocidad);
            mensaje_final_ciclo();
        }
        espera(1);
        if (hacer_lavado){  // Prueba en el ciclo lavado
            hacer_lavado = 0;
            mensaje_lavado();
            lavado(velocidad);
            mensaje_final_ciclo();
        }
        espera(1);
        if (hacer_exprimido){   // Prueba en el ciclo exprimido
            hacer_exprimido = 0;
            mensaje_exprimido();
            exprimido(velocidad);
            mensaje_final_ciclo();
        }
*/
        __bis_SR_register(LPM0_bits);


    }
}

// interrupciones de los botones

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) {
    if (P1IFG && BIT4) {
        sistema_encendido = !sistema_encendido;
        P1IFG &= ~BIT4;
    }
    if(sistema_encendido && BIT4){
        mensaje_encendido();
    }else{
        mensaje_apagado();
        P1IFG &= ~(BIT1 | BIT2 | BIT3 | BIT4);
    }
    if (P1IFG && BIT7) {
        velocidad_iniciada = !velocidad_iniciada;
        P1IFG &= ~BIT7;
    }
    if(velocidad_iniciada){
        mensaje_alto();
        velocidad=11;//EX-> 8s
    }else{
        mensaje_bajo();
        velocidad=15;//EX-> 12s
    }
    /*
    if (sistema_encendido) {

        if (P1IFG & BIT1) {
            velocidad_iniciada = !velocidad_iniciada;
            P1IFG &= ~BIT1;

            if(velocidad_iniciada){
                velocidad=11;//EX-> 8s
            }else{
                velocidad=15;//EX-> 12s
            }
        }
        if (P1IFG & BIT2) {
            hacer_remojado = 1;
            P1IFG &= ~BIT2;
        }
        if (P1IFG & BIT3) {
            hacer_lavado = 1;
            P1IFG &= ~BIT3;
        }
        if (P1IFG & BIT4) {
            hacer_exprimido = 1;
            P1IFG &= ~BIT4;
        }
    } else {
    }
    */
    __bic_SR_register_on_exit(LPM0_bits);
}

