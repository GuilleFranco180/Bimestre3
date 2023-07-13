/*
  FUNDACION KINAL
  CENTRO: EDUCATIVO TECNICO LABORAL KINAL
  PERITO EN ELECTRONICA
  QUINTO PERITO
  SECCION: A
  CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
  ALUMNOS: Guillermo Antonio Franco Longo
  CARNETS: 2022357
  proyecto: Sensor de gas 
*/

#include <Ticker.h>
#include <LedControl.h>

//Directivas de Preprocesado
#define sensor_gas A0
#define dataPin0   13   //pin 12 conectado al pin de datos del max7219.
#define dataClock0 11   //pin 11 conectado al pin de clock del max7219.
#define dataLoad0  10   //pin 10 conectado al pin de carga del max7219.

//Funciones
void medicion(void);
void RepresentarMatriz(byte *Datos, int espera);

//Variables
int time = 150;
int i, gas, conver, promedio;
unsigned long update_delay = 850;

//Constructores
Ticker mediciones(medicion, 2000);
LedControl matriz = LedControl(dataPin0 , dataClock0, dataLoad0, 1); // Los numeros se refieren a que pin de arduino tienes en cada uno de los terminales
/* 11 para el DIN, 13 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/

//Animaciones
byte Copo1[8] =
{
  B10011001,
  B01011010,
  B00111100,
  B11111111,
  B11111111,
  B00111100,
  B01011010,
  B10011001,
};

byte Fuego1[8] =
{
  B00010000,
  B00101000,
  B01010110,
  B01111110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
};

void setup() {
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  Serial.begin(9600);
  pinMode(sensor_gas, INPUT);
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 8); // La valores estan entre 1 y 15
  matriz.clearDisplay(0);
  mediciones.start();
}

void loop() {
  mediciones.update();
  if (conver < 40) {

    Serial.println("Sin fuego");
    //nieve
    for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, Copo1[i]);

    }
    delay(500);
    matriz.clearDisplay(0);
  }
  if (conver > 40 ) {
    Serial.println("Hay Fuego ");
    //fuego
    for (int i = 0; i < 8; i++)
    {
      matriz.setRow(0, i, Fuego1[i]);
    }
    delay(1000);
  }

}
void medicion(void) {

  gas = analogRead(A0);
  conver = map(gas, 0, 1023, 0, 100);
  Serial.println(conver);
}
