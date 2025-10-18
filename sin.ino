float t = 0;
unsigned long last = 0;

float dt = 0.02;        
unsigned long interval;   

void setup() {
  Serial.begin(115200);
  interval = dt * 1000; 
}

void loop() {
  if (millis() - last >= interval) {
    last = millis();
    float y = sin(6.283 * t);  
    Serial.println(y);
    t += dt;
  }
}
