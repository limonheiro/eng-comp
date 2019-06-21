#include "OneWire.h"
#include "DallasTemperature.h"
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

#define buttonUP 12
#define buttonDown 14
#define portrele 23

OneWire oneWire(19);
DallasTemperature tempSensor(&oneWire);
int valor_inicial = 2;
long setpoint = 0;

void setup(void)
{
  Wire.begin();
  oled.init();
  oled.clearDisplay();
  Serial.begin(115200);
  tempSensor.begin();
  pinMode(buttonUP, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(portrele, OUTPUT);
  oled.setTextXY(0, 0);             // Set cursor position, start of line 0
  oled.putString("Carregando...");
  while (valor_inicial--) {
    tempSensor.requestTemperaturesByIndex(0);
    setpoint = tempSensor.getTempCByIndex(0);
  }
  oled.clearDisplay();
}

void draw(float temp) {

  oled.setTextXY(0, 0);             // Set cursor position, start of line 0
  oled.putString("Temp:");
  oled.setTextXY(0, 7);
  oled.putFloat(temp, 2);
  oled.setTextXY(0, 13);
  oled.putString("C");

  oled.setTextXY(1, 0);
  oled.putString("Set: ");
  oled.setTextXY(1, 7);
  oled.putFloat(setpoint, 2);
  oled.setTextXY(1, 13);
  oled.putString("C");
}
void loop(void)
{

  tempSensor.requestTemperaturesByIndex(0);
  float temp = tempSensor.getTempCByIndex(0);
  Serial.println(temp);

  if (digitalRead(buttonUP)) {
    setpoint++;
  }
  if (digitalRead(buttonDown)) {
    setpoint--;
  }
  draw(temp);
  long atual = (long)temp;
  if (atual < setpoint)
    digitalWrite(portrele, HIGH);
  else
    digitalWrite(portrele, LOW);
}
