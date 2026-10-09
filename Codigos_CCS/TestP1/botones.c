#include "botones.h"
#define ONOFF BIT2
#define VEL BIT3
#define RM BIT4
#define LV BIT5
#define EX BIT7
void botones_init(void) {
    // Botones ON/OFF (P1.0) y Velocidad (P1.1)
  //registros- registros-registros
    P2DIR &= ~(ONOFF | VEL |RM | LV | EX);
    P2REN |= (ONOFF | VEL |RM | LV | EX);
    P2OUT |= (ONOFF | VEL |RM | LV | EX);
    P2IES |= (ONOFF | VEL |RM | LV | EX);
    P2IFG &= ~(ONOFF | VEL |RM | LV | EX);
    P2IE  |= (ONOFF | VEL |RM | LV | EX);


    // Botones Remojado (P1.2), Lavado (P1.3) y Exprimido (P1.4)
}
