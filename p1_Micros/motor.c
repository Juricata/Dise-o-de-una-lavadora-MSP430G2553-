#include "motor.h"
#include "lcd.h" 

//secuencia de 4 estados
static const unsigned char seq[4] = {BIT0, BIT1, BIT2, BIT3};

//start pines del motor
void motor_init(void) {
    M_DIR |= M_MASK;   //P2.0 - P2.3 = salidas
    M_OUT &= ~M_MASK;  //apaga las fases del motor (inicio)
}

//mvimiento derecha
void motor_derecha(unsigned int pasos, unsigned int vel) {
    static unsigned char i = 0;
    unsigned int p;

    for (p = 0; p < pasos; p++) {
        M_OUT = (M_OUT & ~M_MASK) | seq[i];
        i = (i + 1) % 4;
        esperar(vel); 
    }
}

