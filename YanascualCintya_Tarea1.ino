/*UNIVERSIDAD TÉCNICA DEL NORTE
          FICA-CIERCOM
    SISTEMAS MICROPROCESADOS
Nombre: Cintya Yanascual
Fecha: 25/10/2018
            Tarea N°1
*/

/*1.- JUEGO DE LUCES QUE SE PRENDEN LOS LEDS IMPARES (1,3,5)*/
int leds[6] = {7, 8, 9, 10, 11, 12}; //Se define el vector para configurar los leds
int i = 0; //variable de recorrido del vector


void setup() {
  // put your setup code here, to run once:
  for (i; i < 6; i++) {    
    pinMode(leds[i], OUTPUT); //Se define los pines a utilizar como OUTPUT==>salida
    randomSeed(4);  // Sirve para dar un comienzo al número randómico
  }
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
   for(i=1;i<6;i=i+2){
    digitalWrite(leds[i],HIGH); //Se pone en HIGH o alto (encendido) la posición i del vector
    delay(500);    //tiempo de espera en ms            
   }
   for(;i>=0;i=i-2){
    digitalWrite(leds[i],LOW); //Se pone en LOW o bajo (apagado) la posición i del vector
    delay(500); 
   }
i=0;

/*2.- SE ENCIENDEN UNO POR UNO LOS LEDS PARES (0,2,4)*/
for(;i<6;i=i+2){
    digitalWrite(leds[i],HIGH); //Se pone en HIGH o alto (encendido) la posición i del vector
    delay(500);                 //tiempo de espera en ms
    digitalWrite(leds[i],LOW); //Se pone en LOW o bajo (apagado) la posición i del vector
    delay(500); 
}
i=0;

/*3.- JUEGO QUE SE ENCIENDAN Y APAGUEN LOS LEDS DE FORMA ALEATORIA (RANDOM)*/

for(;i<6;i++){
int  r=random(1,7);  //Sirve para dar números aleatorios, se empieza desde uno y al número mayor que se utilizará en este caso para los leds que son 6 se suma 1
    digitalWrite(leds[r],HIGH); //Se pone en HIGH o alto (encendido) la posición i del vector
    delay(500);                 //tiempo de espera en ms
    digitalWrite(leds[r],LOW); //Se pone en LOW o bajo (apagado) la posición i del vector
    delay(500);
} 
i=0;
delay(1000);
}
