#include <msp430.h>

/* Funcionamiento:
 *
 * Libreria para funciones de espera
 * antes de usar funcion espera() se debe iniciar init_espera al inicio del programa y elegir configuracion:
 * 0-> espera en el orden de 50 microsegundos (espera(1)=~50us)
 * x-> espera en milisegundos (espera(1)=~1ms)
 * 1-> espera en segundos (espera(1)=~1s)
 *
 * por el momento solo es posible elegir un solo modo, volver a inicializar con init para cambiar a otro rango
 */

volatile unsigned int tiempo=0;

void espera_init(int modo)    // 0-> us 1->s default -> ms
{

    switch(modo){
    case 1:
        // TASSEL_2 : Fuente del reloj SMCLK (aprox. 1Mhz por defecto)
        // ID_3 : Divisor de frecuencia /8 (reloj del timer =~125 Khz)
        // MC_3 : Modo "Updown" (cuenta de 0 hasta TACCR0 mitad de frecuencia)
        // TACLR : Limpiar el contador del timer

        TA0CTL = TASSEL_2 | ID_3 | MC_3 |TAIE| TACLR;

        // Establecer el valor limite de conteo: (2*TACCRO)/F
        // Frecuencia = 125000 hz. con 62500 ciclos logramos en modo updown ~1 segundo por ciclo

        TA0CCR0 = 62500-1;
        break;
    case 0:
        // TASSEL_2 : Fuente del reloj SMCLK (aprox. 1Mhz por defecto)
        // ID_0 : Sin division de frecuencia
        // MC_1 : Modo "Up" (cuenta de 0 hasta TACCR0)
        // TACLR : Limpiar el contador del timer

        TA0CTL = TASSEL_2 | ID_0 | MC_1 |TAIE| TACLR;

        // Establecer el valor limite de conteo
        // Frecuencia = 1M hz. con 50 ciclos logramos ~50 microsegundos por ciclo

        TA0CCR0 = 50-1;
        break;
    default:
        // TASSEL_2 : Fuente del reloj SMCLK (aprox. 1Mhz por defecto)
        // ID_3 : Divisor de frecuencia /8 (reloj del timer =~125 Khz)
        // MC_1 : Modo "Up" (cuenta de 0 hasta TACCR0)
        // TACLR : Limpiar el contador del timer

        TA0CTL = TASSEL_2 | ID_3 | MC_1 |TAIE| TACLR;

        // Establecer el valor limite de conteo
        // Frecuencia = 125000 hz. con 125 ciclos logramos ~1 milisegundos por ciclo

        TA0CCR0 = 125-1;
        break;
    }

    //enable interrup // habilita interrupciones globales
    __bis_SR_register(GIE);
}
void espera(unsigned int segundos){
    tiempo=0;
    while(tiempo<segundos){
        __bis_SR_register(LPM0_bits);
    }
}

    //vector de interrupcion para la bandera del timer A (TA0IV / TAIFG)
#pragma vector = TIMER0_A1_VECTOR
__interrupt void Timer_A0_ISR(void){
    switch(__even_in_range(TA0IV,14)){
        case TA0IV_TAIFG:   // caso en que se produce el desbordamiento/limite
            tiempo++;
            __bic_SR_register_on_exit(LPM0_bits);
            break;
        default:
            break;
    }
}


