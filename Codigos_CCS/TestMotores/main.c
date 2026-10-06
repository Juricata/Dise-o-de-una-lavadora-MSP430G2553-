#include <msp430.h>

#include "motor.h"
#include "segundos.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;
    P2DIR=BIT2|BIT3|BIT4|BIT5;

    P2OUT=0X00;
    espera_init(2);
    while (1) {
        P2OUT=BIT2|BIT3;
        espera(6);

        P2OUT=BIT3|BIT4;
        espera(6);


        P2OUT=BIT4|BIT5;
        espera(6);


        P2OUT=BIT5|BIT2;
        espera(6);


    }
}


