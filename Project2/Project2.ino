#include "Variables.h"
#include "Setup.h"
#include "Utiles.h"
#include "Colisiones.h"
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  SetupMotores();
  //---------------------------------
  SetupUltrasonico();
  SetUpSensorColor();
  encender();
}

void loop() {
  //    Serial.println("Lectura: ");
  //          Serial.println(medirDistanciaSensorUltrasonico());
  //          Serial.println(medirDistanciaSensorUltrasonicoR());
  //          Serial.println(medirDistanciaSensorUltrasonicoL());
  //    Serial.println(analogRead(A1)); //Imprime el valor de la lectura del canal front
  //    Serial.println(analogRead(A0)); //Imprime el valor de la lectura del canal derecho
  //    Serial.println(analogRead(A2)); //Imprime el valor de la lectura del canal izquierdo

  detener();
  //detectarColorF();

  //    Serial.println(analogRead(A1)); //Imprime el valor de la lectura del canal derecho
  //    delay(1000);

  //girarDerecha();
  //girarIzquierda();
  if (runStart) {} else {
    IA();
    controlD++;
  }

  if (controlD > 5) {
    girarDerecha2();
    controlD = 0;
  }


}





void IA() {
  CalcularTiempo();
  long int ultimoPunto = millis();
  if (runStart) {
    return;
  }
  adelante();
  while (millis() < ultimoPunto + 100) {

  }
    detener();

  if (colisionFront()) {
    tiempoDecision = millis();
    desicionGiro();
    enviarDato((millis() - tiempoDecision) / 60, 5); //Tiempo de desicion
    return;
  }
  if (colisionRight2()) {
    girarIzquierda2();
    return;
  }
  if (colisionLeft2()) {
    girarDerecha2();
    return;
  }


}




void desicionGiro() {
  if (runStart) {
    return;
  }
  if (medirDistanciaSensorUltrasonicoR() < 15 && medirDistanciaSensorUltrasonicoL() < 15) {
    detenerAtras(300);
    detenerAtras(300);
    desicionGiro();
  } else if (medirDistanciaSensorUltrasonicoR() < 15) {
    direccion = false;
  } else if (medirDistanciaSensorUltrasonicoL() < 15) {
    direccion = true;
  }

  if (direccion) {
    detenerAtras(400);
    girarDerecha();
  } else {
    detenerAtras(400);
    girarIzquierda();
  }
}




void girarDerecha() {
  derecha();
  long int ultimoPunto = millis();
  long int tiempo = 0;
  long int tiempoAux = 1200;

  while (millis() < ultimoPunto + tiempoAux) {
    if (runStart) {
      return;
    }
    if (millis() > ultimoPunto + 1000 && colisionFront()) {
      detenerAtras(300);
      tiempoAux = tiempoAux + 600;
      tiempo = tiempo + 600;
      derecha();
    }
    if (colisionRight()) {
      detener();
      izquierda();
      tiempo = tiempo + millis() - ultimoPunto;
      ultimoPunto = millis();
      while (millis() < ultimoPunto + tiempo) {      }
      girarIzquierda();
      return;
    }
  }
  direccion = false;
}

void girarIzquierda() {
  izquierda();
  long int ultimoPunto = millis();
  long int tiempo = 0;
  long int tiempoAux = 850;
  while (millis() < ultimoPunto + tiempoAux) {
    if (runStart) {
      return;
    }
    if (millis() > ultimoPunto + 800 && colisionFront()) {
      detenerAtras(300);
      tiempoAux = tiempoAux + 600;
      tiempo = tiempo + 600;
      izquierda();
    }
    if (colisionLeft()) {
      tiempo = tiempo + millis() - ultimoPunto;
      detener();
      derecha();
      ultimoPunto = millis();
      while (millis() < ultimoPunto + tiempo) {      }
      girarDerecha();
      return;
    }
  }
  direccion = true;
}



void girarDerecha2() {
  detener();
  derecha();
  long int ultimoPunto = millis();
  while (millis() < ultimoPunto + 150) {
    if (runStart) {
      return;
    }
  }
}

void girarIzquierda2() {
  detener();
  izquierda();
  long int ultimoPunto = millis();
  while (millis() < ultimoPunto + 100) {
    if (runStart) {
      return;
    }
  }
}
