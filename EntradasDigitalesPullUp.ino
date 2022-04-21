void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool estado_pusador = digitalRead(3);
  String estado;
  if(estado_pusador==true){
    estado ="No pulsado";
  }else{
    estado="Pulsado";
  }
  Serial.println(estado);
}
