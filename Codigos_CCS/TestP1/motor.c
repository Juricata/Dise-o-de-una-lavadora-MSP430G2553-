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
void remojado(void) {
    motor_derecha(512, 20); // 2 vueltas a la derecha
    espera_init(2);
    espera(300);            // Timer
    motor_izquierda(512, 20); // 2 vueltas a la izquierda
}

void lavado(void) {
    motor_derecha(768, 20); // 3 vueltas a la derecha
    espera_init(2);
    espera(300);
    motor_izquierda(768, 20); // 3 vueltas a la izquierda
}

void exprimido(void) {
    motor_derecha(256, 15);  // 1v rapida
    espera_init(2);
    espera(200);
    motor_izquierda(256, 15);  // 1v rapida
}
