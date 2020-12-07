/*
 *    Pruba Bimestral 
 * Nombre: Carlos Guerrón
 * Fecha: 07/12/2020
 * Objetivo: Realice un contador descendiente automático cada 1 segundo. Donde debe usar un poteciómetro que tiene una escala de valores enteros entre 10 a 20 al momento de girarlo. 
 * Una vez establecido el valor de conteo. Se activa el Timer 2 para realizar el conteo descendiente hasta cero. Una vez terminado, solicite nuevamente un nuevo valor a contar. 
 * Este proceso se evidencia mendiante una LCD y puede usar interrupciones para mejor la interacción con el usuario.
 * Ejemplo:
 * 1. Solicita a usuario mover el potenciómetro para establecer contador. Esto se muestra en la LCD.
 * 2. Se presiona interrupción para iniciar conteo de Timer 2 y se observa el decremento del contador.
 * 3. Solicita empezar de nuevo el sistema. 
 * 
 * Nota: puede usar
 * MsTimer2::start()
 * enables the interrupt.
 * MsTimer2::stop()
 * disables the interrupt.
 */
#include <MsTimer2.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int conversor;
int cont=20;
int onOff;
float valPot;
void setup() { 
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(1000,loop);
  //MsTimer2::start();
  attachInterrupt(0,conteo,LOW);
  Serial.println("Prueba Bimestral");

}

void loop() {
conversor=analogRead(0);
  valPot=(conversor*20)/1023;
   if(onOff==1){
    cont=valPot;
    lcd.setCursor(0,0);
    lcd.print(cont);
    lcd.clear();
    }
    if(onOff==2){
      cont=valPot;
    if(cont<21 && cont>9){
      
    MsTimer2::start(); 
    cont--;
    lcd.setCursor(0,0);
    lcd.print("POT: ");
    lcd.setCursor(6,0);
    lcd.print(valPot);
    lcd.setCursor(0,1);
    lcd.print("Cont:");
    lcd.setCursor(8,1);
    lcd.print(cont);
    
      if(cont==0){
        MsTimer2::stop();
      }
      
    }
    }
}
void contar(){
  
  }
void conteo() {
  
  switch(onOff){
    case 0:
    Serial.println("Mover el potenciometro para estabilizar contador");
    onOff++;
    break;
    case 1:
    Serial.println("Decremento del contador");
    onOff++;
    break;
    case 2:
    Serial.println("Presione el boton para iniciar nuevamente el sistema");
    onOff=0;
    break;
    }
  }
