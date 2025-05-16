// Pin definitions
const int pot1Pin = A0;
const int pot2Pin = A1;

const int buzzer1 = 2;
const int buzzer2 = 3;
const int buzzer3 = 4;

const int leds[5] = {5, 6, 7, 8, 9};

void setup() {
  // Buzzer pins
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);

  // LED pins
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }

  // Optional: initialize serial for debugging
  Serial.begin(9600);
}

void loop() {
  // Read potentiometers
  int pot1Value = analogRead(pot1Pin);  // 0 - 1023
  int pot2Value = analogRead(pot2Pin);  // 0 - 1023

  // --- BUZZER LOGIC ---
  digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, LOW);

  if (pot1Value <= 341) {
    digitalWrite(buzzer1, HIGH);
  } else if (pot1Value <= 682) {
    digitalWrite(buzzer2, HIGH);
  } else {
    digitalWrite(buzzer3, HIGH);
  }

  // --- LED CHASE LOGIC ---
  // Map pot2 value to delay time (e.g. 50ms to 500ms)
  int delayTime = map(pot2Value, 0, 1023, 50, 500);

  for (int i = 0; i < 5; i++) {
    turnOnLED(i);
    delay(delayTime);
  }
}

// Helper to turn on one LED at a time
void turnOnLED(int index) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], i == index ? HIGH : LOW);
  }
}

// TinkerCAD Project Link:
// https://www.tinkercad.com/things/9S5HCKAH5oX/editel?returnTo=%2Fdashboard&sharecode=f5qSC2ic1e2WzxHM7R4SOSVmrVrrTkEh0Q74hC0901A
