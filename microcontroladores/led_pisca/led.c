#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

#define LED PIN_d1
#define DELAY 1000



void main()
{

   //Example blinking LED program
   while(true)
   {
      output_toggle(LED);
      delay_ms(DELAY);
   }

}
