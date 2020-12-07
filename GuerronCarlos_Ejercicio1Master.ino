/*
 *    Pruba Bimestral 
 *      MASTER
 * Nombre: Carlos Guerrón
 * Fecha: 07/12/2020
 * Objetivo: Realice un convertidor de clave morse que se ingresa el mensaje por comunicación serial y su resultado se observa en una lcd.
 */

 #include<Wire.h>  // importamos la libreria Wire que sirve para el protocolo I2C
 #include<LiquidCrystal.h>  // importamos la libreria Liquid Crystal que es para el lcd
 LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // nombramos los pines que vamos a usar para el lcd
 char palabra; // variable que guarda la palabra ingresasda 
 String cod; // variable para nombrar a las letras que vamos a codificar
 String pCodi; // para mostarr la palabra codificada
 
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("      Prueba Bismestral - Master    ");
  Serial.println("Carlos Guerron");
  Serial.println("Codificacion Morse");
  Serial.println();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Wire.onReceive(receiveEvent);

}

void loop() {
    if(Serial.available()>0){  // ponemos la condicon de que si se escribe algo en la terminal realice la siguiente actividad
    palabra=Serial.read();    // guarda en la variable palabra lo que se escribio en serial
    Wire.beginTransmission(4);   // inicia la transmision con el esclavo 4
    Wire.write(palabra);   //escribe el dato que tenemos en la variable palabra
    Wire.endTransmission();    // termina la transmision de I2C
  }
  lcd.setCursor(1,1);  
  delay(500);
}

void receiveEvent(){
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
    
    Serial.println(cod);  // Nos muestra en la terminal virtual la letra codificada
    if(Serial.available()>0) {
    pCodi=Serial.read();  // leemos lo que esta ingresado en la terminal 
    lcd.print(pCodi);  // mostramos en la lcd la palabra codificada
   }
   
  }
