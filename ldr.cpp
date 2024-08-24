#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   pinMode(LDR_SENSOR, INPUT);   
}
void brightness_control(void)
{
  unsigned int adc_val;
 // To read values from LDR sensor
  adc_val = analogRead(LDR_SENSOR);

  //Scale it down 0 to 255 and reverse it 255 to 0
  adc_val = 255 - (adc_val / 4);
  // map(0, 1023, 255, 0) this bulit in function can also used

  analogWrite(GARDEN_LIGHT, adc_val);
  delay(100); 
}
