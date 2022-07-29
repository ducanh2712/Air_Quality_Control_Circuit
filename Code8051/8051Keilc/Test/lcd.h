#ifndef _LCD_H_
#define _LCD_H_

void LCD_Command (unsigned char cmd);
void LCD_Char (unsigned char char_data);
void LCD_String (unsigned char *str) ;
void LCD_String_xy (char row, char pos, char *str);
void LCD_Init (void);

#endif