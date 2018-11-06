/*
            UNIVERSIDAD TÉCNICA DEL NORTE
                    FICA-CIERCOM
              SISTEMAS MICROPROCESADOS
   Nombre: Cintya Yanascual
   Fehca: 06/11/2018

*/

// Contador del 1 al 200 sin pulsador

int A = 5;
int B = 4;
int C = 3;
int D = 2;
int i = 0;
int dec = 9;
int uni = 8;
int cen = 10;
int unidades;
int decenas;
int centenas;

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(dec, OUTPUT);
  pinMode(uni, OUTPUT);
  pinMode(cen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (i <= 200) {
    i++;
    unidades = i - ((i/10)*10);
    decenas = ((i%100)/(10));
    centenas = i / 100;

  } else {
    i = 0;
    unidades = 0;
    decenas = 0;
    centenas = 0;

  }


digitalWrite(uni, HIGH);
digitalWrite(dec, LOW);
digitalWrite(cen, LOW);
contador(unidades);
delay(100);

digitalWrite(uni, LOW);
digitalWrite(dec, HIGH);
digitalWrite(cen, LOW);
contador(decenas);
delay(100);

digitalWrite(uni, LOW);
digitalWrite(dec, LOW);
digitalWrite(cen, HIGH);
contador(centenas);
delay(100);


}
void contador(int j) {
  switch (j) {
    //0
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //1
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //2
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //3
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //4
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      delay(300);

    //5
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //6
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //7
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //8
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;

    //9
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}
