/*
 *    Pruba Bimestral 
 *      MASTER
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
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

char palabra; 
String cod; 
String pCodi;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Prueba Bimestral");
  Serial.println("Ingrese vocales de forma desordenada");
  Wire.onReceive(receiveEvent);
}

void loop() {
  if(Serial.available()>0){  
    palabra=Serial.read();    
    Wire.beginTransmission(4);   
    Wire.write(palabra);  
    Wire.endTransmission();    
  }
  lcd.setCursor(1,1);  
  delay(500);

}
void receiveEvent(){
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
    lcd.print(pCodi);  
   }
  }
