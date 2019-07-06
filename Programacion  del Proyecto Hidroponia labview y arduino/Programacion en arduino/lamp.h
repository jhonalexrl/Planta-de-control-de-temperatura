
const int ledPin =   LED_BUILTIN;// se declara el led como entero

int ledState = LOW;   // el led comiensa apagado

void setuplamp() {
  
  pinMode(ledPin, OUTPUT);//se declara el led como salida
}

void lamp1() {

      ledState = HIGH;//el led se lo pone en alto
    digitalWrite(ledPin, ledState);//se lee el pin en alto
    
  }
