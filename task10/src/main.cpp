#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int currentAngle = 90;

void setup() {
  myservo.attach(3);
  myservo.write(currentAngle);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');
    inputString.trim();
    int targetAngle = inputString.toInt();
    if (targetAngle >= 0 && targetAngle <= 180) {
      if (targetAngle != currentAngle) {
        if (currentAngle < targetAngle) {
          for (int angle = currentAngle; angle <= targetAngle; angle++) {
            myservo.write(angle);
            delay(15);
          }
        } else {
          for (int angle = currentAngle; angle >= targetAngle; angle--) {
            myservo.write(angle);
            delay(15);
          }
        }
        currentAngle = targetAngle;
        Serial.print("Угол успешно установлен: ");
        Serial.println(currentAngle);
      } else {
        Serial.println("Сервопривод уже находится в этом положении");
      }
    } else {
      Serial.println("Ошибка: введите значение от 0 до 180 градусов");
    }
  }
}