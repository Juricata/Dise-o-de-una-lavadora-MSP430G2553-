#include "motor.h"
#include "segundos.h"

//start pines del motor
void motor_init(void) {
    M_DIR |= M_MASK;   //P2.4 - P2.7 = salidas
    M_OUT &= ~M_MASK;  //apaga las fases del motor (inicio)
}
//mvimiento derecha
void motor_derecha(unsigned int pasos, unsigned int vel) {
    int p;
    espera_init(2);
    for(p=0;p<pasos;p++){
           P1OUT=BIT0|BIT1;
           espera(vel);
           P1OUT=BIT1|BIT2;
           espera(vel);
           P1OUT=BIT2|BIT3;
           espera(vel);
           P1OUT=BIT3|BIT0;
           espera(vel);
    }
}
//izq
void motor_izquierda(unsigned int pasos, unsigned int vel) {
    int p;
    espera_init(2);
    for(p=0;p<pasos;p++){
              P1OUT=BIT0|BIT3;
              espera(vel);
              P1OUT=BIT3|BIT2;
              espera(vel);
              P1OUT=BIT2|BIT1;
              espera(vel);
              P1OUT=BIT1|BIT0;
              espera(vel);
    }
}
//ciclos de lavadora 
void remojado(unsigned int vel) {
    motor_derecha(1024, vel); // 2 vueltas a la derecha
    espera_init(2);
    espera(300);            // Timer
    motor_izquierda(1024, vel); // 2 vueltas a la izquierda
}

void lavado(unsigned int vel) {
    motor_derecha(1536, vel); // 3 vueltas a la derecha
    espera_init(2);
    espera(300);
    motor_izquierda(1536, vel); // 3 vueltas a la izquierda
}

void exprimido(unsigned int vel) {
    motor_derecha(512, (vel-3));  // 1v rapida
    espera_init(2);
    espera(200);
    motor_izquierda(512, (vel-3));  // 1v rapida
}
