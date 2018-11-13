/*
                UNIVERSIDAD TÉCNICA DEL NORTE
                       FICA-CIERCOM
                 SISTEMAS MICROPROCESADOS
   Nombre: Cintya Yanascual
   Fecha: 13/11/2018

*/


//VALIDAR LA CÉDULA

int modulo[] = {2, 1, 2, 1, 2, 1, 2, 1, 2}; //convertidor para la cedula
int cantidad;
int suma1 = 0;
int suma2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String cedula = Serial.readString();
    validarCedula(cedula);
  }
}

void validarCedula(String ced) {

  char num1 = ced.charAt(0);
  char num2 = ced.charAt(1);
  char num3 = ced.charAt(2);
  char num10 = ced.charAt(9);
  int d1 = String(num1).toInt(); //convierte de char a int
  int d2 = String(num2).toInt(); //convierte de char a int
  int d3 = String(num3).toInt(); //convierte de char a int
  int d10 = String(num10).toInt(); //convierte de char a int

  if (ced.length() == 10) {
    if (d1 >= 1 || d1 <= 2 && d2 >= 0 || d2 <= 4) {
      if (d3 < 6 && d3 >= 0) {
        for (int i = 0; i < 9; i++) {
          cantidad = modulo[i] * ((String(ced.charAt(i)).toInt()));
          if (cantidad >= 10) {
            cantidad = cantidad - 9;
          }
          suma1 = suma1 + cantidad;
          suma2 = 10 - (suma1 % 10);
          if (suma2 == 10) {
            suma2 = 0;
          }

        }

        if (suma2 == d10) {
          Serial.println(" La cedula ingresada es correcta");
          delay(200);

        } else {
          Serial.println(" La cedula ingresada es incorrecta");
          delay(200);

        }

      } else {
        Serial.println(" El tercer digito de la cedula ingresada es incorreta");
      }

    } else {
      Serial.println(" Los dos primeros digitos de la cedula ingresada son incorrectos");
      delay(200);
    }
  } else if (ced.length() < 10) {
    Serial.println(" La cedula ingresada tiene menos de diez digitos");
    delay(200);

  } else if (ced.length() > 10) {
    Serial.println(" La cedula ingresada tiene mas de diez digitos");
    delay(200);

  }
  suma1 = 0;
  suma2 = 0;
  cantidad = 0;

}
