#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

#define PIN_DS18B20_DATA PIN_B1
#include <ds18b20.c>
signed int16 raw_temp;
float temp;

void main()
{

 while(TRUE) {
    if(ds18b20_read(&raw_temp)) {
      temp = (float)raw_temp / 16;               // Convert temperature raw value into degree Celsius (temp in �C = raw/16)             // Go to column 5 row 2
      printf("%f\n", temp);
    }
    else {
      printf(" Error! ");
    }
    delay_ms(5);                              // Wait 1 second
  }

}
