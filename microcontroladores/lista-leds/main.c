#include <main.h>

//#include <math.h>

#define n1 pin_b7
#define n2 pin_b6
#define n3 pin_b5
#define n4 pin_b4
#define n5 pin_b3
#define n6 pin_b2
#define n7 pin_b1
#define n8 pin_b0
#define n9 pin_d7
#define n10 pin_d6

void main(){
char leds[]={n1,n2,n3,n4,n5,n6,n7,n8,n9,n10};
   setup_adc_ports(AN0);
   int i;
   while(TRUE)
   {
      for(i=0;i<10;i++){
        output_high(leds[i]);
      }
      for(i=0;i<10;i++){
        output_low(leds[i]);
      }
   }

}
