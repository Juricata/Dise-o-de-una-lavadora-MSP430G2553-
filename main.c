#include <msp430.h>
#include "motor.h"
#include "lcd.h"

int main(void) {
   
    WDTCTL = WDTPW | WDTHOLD;

    
    lcd_init();   // Inicializa la pantalla
    motor_init(); //pines P2.0 - P2.3 como salidas

    // 3. Bucle principal
    while(1) {
        
        remojado();
        esperar(1000);

        lavado();
        esperar(1000);

        exprimido();
        esperar(2000);
    }
}