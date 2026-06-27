#include <Arduino.h>

const int redLedPin = 9;
const int greenLedPin = 5;
const int photoPin = A0;

const unsigned long openTime = 5000;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  
  Serial.println("Система запущена. Дверь закрыта.");
}

void loop() {
  int sensorValue = analogRead(photoPin);
  if (sensorValue > 512) {

    Serial.println("Дверь открыта");
    
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);

    delay(openTime);

    sensorValue = analogRead(photoPin);
      
    while (sensorValue > 512) {
      Serial.println("Дверь всё ещё открыта");
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      delay(2000);
      sensorValue = analogRead(photoPin);
    }
    Serial.println("Дверь закрыта");
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }
  delay(100);
}