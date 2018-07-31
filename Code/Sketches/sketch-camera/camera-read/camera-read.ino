#define CLK 2
#define SI 3
#define AO A0

void aquisition_trigger(){
  delayMicroseconds(20); //pixel charge transfer time
  digitalWrite(CLK,HIGH);
  delayMicroseconds(2);
  digitalWrite(CLK,LOW);
  delayMicroseconds(1);
  digitalWrite(SI,HIGH);//trigger 
  delayMicroseconds(1);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(1);
  digitalWrite(SI,LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(SI,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(AO, INPUT_PULLUP);
}

void loop() {
  int line[128];
  aquisition_trigger();
  for(int i=0;i<128;i++){
    line[i] = analogRead(AO);
    Serial.print(line[i]);
    Serial.print("\t");
    delayMicroseconds(2);
    digitalWrite(CLK,LOW);
    delayMicroseconds(2);
    digitalWrite(CLK,HIGH);
  }
  Serial.println();

}
