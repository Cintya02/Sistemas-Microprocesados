/*  UNIVERSIDAD TECNICA DEL NORTE
      FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
  CARRERA DE INGENIERIA ELECTRONICA Y REDES DE COMUNICACION
    NOMBRE: Sofia Lopez
    DEBER: validador de cedula*/
#include<stdlib.h>     // -> conversiones lenguaje C

String cedula;
char digito0;
char digito1;
char digito2;
int suma = 0;
int digito = 0;
int tam;
int i = 0;
char verificador;
char guion;
int total = 0;
void setup() {
  Serial.begin(9600);

}
void loop() {
  if (Serial.available() > 0) {
    cedula = Serial.readString();

    digito0 = cedula.charAt(0);
    digito1 = cedula.charAt(1);
    digito2 = cedula.charAt(2);
    verificador = cedula.charAt(9);

    int d0 = String(digito0).toInt();
    int d1 = String(digito1).toInt();
    int d2 = String(digito2).toInt();
    int d10 = String(verificador).toInt();

    int validador[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};

    tam = cedula.length();
    if (tam == 10 ) {

      if ( ( d0 >= 0 || d0 <= 2) && (d1 >= 0 || d1 <= 4) && ( d2 >= 0 || d2 < 6)) {
        for (i; i <= 8 ; i++) {
          digito = validador[i] * (String(cedula.charAt(i)).toInt());
          if (digito >= 10) {
            digito = digito - 9;
          }
          suma = suma + digito;
        }
        total = 10 - (suma % 10);
        if (total == d10) {
          total = 0;
          Serial.println("La cedula ingresada es correcta");
          delay(100);
        }
      } else {
        Serial.println("Cedula incorrecta, no cumple los tres primeros digitos");
        delay(100);
      }
    } else  if (tam < 10) {
      Serial.println("la cedula tiene menos de 10 digitos");
      delay(100);
    }
    suma = 0;
    digito = 0;
    total = 0;
  }

}
