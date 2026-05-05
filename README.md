# Zukunftstag Arduino LED-Projekt 🚀💡

Dieses Projekt wurde für den **Zukunftstag** entwickelt und zeigt, wie man mit einem **Arduino**, **LEDs** und **Tastern** einfache Lichtprogramme umsetzt.

## 🧰 Hardware
- Arduino (z. B. Arduino Uno oder Nano)
- 3 LEDs (Rot, Grün, Blau)
- 1 EIN/AUS Schalter
- 1 EIN/AUS/EIN Schalter
- Widerstände
- Steckbrett & Jumper-Kabel

## 🔌 Anschlüsse
| Bauteil | Arduino Pin |
|-------|-------------|
| Rote LED | Pin 11 |
| Blaue LED | Pin 9 |
| Grüne LED | Pin 10 |
| Taster 1 | Pin 2 |
| Taster 2 | Pin 4 |

Die Schalter werden mit **INPUT_PULLUP** betrieben.  
👉 Das bedeutet:  
- **nicht gedrückt = HIGH**  
- **gedrückt = LOW**

## 🎛️ Funktionen
Je nach Stellung der beiden Schalter passiert etwas anderes:

### ✅ Dauerlicht (Standard)
- **Beide Schalter gleich** (beide gedrückt oder beide nicht gedrückt)
- Alle LEDs leuchten dauerhaft

### 🔁 Blinken
- **Schalter 1 EIN**
- **Schalter 2 AUS**
- Alle LEDs blinken schnell

### 🌈 Dimmen (Fade-Effekt)
- **Schalter 1 EIN**
- **Schalter 2 AUS**
- Alle LEDs werden langsam heller und dunkler (PWM)

## 🧠 Was lernt man dabei?
- Was **Pins** und **Variablen** sind
- Unterschied zwischen `digitalWrite` und `analogWrite`
- Nutzung von **PWM** zum Dimmen von LEDs
- Arbeiten mit **Funktionen**
- Einlesen von **Schalter/Taster**

## 🖥️ Serieller Monitor
Über den seriellen Monitor (115200 Baud) wird angezeigt, welcher Modus gerade aktiv ist:
- `an...`
- `blinken...`
- `dimmen...`

## 🎉 Viel Spaß!
Dieses Projekt ist ideal, um erste Erfahrungen mit Mikrocontrollern zu sammeln.  
Probiert gerne aus, Werte zu verändern oder eigene Effekte einzubauen!

## 🔧 Schaltplan

Der folgende Schaltplan zeigt vereinfacht, wie Arduino, LEDs und Taster verbunden sind.

Pin 11  ------------------->  LED ROT  ---[220Ω]--- GND
Pin 10  ------------------->  LED GRÜN ---[220Ω]--- GND
Pin  9  ------------------->  LED BLAU ---[220Ω]--- GND

Pin  2  ----┐ └---- Taster 1 ---- GND (INPUT_PULLUP)
Pin  4  ----┐ └---- Taster 2 ---- GND (INPUT_PULLUP)

### 📝 Erklärung zum Schaltplan
- **LEDs**
  - Jede LED ist über einen **Vorwiderstand (ca. 220 Ω)** mit Masse (GND) verbunden
  - Die langen Beine der LEDs kommen an die Arduino-Pins (9, 10, 11)

- **Schalter/Taster**
  - Die Taster sind zwischen **Pin und GND** angeschlossen
  - Durch `INPUT_PULLUP` ist **kein zusätzlicher Widerstand nötig**
  - Gedrückt ⇒ LOW, Nicht gedrückt ⇒ HIGH

⚠️ Wichtig: Alle **GND-Anschlüsse** müssen miteinander verbunden sein.
