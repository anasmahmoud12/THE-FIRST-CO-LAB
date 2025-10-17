char buf[10];
int i;
unsigned long num1, num2;

unsigned long readNum() {
  i = 0;
  while (1) {
    if (Serial.available()) {
      
      char c = Serial.read();
      if (c == '\n') {
        buf[i] = 0;
        return atol(buf);
      }
      if (c >= '0' && c <= '9'&&i<=3) {
        buf[i++] = c;
      }
    }

    
  }
}








void setup() {
  Serial.begin(9600);
  Serial.println("enter first number:");
}

void loop() {
  Serial.println("number 1:");
  num1 = readNum();
  Serial.print("you entered: ");
  Serial.println(num1);

  Serial.println("number 2:");
  num2 = readNum();
  Serial.print("you entered: ");
  Serial.println(num2);

  Serial.print("sum = ");
  Serial.println(num1 + num2);
  delay(1000);
}
