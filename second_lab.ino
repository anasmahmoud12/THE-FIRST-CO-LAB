#define push_buttom 12
#define grean 4
#define red 5

void setup() {
Serial.begin(9600);
  pinMode(push_buttom,INPUT_PULLUP);
  pinMode(grean,OUTPUT);
  pinMode(red,OUTPUT);
}

void loop() {
  bool state;
  state=debouce( push_buttom);
  Serial.println(state);
  
  if (state){
      digitalWrite(red,HIGH);
        digitalWrite(grean,LOW);

  }
  else{
     digitalWrite(red,LOW);
        digitalWrite(grean,HIGH);
  }
    
}
bool debouce(int p){
  bool state;
  bool prevstate=digitalRead(p);
  Serial.println(prevstate);

  for (int i=0;i<10;++i){
    delay(5);
    state=digitalRead(p);
    if (state!=prevstate){
      i=0;
      prevstate=state;
    }
  }
  return state;
}
