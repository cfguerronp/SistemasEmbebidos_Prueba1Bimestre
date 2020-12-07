/*
 *    Pruba Bimestral 
 *      ESCLAVO
 * Nombre: Carlos Guerrón
 * Fecha: 07/12/2020
 * Objetivo: Realice un convertidor de clave morse que se ingresa el mensaje por comunicación serial y su resultado se observa en una lcd.
 */

#include<Wire.h>
 char palabra; // variable que guarda la palabra ingresasda 
 String cod; // variable para nombrar a las letras que vamos a codificar
 String pCodi; // para mostarr la palabra codificada
 
void setup() {
  Wire.begin(4);
  Serial.begin(9600);
  Serial.println("      Prueba Bimestral - Esclavo    ");
  Serial.println("Carlos Guerron");
  Serial.println("Codificacion Morse");
  Serial.println();
  Wire.onReceive(receiveEvent);  // solicita recibir del master
  Wire.onRequest(requestEvent);  // solicita envio del mamster

}

void loop() {
  delay(200); 

}
void receiveEvent(int bytes){
  while(Wire.available()){ // realizamos un ciclo while para poner la condicion de la codificacion
    char menu=Wire.read();  // creamos una varible menu para poner los datos de la codificacion
switch(menu){  // creamos el menu y ponemos las letras del abecedario para poder codificar
      case'a':     // ponemos varios casos con todas la letars del abecedario para evitar errores y para codificar las letras que deseamos
      cod=cod+".-";
      break; 
      case'b':
      cod=cod+"-...";
      break; 
      case'c':
      cod=cod+"-.-.";
      break; 
      case'd':
      cod=cod+"-..";
      break; 
      case'e':
      cod=cod+".";
      break; 
      case'f':
      cod=cod+"..-.";
      break; 
      case'g':
      cod=cod+"--.";
      break; 
      case'h':
      cod=cod+"....";
      break; 
      case'i':
      cod=cod+"..";
      break; 
      case'j':
      cod=cod+".---";
      break; 
      case'k':
      cod=cod+"-.-";
      break; 
      case'l':
      cod=cod+".-..";
      break; 
      case'm':
      cod=cod+"--";
      break; 
      case'n':
      cod=cod+"-.";
      break; 
      case'o':
      cod=cod+"---";
      break; 
      case'p':
      cod=cod+".--.";
      break;
      case'q':
      cod=cod+"--.-";
      break;
      case'r':
      cod=cod+".-.";
      break;
      case's':
      cod=cod+"...";
      break;
      case't':
      cod=cod+"-";
      break;
      case'u':
      cod=cod+"..-";
      break;
      case'v':
      cod=cod+"...-";
      break;
      case'w':
      cod=cod+".--";
      break;
      case'x':
      cod=cod+"-..-";
      break;
      case'y':
      cod=cod+"-.--";
      break;
      case'z':
      cod=cod+"--..";
      break;
      case'0':
      cod=cod+"-----";
      break;
      case'1':
      cod=cod+".----";
      break;
      case'2':
      cod=cod+"..---";
      break;
      case'3':
      cod=cod+"...--";
      break;
      case'4':
      cod=cod+"....-";
      break;
      case'5':
      cod=cod+".....";
      break;
      case'6':
      cod=cod+"-....";
      break;
      case'7':
      cod=cod+"--...";
      break;
      case'8':
      cod=cod+"---..";
      break;
      case'9':
      cod=cod+"----.";
      break;
      }
    }
    Serial.println(cod);   // nos imprime la palabra codificada
    if(Serial.available()>0) { 
    pCodi=Serial.read();
   }
  }
  void requestEvent(){  // creamos el metodo que solicita el envio al master
    if(Serial.available()>0){  // creamos la condicion para la comunicacion I2C con el master
    palabra=Serial.read();  
    Wire.beginTransmission(4); 
    Wire.write(palabra); 
    Wire.endTransmission();  
      }
    }
