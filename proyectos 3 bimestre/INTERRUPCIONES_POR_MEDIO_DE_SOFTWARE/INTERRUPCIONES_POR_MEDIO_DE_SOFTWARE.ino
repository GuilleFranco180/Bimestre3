/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Guillermo Antonio Franco Longo
   Profe. Alejandro Navas
   Carnet: 2022357
   Proyecto: Interrupciones por medio de Software
*/



//Librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>



//Directivas de Preprocesado
#define boton 2


//Funcion ISR
void sensortemperatura();
void Boton_Franco();



//Constructores
Ticker accion_temperatura(sensortemperatura, 2900);
Ticker state_boton(Boton_Franco, 5900);
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);



void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  accion_temperatura.start();
  state_boton.start();
  sensor.begin();
}



void loop() {
  accion_temperatura.update();
  state_boton.update();
}



void sensortemperatura() {
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print("La actual Temeperatura es: ");
  Serial.print(temp);
  Serial.println(" C");
}



void Boton_Franco() {
  int estado = digitalRead(boton);

  if (estado == HIGH) {
    Serial.println("El estado del boton es:");
    Serial.println("Presionado");
  }



  if (estado == LOW) {
    Serial.println("El estado del boton es:");
    Serial.println("No Presionado");
  }
}
