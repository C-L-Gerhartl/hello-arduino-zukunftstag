#include <Arduino.h>


/* Konstanten */
const int LEDBLUE_PIN = 9;      // Das Wort „LEDBLUE_PIN“ steht jetzt für den Wert 9 (blaue LEDs sind an PIN 9 angschlossen)
const int LEDGREEN_PIN = 10;    // Das Wort „LEDGREEn_PIN“ steht jetzt für den Wert 10 (grüne LEDs sind an PIN 10 angeschlossen)
const int LEDRED_PIN = 11;      // Das Wort „LEDRED_PIN“ steht jetzt für den Wert 11 (rote LEDs sind an PIN11 angschlossen)
const int SWITCH01 = 2;         // 
const int SWITCH02 = 4;         // 

byte FADE_SCHRITT = 5;          // Bestimmt die Geschwindigkeit des „fadens“

/* Variablen deklarieren */
byte helligkeit = 0;            // Das Wort „Helligkeit“ steht nun für den Wert, der bei der PWM ausgegeben wird

void setup() {
  Serial.begin(9600);
  pinMode(LEDRED_PIN, OUTPUT);     // Der Pin mit den roten LEDs (Pin11) ist ein Ausgang
  pinMode(LEDBLUE_PIN, OUTPUT);    // Der Pin mit den blauen LEDs (Pin9) ist ein Ausgang
  pinMode(LEDGREEN_PIN, OUTPUT);   // Der Pin mit den grünen LEDs (Pin10) ist ein Ausgang
  pinMode(SWITCH01, INPUT_PULLUP); // Der Pin mit dem Schalter "SWITCH01" (Pin2) ist ein Eingang mit Pullup Widerstand
  pinMode(SWITCH02, INPUT_PULLUP); // Der Pin mit dem Schalter "SWITCH02" (Pin4) ist ein Eingang mit Pullup Widerstand
}

void loop() {
  if ((digitalRead(SWITCH01) == HIGH) && (digitalRead(SWITCH02) == LOW)) {
    Blinken();
    Serial.println("blinken...");
  }
  else if ((digitalRead(SWITCH02) == HIGH) && (digitalRead(SWITCH01) == LOW)) {
    Dimmen();
    Serial.println("dimmen...");
  }
  else {
    Licht();
    Serial.println("an...");
  }  
}

void Dimmen() { 
  analogWrite(LEDRED_PIN, helligkeit);       // LED (Pin9) die PWM Ausgabe aktiviert
  analogWrite(LEDBLUE_PIN, helligkeit);      // LED (Pin9) die PWM Ausgabe aktiviert
  analogWrite(LEDGREEN_PIN, helligkeit);     // LED (Pin9) die PWM Ausgabe aktiviert
  helligkeit = helligkeit + FADE_SCHRITT;    // Wert für die PWM-Ausgabe verändert
  delay(50);                                 // Helligkeit beibehalten

  if (helligkeit == 0 || helligkeit == 255) {  // Wenn Helligkeit 0 ODER 255 erreicht wird die Schleife ausgeführt
    FADE_SCHRITT = -FADE_SCHRITT ;             // Wechselt den Wert für die „Fadeschritte“ von positiv zu negativ
  }
}

void Blinken() {
  digitalWrite(LEDRED_PIN, HIGH);
  digitalWrite(LEDBLUE_PIN, HIGH);
  digitalWrite(LEDGREEN_PIN, HIGH);
  delay(50);
  digitalWrite(LEDRED_PIN, LOW);
  digitalWrite(LEDBLUE_PIN, LOW);
  digitalWrite(LEDGREEN_PIN, LOW);
  delay(50);
}

void Licht() {
  digitalWrite(LEDRED_PIN, HIGH);
  digitalWrite(LEDBLUE_PIN, HIGH);
  digitalWrite(LEDGREEN_PIN, HIGH);
  delay(20);
}
