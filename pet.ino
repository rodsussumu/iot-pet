#include <Servo.h>

#define PIR 7
#define SERVO 9
#define INTERVAL 1000

Servo servo;

int pos;
int movimento = 0;

void setup() {
  pinMode(PIR, INPUT);
  servo.attach(SERVO);
  servo.write(180);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIR) == HIGH) {
    Serial.println("Alimenta.");

    for (pos = 180; pos >= 0; pos--) {
      servo.write(pos);
      delay(15);
    }

    delay(300);

    for (pos = 0; pos < 180; pos++) {
      servo.write(pos);
      delay(15);
    }
  }
  else {
    Serial.println("Nenhuma presença detectada");
  }
  delay(1000);
}