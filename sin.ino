float t = 0;
unsigned long last = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (millis() - last > 25) {
    last = millis();
    float y = sin(6.28  * t);
    Serial.println(y);
    t += 0.02;
  }
}
