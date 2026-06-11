//Name : Varun Kumar
//roll no. 2417027

#include <LiquidCrystal.h>

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 10, 9, 6, 5);

const int seatSwitch = 2;
const int beltSwitch = 3;
const int buzzer = 7;
const int redLED = 8;

void setup() {
  pinMode(seatSwitch, INPUT_PULLUP);
  pinMode(beltSwitch, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  pinMode(redLED, OUTPUT);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Seat Belt");
  lcd.setCursor(0, 1);
  lcd.print("Warning Sys");

  delay(2000);
  lcd.clear();
}

void loop() {

  bool seatOccupied = digitalRead(seatSwitch) == LOW;
  bool beltFastened = digitalRead(beltSwitch) == LOW;

  if (!seatOccupied) {

    digitalWrite(redLED, LOW);
    noTone(buzzer);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Seat Empty");
    lcd.setCursor(0, 1);
    lcd.print("Waiting...");
  }

  else if (seatOccupied && !beltFastened) {

    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WARNING!");
    lcd.setCursor(0, 1);
    lcd.print("Fasten Belt");
  }

  else {

    digitalWrite(redLED, LOW);
    noTone(buzzer);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Seat Occupied");
    lcd.setCursor(0, 1);
    lcd.print("Belt Fastened");
  }

  delay(500);
}