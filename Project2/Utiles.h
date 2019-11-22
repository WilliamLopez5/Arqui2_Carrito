void adelante() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void atras() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void derecha() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void izquierda() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void detener() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(300);
}

void detenerAtras(int timer) {
  detener();
  atras();
  delay(timer);
  detener();
}


bool detectarColorF() {
  // 0 = Nada
  // 1 = Negro
  // 2 = Rojo
  // 3 = Azul

  // Definiendo la lectura de los fotodiodos con filtro rojo
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaRojo = pulseIn(salidaSensor, LOW);
    
  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaVerde = pulseIn(salidaSensor, LOW);
   
  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaAzul = pulseIn(salidaSensor, LOW);

//    Serial.println("Lectura");
//  // Mostrando por serie el valor para el rojo (R = Red)
//  Serial.print("R = ");
//  Serial.print(frecuenciaRojo);
//  Serial.print(" G = ");
//  Serial.print(frecuenciaVerde);
//  Serial.print(" B = ");
//  Serial.println(frecuenciaAzul);

  
         if (frecuenciaRojo >=18 && frecuenciaRojo <=30 && frecuenciaVerde >=80 && frecuenciaVerde <=110 && frecuenciaAzul >=65 && frecuenciaAzul <=90 ) {
          digitalWrite(motorBarrer, LOW);
          digitalWrite(motorAspi, HIGH);
//          Serial.println("ROJO");
          return false;
  } else if (frecuenciaRojo >=80 && frecuenciaRojo <=110 && frecuenciaVerde >=85 && frecuenciaVerde <=125 && frecuenciaAzul >=30 && frecuenciaAzul <=70 ) {
          digitalWrite(motorBarrer, HIGH);
          digitalWrite(motorAspi, LOW);
//          Serial.println("AZUL");
          return false;
 } else if (frecuenciaRojo >=90 && frecuenciaRojo <=140 && frecuenciaVerde >=150 && frecuenciaVerde <=200 && frecuenciaAzul >=120 && frecuenciaAzul <=185 ) {
//          Serial.println("Negro");
      return true;
  }else {
      return false;

//    Serial.println("Blanco");
  }
  
  return false;
}

int detectarColorR(int valorCNY) {
  // 0 = Nada
  // 1 = Negro
  // 2 = Rojo
  // 3 = Azul

  if (valorCNY >= 80 && valorCNY <= 125) {
    return 1;
  }
  return 0;
}

int detectarColorL(int valorCNY) {
  // 0 = Nada
  // 1 = Negro
  // 2 = Rojo
  // 3 = Azul

  if (valorCNY >= 60 && valorCNY <= 90) {
    return 1;
  }
  return 0;
}


void verificarSwitchAB() {
    digitalWrite(motorBarrer, HIGH);
    digitalWrite(motorAspi, LOW);

//  valorSwitch = digitalRead(intPin);
//  if (valorSwitch == LOW) {
//    digitalWrite(motorBarrer, HIGH);
//    digitalWrite(motorAspi, HIGH);
//  } else {
//    digitalWrite(motorBarrer, LOW);
//    digitalWrite(motorAspi, LOW);
//  }
}

void encender() {
  valorSwitchON = digitalRead(onOffPin);
  if (valorSwitchON == LOW) {
    runStart = true;
    digitalWrite(motorBarrer, LOW);
    digitalWrite(motorAspi, LOW);

  } else {
    digitalWrite(motorBarrer, HIGH);
    digitalWrite(motorAspi, LOW);

    runStart = false;
  }
}

//---------------------------------------


//modo:
//1 velocidad
//2 distancia recorrida
//3 Tiempo del viaje
//4 objetos Evadidos
//5 tiempo decision
void enviarDato(int dato, int modo) {
  char donde[200];
  String hola = String(dato) + ',' + String(modo) + '#' + '\n';
  hola.toCharArray(donde, hola.length() - 1);
  Serial.write(donde);
  Serial.write("#");
}


//------------- Calculo tiempo encendido -------------------
long Minutes = 0;
long Seconds = 0;
long tiempoAnterior = 0;
//--------------------------------------
//---------- int velocidad ----------------------------
int velocidadCarrito = 17; //cm/seg
int contadorObjetoEsquivados = 0;
//----------------------------------------------------
int medioMinuto = 5000;
int opcionEnvio = 0;
int tiempoDecision = 0;
void CalcularTiempo() {
  if (millis() - tiempoAnterior >= medioMinuto) {
    switch (opcionEnvio) {
      case 0://Velocidad
        velocidadCarrito = random(15, 18);
        enviarDato(velocidadCarrito, 1);
        break;
      case 1://Distancia}
        Seconds = millis() / 1000;
        enviarDato((Seconds)*velocidadCarrito, 2);
        break;
      case 2://Tiempo total
        Seconds = millis() / 1000;
        enviarDato((Seconds), 3);
        break;
      case 3:// Objetos esquivados
        enviarDato(contadorObjetoEsquivados, 4);
        opcionEnvio = 0;
        break;
    }
  enviarDato(0,6);
    opcionEnvio++;
    tiempoAnterior = millis();
  }
}
