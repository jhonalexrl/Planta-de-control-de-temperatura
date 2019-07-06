#include <DHT.h> //libreria del sensor
#define DHTPIN 2 //PIN DONDE CONECTAR LA SEÑAL DEL SENSOR
#define DHTTYPE DHT11  //Definimos el sensor DHT11

DHT dht(DHTPIN, DHTTYPE); //Se declara el sensor


String s = ""; //se define string como s y esta seguarda cadena de caracteres
float t; //se define como flotante la temperatura
float h; //se define como flotente la humedad
 
void tareasensor() {
  Serial.begin(115200); //se define la velocidad de comunicasion
  dht.begin(); //se activa el sensor

}

void tareaTH(){    // se define la tarea
  
   h = dht.readHumidity();//se define la humedad como h
   t = dht.readTemperature();//se define la temperatura como t
 // float tf = dht.readTemperature  (true );//se lee la temperatura


}
