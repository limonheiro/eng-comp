#include <motorCC.h>

void main()
{
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)512);

   int16 value;
   
   while(TRUE)
   {
      value = read_adc();
      delay_us(50);
      set_pwm1_duty(value);
      delay_ms((int16)50);
   }

}
