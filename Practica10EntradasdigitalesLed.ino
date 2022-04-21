int led = 3;
int boton=2;
int valorBoton=0;
int estadoled = 0;

void setup(){
    pinMode(led,OUTPUT);    
    pinMode(boton,INPUT);
}
void loop() {
    valorBoton=digitalRead(boton);
    if(valorBoton == HIGH)
    {
      estadoled=!estadoled;
      delay(200);
    }
    if(estadoled== HIGH){
      digitalWrite(led,HIGH);
    }else{
      digitalWrite(led,LOW);
    }
}
