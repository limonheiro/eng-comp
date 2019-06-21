#include <12F675.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset

#use delay(internal=4MHz)
#use rs232(baud=9600,parity=N,xmit=PIN_A1,rcv=PIN_A2,bits=8,stream=PORT1)
int16 pulso;

void main()
{
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_adc( ADC_CLOCK_INTERNAL ); 

   while(TRUE)
   {
      pulso = read_adc();
      fprintf(PORT1, "%lu\n\r",pulso);
   }

}
