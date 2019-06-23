

//---Llamada a las diferentes tareas realizadas en .h----
#include "sensor_T_H.h"//se inclulle la pestaña del sensor  
#include "pid.h"   //se inclulle la pestaña de pid 
#include "Comm.h" //se inclulle la pestaña de comando  
#include "lamp.h"  //se inclulle la pestaña de la lampara  




    
#define Ts1 2000      // Periodo de la tarea 1
#define Ts2 10000      // Periodo de la tarea 2 
#define Ts3 2000      // Periodo de la tarea 3
 
// -- Variables de control de tiempo ---------------------
 
unsigned long int T =0;     // Tiempo total (microsegundos)
 
// -- Variables de temporizacion de tareas --------------- Creacion de variables 
 
// Tarea 1: Sensor  De Temperatura y Humedad

unsigned long int ts1;   // Tiempo parcial (tarea 1)
unsigned long int t01;   // Tiempo de la ultima ejecucion

 // Tarea 2: Ventilador
unsigned long int ts2;   // Tiempo parcial (tarea 2)
unsigned long int t02;   // Tiempo de la ultima ejecucion

unsigned long int ts3;   // Tiempo parcial (tarea 3)
unsigned long int t03;   // Tiempo de la ultima ejecucion

// -- Funciones de definicion de tareas ------------------





//--------------------------------------------------------
 

// -- Inicializacion -------------------------------------
 
void setup() {
  // Inicializacion de temporizadores de tarea
  ts1 = 0;//tarea iniciada en cero
  t01 = 0;//tiempo en cero
  ts2 = 0;//tarea iniciada en cero
  t02 = 0;//tiempo en cero
  ts3 = 0;//tarea iniciada en cero
  t03 = 0;//tiempo en cero
  setupCOM();//se imboca tareas
  tareasensor();//se imboca tareas
  SetupPid();//se imboca tareas
  setuplamp();//se imboca tareas
  
 }
 
// -- Bucle principal ------------------------------------
 
void loop() { 
  // Actualizar tiempo
  T = millis();// Tiempo de planeador basado en milisegundos
  // Temporizacion tarea 1
  ts1 = T - t01;
  if (ts1 >= Ts1) {
    tareaTH ();  // en este espacio se hace la llamada a la tarea de acuerdo a
    t01 = T; // la configuración de tiempos Ts1
  }
 
 // Temporizacion tarea medicion de distancia
  ts2 = T - t02;
  if (ts2 >= Ts2) {
    TareaPID  (); // en este espacio se hace la llamada a la tarea de acuerdo a
    t02 = T; // la configuración de tiempos Ts2
  }
   ts3 = T - t03;
  if (ts3 >= Ts3) {
   lamp1  (); // en este espacio se hace la llamada a la tarea de acuerdo a
    t03 = T; // la configuración de tiempos Ts3
  }
}
