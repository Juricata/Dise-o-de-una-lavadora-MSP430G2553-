#include "motor.h"
#include "segundos.h"

//secuencia de 4 estados
static const unsigned char seq[4] = {BIT4, BIT5, BIT6, BIT7};

//start pines del motor
void motor_init(void) {
    M_DIR |= M_MASK;   //P2.4 - P2.7 = salidas
    M_OUT &= ~M_MASK;  //apaga las fases del motor (inicio)
}
static unsigned char i = 0;
//mvimiento derecha
void motor_derecha(unsigned int pasos, unsigned int vel) {

    unsigned int p;
  espera_init(2);   //milisegundos
  for (p = 0; p < pasos; p++) {
        M_OUT = (M_OUT & ~M_MASK) | seq[i];
        i = (i + 1) % 4;
        espera(vel); //TIMER
    }
}
//izq
void motor_izquierda(unsigned int pasos, unsigned int vel) {

    unsigned int p;
    espera_init(2);
    for (p = 0; p < pasos; p++) {
        M_OUT = (M_OUT & ~M_MASK) | seq[i];
        i = (i == 0) ? 3 : i -1;
        espera(vel); // TIMER
    }
}
//ciclos de lavadora 
void remojado(unsigned int vel) {
    motor_derecha(512, vel); // 2 vueltas a la derecha
    espera_init(2);
    espera(300);            // Timer
    motor_izquierda(512, vel); // 2 vueltas a la izquierda
}

void lavado(unsigned int vel) {
    motor_derecha(768, vel); // 3 vueltas a la derecha
    espera_init(2);
    espera(300);
    motor_izquierda(768, vel); // 3 vueltas a la izquierda
}

void exprimido(unsigned int vel) {
    motor_derecha(256, (vel-5));  // 1v rapida
    espera_init(2);
    espera(200);
    motor_izquierda(256, (vel-5));  // 1v rapida
}
