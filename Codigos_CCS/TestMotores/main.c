#include <msp430.h>

#include "motor.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;

    motor_init();
    motor_derecha(400, 10);
    while (1) {
    }
}


