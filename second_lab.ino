#define inputPin 12
#define green 4
#define red 5

bool lastState = HIGH;
bool ledState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
}

void loop() {
  bool currentState = debounce(inputPin);

  if (currentState != lastState) {
    if (currentState == LOW) { 
      ledState = !ledState;   
      if (ledState) {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
      } else {
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
      }
    }
    lastState = currentState;
  }
}

bool debounce(int pin) {
  bool state;
  bool prevState = digitalRead(pin);
  for (int i = 0; i < 10; ++i) {
    delay(5);
    state = digitalRead(pin);
    if (state != prevState) {
      i = 0;
      prevState = state;
    }
  }
  return state;
}
