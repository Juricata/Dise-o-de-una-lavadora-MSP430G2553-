#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR |=BIT0;
    P1OUT &= ~BIT0;

    // Configuracion del Timer_A0
    // TASSEL_2 : Fuente del reloj SMCLK (aprox. 1Mhz por defecto)
    // ID_3 : Divisor de frecuencia /8 (reloj del timer =~125 Khz)
    // MC_3 : Modo "Updown" (cuenta de 0 hasta TACCR0 mitad de frecuencia)
    // TACLR : Limpiar el contador del timer

    TA0CTL = TASSEL_2 | ID_3 | MC_3 |TAIE| TACLR;

    // Establecer el valor limite de conteo: (2*TACCRO)/F
    // Frecuencia = 125000 hz. con 62500 ciclos logramos en modo updown ~1 segundo por ciclo

    TA0CCR0 = 62500-1;

    //enable interrup // habilita interrupciones globales
    __bis_SR_register(GIE);
    while(1){
        __bis_SR_register(LPM0_bits);
    }
}
    //vector de interrupcion para la bandera del timer A (TA0IV / TAIFG)
#pragma vector = TIMER0_A1_VECTOR
__interrupt void Timer_A0_ISR(void){
    switch(__even_in_range(TA0IV,14)){
        case TA0IV_TAIFG:   // caso en que se produce el desbordamiento/limite
            P1OUT^=BIT0;
            break;
        default:
            break;
    }
}

