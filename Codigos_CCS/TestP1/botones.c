#include "botones.h"

void botones_init(void) {
    // Botones ON/OFF (P1.0) y Velocidad (P1.1)
  //registros- registros-registros
    P1DIR &= ~(BIT0 | BIT1 |BIT2 | BIT3 | BIT4);
    P1REN |= (BIT0 | BIT1 |BIT2 | BIT3 | BIT4);
    P1OUT &= ~(BIT0 | BIT1 |BIT2 | BIT3 | BIT4);
    P1IES &= ~(BIT0 | BIT1 |BIT2 | BIT3 | BIT4);
    P1IFG &= ~(BIT0 | BIT1 |BIT2 | BIT3 | BIT4);
    P1IE  |= (BIT0 | BIT1 |BIT2 | BIT3 | BIT4);

    // Botones Remojado (P1.2), Lavado (P1.3) y Exprimido (P1.4)
}
