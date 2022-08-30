#include <Servo.h>

#include <LiquidCrystal.h>//Añadimos librería para la LCD

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Definimos pines de conexión de la LCD
//---------------RS, E, D4, D5, D6, D7 - Pines de la LCD
const int Trigger1 = 2;   //Pin digital 2 para el Trigger del sensor para mover motor
const int Echo1 = 3;   //Pin digital 3 para el Echo del sensorpara mover motor
const int Trigger2 = 6;   //Pin digital 2 para el Trigger del sensor para mover motor
const int Echo2 = 7;   //Pin digital 3 para el Echo del sensorpara mover motor
Servo servoMotor;

void setup(){
  Serial.begin(9600);//iniciailizamos la comunicación
  pinMode(Trigger1, OUTPUT); //pin como salida para sensor motor
  pinMode(Echo1, INPUT);  //pin como entrada para sensor motor
  digitalWrite(Trigger1, LOW);//Inicializamos el pin con 0 el del motor
  pinMode(Trigger2,OUTPUT);//pin como salida detectar usuarios
  pinMode(Echo2,INPUT);////pin como entrada para detectar usuarios
  digitalWrite(Trigger2, LOW);//Iniciamos pin con 0 el del detector de usuario
  servoMotor.attach(5);
  lcd.begin(16, 2);//Definimos las columnas y filas que contiene la LCD 
}
void loop(){
  long t2; //timepo que demora en llegar el eco
  long d2; //distancia en centimetros

  digitalWrite(Trigger2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger2, LOW);
  
  t2 = pulseIn(Echo2, HIGH); //obtenemos el ancho del pulso
  d2 = t2/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d2);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms

if (d2< 20) {
 lcd.print("Hola");
 delay(1000);
 lcd.clear(); 
 lcd.print("Introduce");
 delay(1000);
 lcd.clear();  
 lcd.print("Botellas");
 delay(1000);
 lcd.clear(); 
 lcd.print("Espera");
 delay(1000);
 lcd.clear(); 
 lcd.print("2 segundos");
 delay(1000);
 lcd.clear(); 
 lcd.print("y Sueltala"); 
 delay(1000);
 lcd.clear();
 }
  
  long t1; //timepo que demora en llegar el eco
  long d1; //distancia en centimetros

  digitalWrite(Trigger1, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger1, LOW);
  
  t1 = pulseIn(Echo1, HIGH); //obtenemos el ancho del pulso
  d1 = t1/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d1);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms

    
if (d1 < 5) {
  servoMotor.write(0);// Desplazamos a la posición 90º
  delay(600);// Esperamos 1 segundo
  servoMotor.write(90);// Desplazamos a la posición 90º
  delay(600);// Esperamos 1 segundo
}else  {
   servoMotor.write(0);// Desplazamos a la posición 0º
    } 
  
  }
 
