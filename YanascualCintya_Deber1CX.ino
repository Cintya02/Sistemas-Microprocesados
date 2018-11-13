/*
                  UNIVERSIDAD TÉCNICA DEL NORTE
                        FICA-CIERCOM
                   SISTEMAS MICROPROCESADOS
    Nombre: Cintya Yanascual
    Fecha: 13/11/2018
*/

//Realizar un sistema que permite determinar el número de vocales dentro de una palabra.

#include<stdlib.h> //->conversiones lenguaje c


int i = 0;
String str;
int tam = 0;
int conv = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    str = Serial.readString();
    tam = str.length(); // tamaño de string
    char vector[tam];
    str.toCharArray(vector, tam + 1);
    for (i = 0; i <= tam; i++) {
      if (vector[i] == 'A' || vector[i] == 'E' || vector[i] == 'I' || vector[i] == 'O' || vector[i] == 'U') {
        conv++;

      }

    }

    Serial.println(conv);
  }


}
