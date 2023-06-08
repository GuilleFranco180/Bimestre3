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
   Proyecto: CONTROL DE BRILLO DE UN LED
*/
#define led 3
#define pot A0

int intensidad, brillo;

void setup() {
  pinMode(led , OUTPUT);
}

void loop() {
  intensidad = analogRead(pot);
  //Map de los valores del potenciometro
  brillo = map(intensidad, 0, 1023, 0, 255);
  analogWrite(led, brillo);
}
