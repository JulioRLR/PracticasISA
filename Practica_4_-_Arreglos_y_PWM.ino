int ledPin=3;
int parpadeo[]={180,30,255,200,10,90,150,60};
void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  for(int i=0;i<8;i++){
    analogWrite(ledPin,parpadeo[i]);
    delay(200);
  }
}
