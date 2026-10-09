#include <msp430.h>
#include "segundos.h"
#include "motor.h"
#include "botones.h"
#include "LCD.h"
#include "mensajes.h"

volatile char sistema_encendido = 0; // 1 -> Encendido; 0 -> Apagado
volatile char velocidad_iniciada = 0; // 1-> Alto; 0 -> Bajo

// Banderas para cada ciclo
volatile char hacer_remojado = 0;
volatile char hacer_lavado = 0;
volatile char hacer_exprimido = 0;

unsigned int velocidad = 8; // Inicio en modo bajo
// bandera de pulso de botones
volatile char pulso2=0;
volatile char pulso3=0;


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    motor_init();
    botones_init();
    lcd_init();

    __bis_SR_register(GIE);

    while (1) {
        if (sistema_encendido &  pulso2) {
            pulso2=0;
            mensaje_encendido();
        } else if(!sistema_encendido & pulso2) {
            pulso2=0;
            mensaje_apagado();
            hacer_remojado = 0;
            hacer_lavado = 0;
            hacer_exprimido = 0;
        }
        if (sistema_encendido) {
            if (velocidad_iniciada & pulso3) {
                mensaje_alto();
                pulso3=0;
                velocidad = 8; // Velocidad alta
            } else if(!velocidad_iniciada & pulso3) {
                pulso3=0;
                mensaje_bajo();
                velocidad = 10; // Velocidad baja
            }
            if (hacer_remojado) {
                mensaje_remojado();
                hacer_remojado = 0;
                remojado(velocidad);
                mensaje_final_ciclo();
            }

            if (hacer_lavado) {
                hacer_lavado = 0;
                mensaje_lavado();
                lavado(velocidad);
                mensaje_final_ciclo();
            }

            if (hacer_exprimido) {
                hacer_exprimido = 0;
                mensaje_exprimido();
                exprimido(velocidad);
                mensaje_final_ciclo();
            }
        }

        __bis_SR_register(LPM0_bits);
    }
}

// Interrupciones de los botones (Puerto 1)
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {
    // Antirrebote básico por software y verificación de bandera
    if (P2IFG & BIT2) { // Botón ON/OFF (P1.0)
        sistema_encendido = !sistema_encendido;
        pulso2=1;
        P2IFG &= ~BIT2;
    }
    else{
        pulso2=0;
    }

    if (sistema_encendido) {
        if (P2IFG & BIT3) { // Botón de Velocidad (P1.1)
            velocidad_iniciada = !velocidad_iniciada;
            pulso3=1;
            P2IFG &= ~BIT3;
        }
        if (P2IFG & BIT4) { // Botón Remojado (P1.2)
            hacer_remojado = 1;
            P2IFG &= ~BIT4;
        }
        if (P2IFG & BIT5) { // Botón Lavado (P1.3)
            hacer_lavado = 1;
            P2IFG &= ~BIT5;
        }
        if (P2IFG & BIT7) { // Botón Exprimido (P1.4)
            hacer_exprimido = 1;
            P2IFG &= ~BIT7;
        }
    } else {
        P2IFG &= ~(BIT3 | BIT4 | BIT5 | BIT7);
        pulso3=0;

    }

    __bic_SR_register_on_exit(LPM0_bits);
}


