const int ledPins[] = {13, 10, 5};   	    // assign LEDs pins
const int buttonPins[] = {12,  9, 4};     // assign push‑buttons

int ledState[3] = {LOW};        		      // LED on/off state
int lastButton[3];                        // previous button reading

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);       // LED pins set to output
    pinMode(buttonPins[i], INPUT);        // enable input pins
    digitalWrite(ledPins[i], LOW);        // start all LEDs OFF
    lastButton[i] = digitalRead(buttonPins[i]);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    int reading = digitalRead(buttonPins[i]); // read button state

    if (lastButton[i] == LOW && reading == HIGH) {
      ledState[i] = !ledState[i];                    // toggle
      digitalWrite(ledPins[i], ledState[i] ? HIGH : LOW);
    }
    lastButton[i] = reading;
  }
  delay(15);
}
