#include <LiquidCrystal.h>;

LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5);  //Asignar pines a utilizar para el display
double resist;


byte ohm[8] = { B01110, B10001, B10001, B10001, B01010, B01010, B11011, B00000  };  //Arreglo de bytes para crear un nuevo caracter (omega)

//Codigo a ejecutar una sola vez
void setup() {
lcd.begin(16, 2);          //Definir numero de caracteres y lineas del display

lcd.print("Resistencia:"); //Escribir una cadena en la primer linea del display
pinMode(A0,INPUT);         //Definir pin analogico como entrada

lcd.createChar(1, ohm);    //Crear un nuevo caracter (omega) y asignarle el identificador 1
}


//codigo ejecutado continuamente
void loop() {
lcd.setCursor(0, 1);    //Colocar el cursor en el primer caracter de la segunda linea


resist = (analogRead(A0)*106.39)+100;  //mapear el valor obtenido del convertidor interno al rango de medición


if(resist<10000)        //Mostrar el valor en ohms
{
  lcd.print(resist);    //Imprimir valor
  lcd.write(1);         //Imprimir omega
  lcd.print("   ");     //Imprimir espacios para limpiar datos anteriores en el display
}

else
{
  resist = resist/1000; //Mostrar el valor en Kilo ohms
  lcd.print(resist);    //Imprimir valor
  lcd.print('K');       //Imprimir caracter K
  lcd.write(1);         //Imprimir omega
  lcd.print("   ");     //Imprimir espacios para limpiar datos anteriores en en el display
}
delay(300);             //Retaso para evitar comportamientos extraños en la ejecución
}
