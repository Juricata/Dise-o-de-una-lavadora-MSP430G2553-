#include <msp430.h>

#include "motor.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;

    motor_init();
    motor_derecha(512, 20);
    motor_izquierda(512,20);
    motor_derecha(512, 15);
    motor_izquierda(512,15);
    while (1) {
    }
}


