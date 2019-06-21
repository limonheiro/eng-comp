#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

#INT_RTCC
void  RTCC_isr(void) 
{

}

#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_ENABLE_PIN PIN_D3
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7

#include <LCD.C>
//#include <lcd.c>

void main()
{
   char k;

   setup_adc_ports(AN0);
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)510);
   lcd_init();

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   lcd_init();
   
   
   lcd_putc("\fMotor 1:  \n");

   //lcd_putc("\fReady...\n");

   while(TRUE)
   {
      k = "1\0";
      //k = kbd_getc();
      if(k!=0)
         if(k=='*')
            lcd_putc('\f');
         else
            lcd_putc(k);

      //TODO: User Code
   }

}
