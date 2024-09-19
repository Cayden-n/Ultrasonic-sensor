#include <NewPing.h>
#include <LiquidCrystal.h>

const int LED = 12;
const int rs = 2,
          en = 3,
          d4 = 6,
          d5 = 7,
          d6 = 8,
          d7 = 9;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(LED, OUTPUT);
}

void loop(){
  int uS = sonar.ping();
  lcd.setCursor(0,0); 
  lcd.print("Ping: ");
  lcd.print(uS/US_ROUNDTRIP_CM);
  lcd.print("cm");
  if (uS/US_ROUNDTRIP_CM <= 10){
    digitalWrite(LED, HIGH);
  }
  else {
     digitalWrite(LED, LOW);
  }
  delay(500);
  lcd.clear();
}
