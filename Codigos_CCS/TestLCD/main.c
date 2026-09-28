#include <msp430.h> 
#include "lcd.h"

#define J 0x4A
#define u 0x75
#define l 0x6C
#define i 0x69
#define a 0x61

/**
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    int corazon1[8] = {
                     0b00000001,
                     0b00000110,
                     0b00001110,
                     0b00011100,
                     0b00011100,
                     0b00001110,
                     0b00000110,
                     0b00000001,
    };

    int corazon2[8] = {
                         0b00000100,
                         0b00001110,
                         0b00011111,
                         0b00011111,
                         0b00011110,
                         0b00011100,
                         0b00010000,
                         0b00000000,
        };

    lcd_init();
    lcd_letra(J);
    lcd_letra(u);
    lcd_letra(l);
    lcd_letra(i);
    lcd_letra(a);
    lcd_nuevosim(0x40,corazon1);
    lcd_comando(0x86);
    lcd_letra(0x00);
    lcd_nuevosim(0x48,corazon2);
    lcd_comando(0x87);
    lcd_letra(0x01);

    while(1){

    }

}
