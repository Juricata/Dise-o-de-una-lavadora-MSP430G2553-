#include "botones.h"
#define ONOFF BIT0
#define VEL BIT1
#define RM BIT2
#define LV BIT3
#define EX BIT4
void botones_init(void) {
    // Botones ON/OFF (P1.0) y Velocidad (P1.1)
  //registros- registros-registros
    P1DIR &= ~(ONOFF | VEL |RM | LV | EX);
    P1REN |= (ONOFF | VEL |RM | LV | EX);
    P1OUT &= ~(ONOFF | VEL |RM | LV | EX);
    P1IES |= (ONOFF | VEL |RM | LV | EX);
    P1IFG &= ~(ONOFF | VEL |RM | LV | EX);
    P1IE  |= (ONOFF | VEL |RM | LV | EX);

    // Botones Remojado (P1.2), Lavado (P1.3) y Exprimido (P1.4)
}
