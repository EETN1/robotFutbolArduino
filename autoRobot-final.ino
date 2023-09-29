int motorUno1 = 6;
int motorUno2 = 7;
//int velocidadMotorUno = 5;
int motorDos1 = 8;
int motorDos2 = 9;
//int velocidadMotorUno = 5;
char crt;
#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
// para comunicacion serie

SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX

void setup() {
  pinMode(motorUno1, OUTPUT);
  pinMode(motorUno2, OUTPUT);
  //pinMode(velocidadMotorUno,OUTPUT);
  pinMode(motorDos1, OUTPUT);
  pinMode(motorDos2, OUTPUT);
  //pinMode(velocidadMotorDos,OUTPUT);
  Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
  Serial.println("Listo");  // escribe Listo en el monitor
  pinMode(13, OUTPUT);
  //miBT.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  miBT.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  digitalWrite(13, HIGH);
}

void loop() {

  if (miBT.available()) {      // si hay informacion disponible desde modulo
    //Serial.write(miBT.read());   // lee Bluetooth y envia a monitor serial de Arduino
    crt = miBT.read();
    // Serial.println(crt);
    //delay(1000);
    if (crt == 'w') {
      digitalWrite(motorUno1, HIGH);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, HIGH);
      digitalWrite(motorDos2, LOW);
      Serial.println("Adelante");
      delay(250);
    } else {
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, LOW);
    }
    if (crt == 's') {
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, HIGH);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, HIGH);
      Serial.println("Atras");
      delay(250);
    } else {
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, LOW);
    }
    if (crt == 'd') {
      digitalWrite(motorUno1, HIGH);
      digitalWrite(motorDos2, HIGH);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      Serial.println("Derecha");
      delay(100);
    } else {
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, LOW);
    }
    if (crt == 'a') {
      digitalWrite(motorUno2, HIGH);
      digitalWrite(motorDos1, HIGH);
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorDos2, LOW);
      Serial.println("Izquierda");
      delay(100);
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, LOW);
    } else {
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, LOW);
    }
    if (crt == 'x') {
      digitalWrite(motorUno1, LOW);
      digitalWrite(motorUno2, LOW);
      digitalWrite(motorDos1, LOW);
      digitalWrite(motorDos2, LOW);
      Serial.println("Detener");

    }
  }




}
