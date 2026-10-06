#include "botones.h"
/*
#define ONOFF BIT0
#define VEL BIT1
#define RM BIT2
#define LV BIT3
#define EX BIT4
*/
#define ONOFF BIT4
#define VEL BIT7
#define RM BIT4
#define LV BIT5
#define EX BIT6

void botones_init(void) {

    P1DIR &= ~(ONOFF | VEL);
    P1REN |= (ONOFF | VEL );
    P1OUT &= ~(ONOFF | VEL);
    P1IE  |= (ONOFF | VEL);
    P1IES |= (ONOFF | VEL );
    P1IFG &= ~(ONOFF | VEL );


    P2DIR &= ~(RM | LV | EX);
    P2REN |= (RM | LV | EX);
    P2OUT &= ~(RM | LV | EX);
    P2IES |= (RM | LV | EX);
    P2IFG &= ~(RM | LV | EX);
    P2IE  |= (RM | LV | EX);
    // Botones ON/OFF (P1.0) y Velocidad (P1.1)
  //registros- registros-registros
    /*
    P1DIR &= ~(ONOFF | VEL |RM | LV | EX);
    P1REN |= (ONOFF | VEL |RM | LV | EX);
    P1OUT &= ~(ONOFF | VEL |RM | LV | EX);
    P1IES |= (ONOFF | VEL |RM | LV | EX);
    P1IFG &= ~(ONOFF | VEL |RM | LV | EX);
    P1IE  |= (ONOFF | VEL |RM | LV | EX);
    */

    // Botones Remojado (P1.2), Lavado (P1.3) y Exprimido (P1.4)
}
