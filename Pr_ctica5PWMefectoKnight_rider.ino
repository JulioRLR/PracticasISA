int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;
int led6 = 11;
int array[] = {led1,led2,led3,led4,led5,led6};
int apagado = 0;
int luz1 = 64;
int luz2 = 128;
int luz3 = 255;
int i,f;
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(luz3>=255)
  {
   for(i=0;i<6;i++) 
   { 
    analogWrite(array[i],luz3);
    delay(50);
    analogWrite(array[i-1],luz2);
    delay(50);
    analogWrite(array[i-2],luz1);
    delay(50);
    analogWrite(array[i-3],apagado);
   }
  }
  if(apagado>=0) 
  {
    for(f=5;f>0;f--)
   {
    analogWrite(array[f-1],luz3);
    delay(50);
    analogWrite(array[f],luz2);
    delay(50);
    analogWrite(array[f+1],luz1);
    delay(50);
    analogWrite(array[f+2],apagado);
   }
  }
  if(i==6||f==0){
    i=0;
    f=5;
    }
} 
