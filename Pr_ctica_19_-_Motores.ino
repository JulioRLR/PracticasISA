const byte motora=3;
const byte motorb=4;
const byte enableIzq=10;
byte vel=0;
void setup(){
  Serial.begin(9600);
  pinMode( motora,OUTPUT);
  pinMode( motorb,OUTPUT);
  analogWrite(enableIzq,vel);
}
void loop(){
  control_izq(true,254);
  delay(2000);
  control_izq(true,0);
  delay(1000);
  control_izq(true,254);
  delay(2000);
  control_izq(true,0);
  delay(1000);
}
void control_izq(bool sent, byte vel){
  if(sent==true){
    digitalWrite(motora,HIGH);
    digitalWrite( motorb,LOW);
  }
  else{
   digitalWrite(motora,LOW);
    digitalWrite( motorb,HIGH);
  }
  analogWrite(enableIzq,vel);
}
