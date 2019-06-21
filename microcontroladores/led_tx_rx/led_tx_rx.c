#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20MHz)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)


#define button pin_b0
#define led pin_b1

void main()
{
   char letra;

   while(TRUE)
   {
      if(input(button)){
         printf("a");
         delay_ms(5);
      }
      if(kbhit())
      {
         letra=getc();
         if(letra=='a'){
            output_toggle(led);
            delay_ms(5);
         }
      }
   }
}
