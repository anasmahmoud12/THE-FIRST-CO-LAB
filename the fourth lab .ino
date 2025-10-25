const int analogPin = A5;
const int buzzerPin = 9;
const int ledPin = 13;
const int ledPin2 = 7;
float voltage = 0.0;
 
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
    pinMode(ledPin2, OUTPUT);

}

void loop() {
  int sensorValue = analogRead(analogPin);
   voltage = sensorValue * (5.0 / 1023.0);
  
  Serial.print("Voltage = ");
  Serial.print(voltage);
  Serial.println(" V");

  if (voltage > 3.0 ) {
    tone(buzzerPin, 1000);      
    digitalWrite(ledPin, HIGH);
        digitalWrite(ledPin2, HIGH);

  } 
  else if (voltage < 2.5 ) {
    noTone(buzzerPin);          
    digitalWrite(ledPin, LOW);
        digitalWrite(ledPin2, LOW);

    
  }

  delay(100);
}
