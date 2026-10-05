/*
 * LCD.h
 *
 *  Created on: 28/09/2026
 *      Authors: Julia Elizabeth Cuesta Quezada
 *               Dania Guadalupe Rosales Trujillo
 */

#ifndef LCD_H
#define LCD_H

void lcd_comando(int comando);
void lcd_init(void);
void lcd_letra(int letra);
void lcd_limpiar(void);
void lcd_nuevosim(int posicioncgram, int *fila);

#endif
