#include <LCD.h>
#include "mod_lcd.h"

void main()
{
   
   lcd_ini();
   while(TRUE)
   {
   //limpa_lcd();            //Limpa o display do LCD
        lcd_pos_xy(2,6);
        printf(lcd_escreve,"                ");
        delay_ms(500);
        lcd_pos_xy(1,4);   //Define o caracter de inicio da escrita
        printf(lcd_escreve,"FILIPEFLOP");  //Escreve no LCD
        delay_ms(2000);
                
        lcd_pos_xy(1,4);
        printf(lcd_escreve,"           ");
        delay_ms(500);
        lcd_pos_xy(2,6);
        printf(lcd_escreve,"P I C");
        delay_ms(2000); 
   }

}
