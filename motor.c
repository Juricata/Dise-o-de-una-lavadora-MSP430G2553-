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
// movimiento izquierda
void motor_izquierda(unsigned int pasos, unsigned int vel) {
    static unsigned char i = 0;
    unsigned int p;

    for (p = 0; p < pasos; p++) {
        M_OUT = (M_OUT & ~M_MASK) | seq[i];
        i = (i == 0) ? 3 : i - 1;
        esperar(vel);
    }
}

//ciclos

void remojado(void) {
    motor_derecha(400, 10); // 2 vueltas der (200 pasos * 2)
    esperar(300);
    motor_izquierda(400, 10); // 2 vueltas izq
}

void lavado(void) {
    motor_derecha(600, 10); // 3 vueltas der (200 pasos * 3)
    esperar(300);
    motor_izquierda(600, 10); // 3 vueltas izq
}

void exprimido(void) {
    motor_derecha(200, 4);  // 1 vuelta der 
    esperar(200);
    motor_izquierda(200, 4);  // 1 vuelta izq
}