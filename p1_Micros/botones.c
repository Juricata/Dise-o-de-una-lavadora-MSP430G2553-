#include "botones.h"

void botones_init(void) {
    // Botones ON/OFF (P1.6) y Velocidad (P1.7)
  //registros- registros-registros
    P1DIR &= ~(BIT6 | BIT7);
    P1REN |= (BIT6 | BIT7);
    P1OUT &= ~(BIT6 | BIT7);
    P1IES &= ~(BIT6 | BIT7);
    P1IFG &= ~(BIT6 | BIT7);
    P1IE  |= (BIT6 | BIT7);

    // Botones Remojado (P2.4), Lavado (P2.5) y Exprimido (P2.6)
    P2DIR &= ~(BIT4 | BIT5 | BIT6);
    P2REN |= (BIT4 | BIT5 | BIT6);
    P2OUT &= ~(BIT4 | BIT5 | BIT6);
    P2IES &= ~(BIT4 | BIT5 | BIT6);
    P2IFG &= ~(BIT4 | BIT5 | BIT6);
    P2IE  |= (BIT4 | BIT5 | BIT6);
}
