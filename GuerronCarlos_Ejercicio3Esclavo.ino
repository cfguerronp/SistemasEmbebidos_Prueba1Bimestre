/*
 *    Pruba Bimestral 
 *      ESCLAVO
 * Nombre: Carlos Guerrón
 * Fecha: 07/12/2020
 * Objetivo: Realice un programa que pueda ingresar vocales por comunicación serial y responda un vector del mismo tamaño pero de forma ordenadas visualizado en una lcd.
 * Ejemplo 1:
 * Ingreso: uie
 * Responde: eiu
 * Ejemplo 2:
 * Ingreso : auoia
 * Responde: aaiou
 */
  #include<Wire.h>
 char palabra; 
 String cod; 
 String pCodi; 
void setup() {
 Wire.begin(4);
  Serial.begin(9600);
  Serial.println("      Prueba Bimestral - Esclavo    ");
  Serial.println("Carlos Guerron");
  Serial.println("Orden de vocales");
  Serial.println();
  Wire.onReceive(receiveEvent);  
  Wire.onRequest(requestEvent);  

}

void loop() {
 delay(200); 

}
void receiveEvent(int bytes){
  while(Wire.available()){ 
    char menu=Wire.read();  
switch(menu){  
      case'a':    
      cod=cod+"a";
      break; 
      case'e':
      cod=cod+"e";
      break; 
      case'i':
      cod=cod+"i";
      break; 
      case'o':
      cod=cod+"o";
      break; 
      case'u':
      cod=cod+"u";
      break; 
      
      }
    }
    Serial.println(cod);   
    if(Serial.available()>0) { 
    pCodi=Serial.read();
   }
  }
  void requestEvent(){  
    if(Serial.available()>0){  
    palabra=Serial.read();  
    Wire.beginTransmission(4); 
    Wire.write(palabra); 
    Wire.endTransmission();  
      }
  }
