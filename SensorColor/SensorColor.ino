//
// Cableado de TCS3200 a Arduino
//
#define S0 26
#define S1 27
#define S2 28
#define S3 29

#define salidaSensor 30

// Para guardar las frecuencias de los fotodiodos
int frecuenciaRojo = 0;
int frecuenciaVerde = 0;
int frecuenciaAzul = 0;

void setup() {
  // Definiendo las Salidas
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Definiendo salidaSensor como entrada
  pinMode(salidaSensor, INPUT);

  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Iniciar la comunicacion serie
  Serial.begin(9600);
}
void loop() {
  // Definiendo la lectura de los fotodiodos con filtro rojo
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Leyendo la frecuencia de salida del sensor
  frecuenciaRojo = pulseIn(salidaSensor, LOW);

  Serial.println("Lectura");
  // Mostrando por serie el valor para el rojo (R = Red)
  Serial.print("R = ");
  Serial.print(frecuenciaRojo);
  //  delay(100);

  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Leyendo la frecuencia de salida del sensor
  frecuenciaVerde = pulseIn(salidaSensor, LOW);

  // Mostrando por serie el valor para el verde (G = Green)
  Serial.print(" G = ");
  Serial.print(frecuenciaVerde);
  //  delay(100);

  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Leyendo la frecuencia de salida del sensor
  frecuenciaAzul = pulseIn(salidaSensor, LOW);

  // Mostrando por serie el valor para el azul (B = Blue)
  Serial.print(" B = ");
  Serial.println(frecuenciaAzul);
  int valor = frecuenciaAzul + frecuenciaVerde + frecuenciaRojo;

         if (frecuenciaRojo >=18 && frecuenciaRojo <=30 && frecuenciaVerde >=80 && frecuenciaVerde <=110 && frecuenciaAzul >=65 && frecuenciaAzul <=90 ) {
    Serial.println("Rojo");
  } else if (frecuenciaRojo >=80 && frecuenciaRojo <=110 && frecuenciaVerde >=85 && frecuenciaVerde <=110 && frecuenciaAzul >=30 && frecuenciaAzul <=70 ) {
    Serial.println("Azul");
  } else if (frecuenciaRojo >=90 && frecuenciaRojo <=120 && frecuenciaVerde >=150 && frecuenciaVerde <=200 && frecuenciaAzul >=120 && frecuenciaAzul <=165 ) {
    Serial.println("Negro");
  } else {
    Serial.println("Blanco");
  }
//
//  if (frecuenciaRojo >= && frecuenciaRojo <= && && frecuenciaAzul <= && frecuenciaAzul >= ) {
//    Serial.println("Rojo");
//  } else if (frecuenciaRojo >= && frecuenciaRojo <= && frecuenciaAzul <= && frecuenciaAzul >= ) {
//    Serial.println("Azul");
//  } else if (frecuenciaRojo >= && frecuenciaRojo <= && frecuenciaAzul <= && frecuenciaAzul >= ) {
//    Serial.println("Negro");
//  } else {
//    Serial.println("Blanco");
//  }
//
//  if (frecuenciaRojo >= && frecuenciaRojo <= ) {
//    Serial.println("Rojo");
//  } else if (frecuenciaRojo >= && frecuenciaRojo <= ) {
//    Serial.println("Azul");
//  } else if (frecuenciaRojo >= && frecuenciaRojo <= ) {
//    Serial.println("Negro");
//  } else {
//    Serial.println("Blanco");
//  }
//
//
//  if (valor <= 65) {
//    Serial.println("Blanco");
//  }  else if (valor >= 90 && valor <= 180) {
//    if (frecuenciaRojo <= 25) {
//      Serial.println("Rojo");
//    } else {
//      Serial.println("Azul");
//    }
//  } else if (valor >= 190) {
//    Serial.println("Negro");
//  } else {
//    Serial.println("Nada");
//  }


  //if(frecuenciaRojo<=20){
  //      Serial.println("Blanco");
  //  }  else if (frecuenciaRojo <= 25){
  //
  //    }  else if (frecuenciaRojo<=60&&frecuenciaRojo <= 90){
  //
  //    }else if (frecuenciaRojo<=60&&frecuenciaRojo <= 90){
  //      Serial.println("Azul");
  //    }else if (frecuenciaRojo<=60&&frecuenciaRojo <= 90){
  //      Serial.println("Azul");
  //    }

  //  if (valor <= 65) {
  //    Serial.println("Blanco");
  //  }  else if (valor >= 90&&valor <= 180) {
  //    if (frecuenciaRojo <= 25) {
  //      Serial.println("Rojo");
  //    } else {
  //      Serial.println("Azul");
  //    }
  //  } else if (valor >= 190){
  //    Serial.println("Negro");
  //  }else{
  //    Serial.println("Nada");
  //    }

  delay(2000);



}
