const int motor1Pin1=22;
const int motor1Pin2=23;
const int motor2Pin1=24;
const int motor2Pin2=25;
// ------- VAR CNY70 ----------
unsigned int referenciaBlanco = 100;
unsigned int referenciaSinSuperficie = 20;
unsigned int lecturaCNY70 = 0;
// ---------------------------

void setup() {
  Serial.begin(9600); //Configuracion de la velocidad serial
/*
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  digitalWrite(motor1Pin1, HIGH);  
  digitalWrite(motor1Pin2, LOW);  
  digitalWrite(motor2Pin1, HIGH);  
  digitalWrite(motor2Pin2, LOW);
  */  
}

void loop() {
  lecturaCNY70 = analogRead(A0);
/*
  if((lecturaCNY70 >= 0) && (lecturaCNY70 <= referenciaSinSuperficie )) {
    Serial.println("Sin Superficie");
  }
  else if((lecturaCNY70 > referenciaSinSuperficie) && (lecturaCNY70 < referenciaBlanco )) {
    Serial.println("Linea Negra");
    
  }
  else if(lecturaCNY70 >= referenciaBlanco){
    Serial.println("Superficie Blanca");
  }
  */
  Serial.print("Lectura: ");
  Serial.println(lecturaCNY70); //Imprime el valor de la lectura del canal A0
  delay(1000); //retardo de 2 segundos entre lectura
  
// adelante();
//  atras();
//  derecha();
//  izquierda();
//  detener();
//  delay(5000);
}

void adelante(){
  digitalWrite(motor1Pin1, HIGH);  
  digitalWrite(motor1Pin2, LOW);  
  digitalWrite(motor2Pin1, HIGH);  
  digitalWrite(motor2Pin2, LOW);  
  delay(5000);
  }

void atras(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(5000);
  }

void  izquierda(){
  digitalWrite(motor1Pin1, HIGH);  
  digitalWrite(motor1Pin2, LOW);  
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);  
  delay(5000);
  }

void derecha(){
  digitalWrite(motor1Pin1, LOW);  
  digitalWrite(motor1Pin2, LOW);  
  digitalWrite(motor2Pin1, HIGH);  
  digitalWrite(motor2Pin2, LOW);  
  delay(5000);
  }

void detener(){
  digitalWrite(motor1Pin1, LOW);  
  digitalWrite(motor1Pin2, LOW);  
  digitalWrite(motor2Pin1, LOW);  
  digitalWrite(motor2Pin2, LOW);  
  delay(5000);
  }

int detectarColor(int valorCNY){
// 0 = Nada 
// 1 = Negro
// 2 = Rojo
// 3 = Azul
/*
  if (sensorValue>=0 && sensorValue<=20){
    return 0;
  }else if (sensorValue>=60 && sensorValue<=80){
    return 1;
  }else if (sensorValue>=28 && sensorValue<=30){
    return 2;
  }else if (valorCNY>=360 && valorCNY<=400){
    return 3;
  }
  */
  return 0;
}
