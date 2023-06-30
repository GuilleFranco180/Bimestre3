/*
 * Fundación Kinal
 * Centro educativo técnico laboral Kinal
 * Electrónica
 * Grado: Quinto
 * Sección: "A"
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Guillermo Antonio Franco Longo 
 * Carnet:2022357
 * Proyecto: practica 3
*/
#include <Servo.h>
#define LDR A0
#define LEDR 3
#define LEDG 4
#define LEDB 5
#define Servo1 6 


int INA = 8;
int INB = 9;
int INC = 10;
int IND = 11;
int demora = 20;
const int sensorob = 2;

int resultado_azul, resultado_rojo, resultado_verde;
int resultado;
int tol = 8;

Servo SERVOKEVIN;

void setup() {
  Serial.begin(9600);
  //Para motor Stepper
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(INC, OUTPUT);
  pinMode(IND, OUTPUT);
  //Para Sensor de obstaculos
  pinMode(sensorob, INPUT);
  //Para LDR 
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LDR, INPUT);
  //LEDs en estado bajo.
  digitalWrite(LEDR,LOW);
  digitalWrite(LEDG,LOW);
  digitalWrite(LEDB,LOW);
 //Para Servo
 SERVOKEVIN.attach(Servo1);



}
void loop() {

    int value = 0;
  value = digitalRead(sensorob );
  if (value == HIGH) {
 digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  delay(2);
  //paso2
  digitalWrite(INA, HIGH);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  delay(2);
  //paso3
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  delay(2);
  //paso4
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, HIGH);
  digitalWrite(IND, LOW);
  delay(2);
  //paso5
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  digitalWrite(INC, HIGH);
  digitalWrite(IND, LOW);
  delay(2);
  //paso6
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  digitalWrite(INC, HIGH);
  digitalWrite(IND, HIGH);
  delay(2);
  //paso7
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, HIGH);
  delay(2);
  //paso8
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, HIGH);
  delay(2);
  }
  
  else {
    digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  delay(2);
  //paso2
  digitalWrite(INA, HIGH);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  delay(2);
 
      //sensor de color por LDR
  digitalWrite(LEDR,HIGH);
  delay(150);

  resultado= analogRead(LDR);
  resultado_rojo;

  resultado= analogRead(LDR);
  resultado_rojo=map(resultado,0,1023,0,1023);

  Serial.print("R,G,B rojo  =");
  Serial.println(resultado_rojo);
  digitalWrite(LEDR,LOW);
  delay(150);

  digitalWrite(LEDG,HIGH);
  delay(150);

  resultado = analogRead(LDR);
  resultado_verde=map(resultado,0,1023,0,1023);

  Serial.print("R,G,B,verde  =");
  Serial.println(resultado_verde);  
  digitalWrite(LEDG,LOW);
  delay(150);

  digitalWrite(LEDB,HIGH);
  delay(150);

  resultado=analogRead(LDR);
  resultado_azul=map(resultado,0,1023,0,1023);
  Serial.print("R,G,B,azul =");
  Serial.println(resultado_azul);  
  digitalWrite(LEDB,LOW);
  delay(150);
    

    //detector de colores con accion del Servo

if(resultado_verde>resultado_rojo&&resultado_verde>resultado_azul){
  SERVOKEVIN.write(0);
  delay(100);
  SERVOKEVIN.write(120);
  delay(1000);
  }

  }
}
