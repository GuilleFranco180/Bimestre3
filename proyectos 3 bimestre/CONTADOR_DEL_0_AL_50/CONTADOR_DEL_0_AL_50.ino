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
   Proyecto: interrupciones externas 
*/
//Directivas de Propocesador
#define BOTONMAS 2 //pin 2 utilizado para una interrupción externa para rising
#define BOTONMENOS 3 //pin 3 utilizado para una interrupción externa para falling
#define au 4
#define Bu 5
#define Cu 6
#define Du 7

#define ad 8
#define Bd 9
#define Cd 10
#define Dd 11

//Funciones
void funcion_rising(void);
void funcion_falling(void);
void display_primero();
void display_segundo();

//Variables
volatile static bool f_print = false; //Variable booleana que me permite imprimir un texto en el Loop
int unidades = 0; ///variable que va de 0 - 9
int decenas = 0; ///variable que va de 0 - 5

void setup() {
  pinMode(BOTONMAS, INPUT);
  pinMode(BOTONMENOS, INPUT);
  pinMode(au, OUTPUT);
  pinMode(Bu, OUTPUT);
  pinMode(Cu, OUTPUT);
  pinMode(Du, OUTPUT);
  pinMode(ad, OUTPUT);
  pinMode(Bd, OUTPUT);
  pinMode(Cd, OUTPUT);
  pinMode(Dd, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BOTONMAS), funcion_rising, RISING); //Anclar la interrupcion del pin 9 a una funcion de ISR, disparado por el flanco
  attachInterrupt(digitalPinToInterrupt(BOTONMENOS), funcion_falling, FALLING); //Anclar la interrupcion del pin 10 a una funcion de ISR, disparado por el flanco
}
void loop() {
  if (f_print) {
    f_print = false; //Limpio la variable
    if (unidades > 9) {
      decenas++;
      unidades = 0;
    }
    if (unidades == -1) {
      unidades = 9;
      decenas--;
    }
    if (decenas < 0) {
      unidades = 0;
      decenas = 5;
    }
    if (unidades > 0 && decenas == 5) {
      unidades = 0;
      decenas = 0;
    }

  }
  display_primero();
  display_segundo();
}
//Funciones ISR
void funcion_rising(void) {
  unidades ++; //aunmento el valor de la variable
  f_print = true;
}
void funcion_falling(void) {
  unidades --; //disminuyo el valor de la variable
  f_print = true;
}
void display_primero() {
  if (unidades == 0) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, LOW);
    digitalWrite(Cu, LOW);
    digitalWrite(Du, LOW);
  }
  if (unidades == 1) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, LOW);
    digitalWrite(Cu, LOW);
    digitalWrite(Du, HIGH);
  }
  if (unidades == 2) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, LOW);
    digitalWrite(Cu, HIGH);
    digitalWrite(Du, LOW);
  }
  if (unidades == 3) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, LOW);
    digitalWrite(Cu, HIGH);
    digitalWrite(Du, HIGH);
  }
  if (unidades == 4) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, HIGH);
    digitalWrite(Cu, LOW);
    digitalWrite(Du, LOW);
  }
  if (unidades == 5) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, HIGH);
    digitalWrite(Cu, LOW);
    digitalWrite(Du, HIGH);
  }
  if (unidades == 6) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, HIGH);
    digitalWrite(Cu, HIGH);
    digitalWrite(Du, LOW);
  }
  if (unidades == 7) {
    digitalWrite(au, LOW);
    digitalWrite(Bu, HIGH);
    digitalWrite(Cu, HIGH);
    digitalWrite(Du, HIGH);
  }
  if (unidades == 8) {
    digitalWrite(au, HIGH);
    digitalWrite(Bu, LOW);
    digitalWrite(Cu, LOW);
    digitalWrite(Du, LOW);
  }
  if (unidades == 9) {
    digitalWrite(au, HIGH);
    digitalWrite(Bu, LOW);
    digitalWrite(Cu, LOW);
    digitalWrite(Du, HIGH);
  }
}
void display_segundo() {
  if (decenas == 0) {
    digitalWrite(ad, LOW);
    digitalWrite(Bd, LOW);
    digitalWrite(Cd, LOW);
    digitalWrite(Dd, LOW);
  }
  if (decenas == 1) {
    digitalWrite(ad, LOW);
    digitalWrite(Bd, LOW);
    digitalWrite(Cd, LOW);
    digitalWrite(Dd, HIGH);
  }
  if (decenas == 2) {
    digitalWrite(ad, LOW);
    digitalWrite(Bd, LOW);
    digitalWrite(Cd, HIGH);
    digitalWrite(Dd, LOW);
  }
  if (decenas == 3) {
    digitalWrite(ad, LOW);
    digitalWrite(Bd, LOW);
    digitalWrite(Cd, HIGH);
    digitalWrite(Dd, HIGH);
  }
  if (decenas == 4) {
    digitalWrite(ad, LOW);
    digitalWrite(Bd, HIGH);
    digitalWrite(Cd, LOW);
    digitalWrite(Dd, LOW);
  }
  if (decenas == 5) {
    digitalWrite(ad, LOW);
    digitalWrite(Bd, HIGH);
    digitalWrite(Cd, LOW);
    digitalWrite(Dd, HIGH);
  }
}
