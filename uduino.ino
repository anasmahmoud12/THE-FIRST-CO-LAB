String inputstr="";
    bool strcom=false;
    int x=1;
    int bin3=3;int unit=500;
    String morseletters[]={
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."};
String morsenumbers[] = {
  "-----",  
  ".----",  
  "..---",  
  "...--", 
  "....-",  
  ".....",  
  "-....",  
  "--...",  
  "---..",  
  "----."  
};

  String code;

void setup(){
  Serial.begin(9600);
  Serial.println("type the textt  ");
  pinMode(bin3,OUTPUT);
}


void loop (){

 
  if (strcom){
    
    inputstr.toUpperCase(); 
 Serial.println(inputstr);   
    for (int i=0;i<inputstr.length();++i){
        char a=inputstr.charAt(i);
        if (a==' '){
space();
continue;
        }
      
if (a>='A'&&a<='Z'){
  code=morseletters[a-'A'];
}
    if (a>='0'&& a<='9'){
       code=morsenumbers[a-'0'];
    }

      


for (int j=0;j<code.length();++j){
    char c=code.charAt(j);
    if (c=='.'){
        dot(code.length(),j);

    }
    else if (c=='-'){
        dash(code.length(),j);
    }
}
if (i!=inputstr.length()-1){
if(inputstr[i+1]!=' '){
    letter();
}
}

    }
  
strcom=false;
    inputstr="";
}


  
}


void dot(int n,int j){
  digitalWrite(bin3,HIGH);
  delay(unit);
    digitalWrite(bin3,LOW);
  if (j!=n-1){
delay(unit);
}}


void dash(int n ,int j){
  digitalWrite(bin3,HIGH);
  delay(3*unit);
    digitalWrite(bin3,LOW);
 if (j!=n-1){
delay(unit);
}
}
void space(){
  delay(7*unit);
}
void letter(){
  delay(3*unit);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') strcom = true;
    else inputstr += inChar;
  }
}
