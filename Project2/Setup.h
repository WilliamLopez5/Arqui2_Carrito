void SetupMotores() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motorBarrer, OUTPUT);
  pinMode(motorAspi, OUTPUT);

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  pinMode(intPin, INPUT_PULLUP);
  pinMode(onOffPin, INPUT_PULLUP);
  verificarSwitchAB();
  encender();

  attachInterrupt(digitalPinToInterrupt(intPin), verificarSwitchAB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(onOffPin), encender, CHANGE);

}
void SetupUltrasonico() {
  //------------- Sensor Frontal -----------------
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  //---------- Sensor izq -------------------------
  pinMode(TriggerL, OUTPUT); //pin como salida
  pinMode(EchoL, INPUT);  //pin como entrada
  digitalWrite(TriggerL, LOW);//Inicializamos el pin con 0
  //----------- Sensor dcho -----------------------
  pinMode(TriggerR, OUTPUT); //pin como salida
  pinMode(EchoR, INPUT);  //pin como entrada
  digitalWrite(TriggerR, LOW);//Inicializamos el pin con 0
  //-------------------------------------------------------

}

void SetUpSensorColor() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Definiendo salidaSensor como entrada
  pinMode(salidaSensor, INPUT);

  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

}

int medirDistanciaSensorUltrasonico() {
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59;           //escalamos el tiempo a una distancia en cm

  return d;
}

int medirDistanciaSensorUltrasonicoL() {
  digitalWrite(TriggerL, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(TriggerL, LOW);

  t = pulseIn(EchoL, HIGH); //obtenemos el ancho del pulso
  d = t / 59;           //escalamos el tiempo a una distancia en cm

  return d;
}

int medirDistanciaSensorUltrasonicoR() {
  digitalWrite(TriggerR, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(TriggerR, LOW);

  t = pulseIn(EchoR, HIGH); //obtenemos el ancho del pulso
  d = t / 59;           //escalamos el tiempo a una distancia en cm

  return d;
}
