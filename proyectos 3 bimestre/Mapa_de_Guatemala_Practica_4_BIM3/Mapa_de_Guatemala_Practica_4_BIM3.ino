/*
FUNDACION KINAL
CENTRO: Educativo Tecnico Laboral Kinal
Perito en Electronica
Quinto Perito
SECCION: A
CURSO: Taller de Electronica Digital y Reparacion de Computadoras
Proyecto: Mapa de Guatemala 
Alumno:Guillermo Antonio Franco Longo
CARNET: 2022357
*/


#include <Wire.h>
#include <PCF8574.h>

//Directivas de Preprocesador
#define BUZZER 6
#define PCF8574_HIGH LOW  //Negacion utilizada para encender un puerto del expansor PCF8574
#define PCF8574_LOW HIGH  //Negacion utilizada para apagar un puerto del expansor PCF8574

//Constructor
PCF8574 expansor_PCF(0x27);  //Expansor con direccion I2C 0x27

//Variables
int num_de_pregunta;
int t = 3000; //tiempo de encendido de las leds
String respuesta;

//Funciones
int num_random();
void preguntas();
void incorrecta();

void setup() {
  Serial.begin(9600);
  expansor_PCF.begin();
  for (int i = 2; i < 17; i++) {
    pinMode(i, OUTPUT);
  }  
}

void loop() {
  num_de_pregunta = num_random();
  preguntas();
  delay(1500);
}

int num_random() {
  int num = random(0, 21);
  return num;
}

void preguntas() {
  switch (num_de_pregunta) {
    case 0:
      Serial.println("Cabecera de Petén?");
      if (respuesta == String("Flores")) {
        digitalWrite(2, HIGH);
        delay(t);
        digitalWrite(2, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 1:
      Serial.println("Cabecera de Izabal?");
      if (respuesta == String("Puerto Barrios")) {
        digitalWrite(3, HIGH);
        delay(t);
        digitalWrite(3, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 2:
      Serial.println("Cabecera de Alta Verapaz?");
      if (respuesta == String("Cobán")) {
        digitalWrite(4, HIGH);
        delay(t);
        digitalWrite(4, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 3:
      Serial.println("Cabecera de Qiché?");
      if (respuesta == String("Santa Cruz del Quiché")) {
        digitalWrite(5, HIGH);
        delay(t);
        digitalWrite(5, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 4:
      Serial.println("Cabecera de Huehuetenango?");
      if (respuesta == String("Huehuetenango")) {
        expansor_PCF.write(0, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(0, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 5:
      Serial.println("Cabecera de Escuintla?");
      if (respuesta == String("Escuintla")) {
        expansor_PCF.write(1, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(1, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 6:
      Serial.println("Cabecera de San Marcos?");
      if (respuesta == String("San Marcos")) {
        digitalWrite(8, HIGH);
        delay(t);
        digitalWrite(8, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 7:
      Serial.println("Cabecera de Jutiapa?");
      if (respuesta == String("Jutiapa")) {
        digitalWrite(9, HIGH);
        delay(t);
        digitalWrite(9, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 8:
      Serial.println("Cabecera de Baja Verapaz?");
      if (respuesta == String("Salamá")) {
        digitalWrite(10, HIGH);
        delay(t);
        digitalWrite(10, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 9:
      Serial.println("Cabecera de Santa Rosa?");
      if (respuesta == String("Cuilapa")) {
        digitalWrite(11, HIGH);
        delay(t);
        digitalWrite(11, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 10:
      Serial.println("Cabecera de Zacapa?");
      if (respuesta == String("Zacapa")) {
        digitalWrite(12, HIGH);
        delay(t);
        digitalWrite(12, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 11:
      Serial.println("Cabecera de Suchitepéquez?");
      if (respuesta == String("Mazatenango")) {
        digitalWrite(13, HIGH);
        delay(t);
        digitalWrite(13, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 12:
      Serial.println("Cabecera de Chiquimula?");
      if (respuesta == String("Chiquimula")) {
        digitalWrite(14, HIGH);
        delay(t);
        digitalWrite(14, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 13:
      Serial.println("Cabecera de Guatemala?");
      if (respuesta == String("Ciudad de Guatemala")) {
        digitalWrite(15, HIGH);
        delay(t);
        digitalWrite(15, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 14:
      Serial.println("Cabecera de Jalapa?");
      if (respuesta == String("Jalapa")) {
        digitalWrite(16, HIGH);
        delay(t);
        digitalWrite(16, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 15:
      Serial.println("Cabecera de Chimaltenango?");
      if (respuesta == String("Chimaltenango")) {
        digitalWrite(17, HIGH);
        delay(t);
        digitalWrite(17, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 16:
      Serial.println("Cabecera de Quetzaltenango?");
      if (respuesta == String("Quetzaltenango")) {
        expansor_PCF.write(2, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(2, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 17:
      Serial.println("Cabecera de El Progreso?");
      if (respuesta == String("Guastatoya")) {
        digitalWrite(7, HIGH);
        delay(t);
        digitalWrite(7, LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 18:
      Serial.println("Cabecera de Retalhuleu?");
      if (respuesta == String("Retalhuleu")) {
        expansor_PCF.write(7, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(7, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
         
      }
      break;
    case 19:
      Serial.println("Cabecera de Sololá?");
      if (respuesta == String("Sololá")) {
        expansor_PCF.write(4, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(4, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 20:
      Serial.println("Cabecera de Totonicapán?");
      if (respuesta == String("Totonicapán")) {
        expansor_PCF.write(5, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(5, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
    case 21:
      Serial.println("Cabecera de Sacatepéquez?");
      if (respuesta == String("La Antigua Guatemala")) {
        expansor_PCF.write(6, PCF8574_HIGH);
        delay(t);
        expansor_PCF.write(6, PCF8574_LOW);
      } else {
        Serial.print("Respuesta Incorrecta");
        incorrecta();
      }
      break;
  }
}


void incorrecta() {
    delay(500);
    tone(BUZZER, 400, 350);  
    delay(350);
    tone(BUZZER, 350, 150);
    delay(150);
   
    delay(350);
    tone(BUZZER, 400, 150);
    delay(150);
    tone(BUZZER, 350, 1000);  
    delay(1000);
}
