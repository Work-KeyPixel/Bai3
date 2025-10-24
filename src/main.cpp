#include <Arduino.h>

#define PIN_LDR 36
#define PIN_LED 5

const long BAUD = 115200;

void setup() {
  Serial.begin(BAUD);
  while (!Serial) delay(10);

  analogReadResolution(12);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  Serial.println("=== LDR SENSOR MONITOR ===");
  Serial.println(">label:light");
}

void loop() {
  int light = analogRead(PIN_LDR);
  Serial.printf(">light:%d\n", light);

  digitalWrite(PIN_LED, light >= 1500 ? HIGH : LOW);
  delay(200);
}