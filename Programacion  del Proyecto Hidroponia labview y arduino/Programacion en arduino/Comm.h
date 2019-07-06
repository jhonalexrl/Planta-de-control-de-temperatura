void setupCOM() {
 
  Serial.begin(115200); //velocidad de la comunicacion
}


void serialEvent() {
  s="";  //se define string como s y esta seguarda cadena de caracteres
     while (Serial.available())//mientras el puerto serial este disponible        
  {   char c = Serial.read(); //la nueva cadena de caracteres se guarda en c       
      while ( c != '\n' ) //mientras c sea igual a enter           
        {     s = s + c ; //se suma s mas c           
              delay(1);//tiempo de espera 1 ms               
              c = Serial.read(); // se lee c     
        }
}
 if (s.startsWith("sp="))
  {
    String T = s.substring(3);
    Setpoint=T.toInt();
  }
 
    if ( s.startsWith  ("T")) //se manda la variable T        
     {
      Serial.println (t);//Imprime la temperatura       
     }
    if ( s.startsWith  ("H"))//se manda la variable H          
    {
      Serial.println (h); //Imprime la humedad        
    }

    if ( s.startsWith  ("*"))//con esta variable se salta el espacio en el monitor serial          
    {
    //  Serial.print(DHTPIN2 ,!digitalRead(DHTPIN2)); 
    }
}
