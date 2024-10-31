#include "max6675.h"
#include <Adafruit_Sensor.h>

#define BUTTON_PIN 34 
#define BOIA_1 34
#define BOIA_2 35 
#define BOIA_3 13
#define BOIA_4 12

int thermoDO1 = 19;
int thermoCS1 = 23;
int thermoCLK1 = 5;
MAX6675 thermocouple1(thermoCLK1, thermoCS1, thermoDO1);

int thermoDO2 = 33;
int thermoCS2 = 25;
int thermoCLK2 = 26;
MAX6675 thermocouple2(thermoCLK2, thermoDO2, thermoCS2);

unsigned long previousMillis = 0;
int interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BOIA_1, INPUT);
  pinMode(BOIA_2, INPUT);
  pinMode(BOIA_3, INPUT);
  pinMode(BOIA_4, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int boia_1 = digitalRead(BOIA_1);
    int boia_2 = digitalRead(BOIA_2);
    int boia_3 = digitalRead(BOIA_3);
    int boia_4 = digitalRead(BOIA_4);
    float tpar1 = thermocouple1.readCelsius();
    float tpar2 = thermocouple2.readCelsius();

    Serial.print("Boia 1: "); Serial.println(boia_1);
    Serial.print("Boia 2: "); Serial.println(boia_2);
    Serial.print("Boia 3: "); Serial.println(boia_3);
    Serial.print("Boia 4: "); Serial.println(boia_4);
    Serial.print("Temperatura Termopar 1: "); Serial.print(tpar1); Serial.println(" C");
    Serial.print("Temperatura Termopar 2: "); Serial.print(tpar2); Serial.println(" C");
    Serial.println("--------------------------------");
  }
}
