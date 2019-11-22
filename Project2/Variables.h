// ------ VAR MOTORES ----------
const int motor1Pin1=22;
const int motor1Pin2=23;
const int motor2Pin1=24;
const int motor2Pin2=25;

// ------ VAR INTERRUPTORES ASPIRADO/BARRIDO ----------
const int motorBarrer=33;
const int motorAspi=32;
unsigned int valorSwitch=LOW;

const int intPin = 2;
void verificarSwitchAB();

// ------- VAR CNY70 ----------
unsigned int referenciaBlanco = 100;
unsigned int referenciaSinSuperficie = 20;
unsigned int CNY70Front = 0;
//unsigned int CNY70Right = 0;
//unsigned int CNY70Left = 0;

//------------ SENSOR LATERAL DCHO -----------------
const int TriggerR = 49;
const int EchoR= 48;
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros

//------------ SENSOR FRONTAL ------------------
const int Trigger = 51;   //Pin digital 2 para el Trigger del sensor
const int Echo = 50;   //Pin digital 3 para el echo del sensor

//------------ SENSOR LATERAL IZQ -----------------
const int TriggerL = 53;
const int EchoL = 52;

//--------------BOTON INICIO---------------
const int onOffPin = 3;
bool runStart = false;
void encender();
unsigned int valorSwitchON=LOW;


bool direccion=true;


//------------ SENSOR DE COLOR -----------------
#define S0 26
#define S1 27
#define S2 28
#define S3 29
#define salidaSensor 30
int frecuenciaRojo = 0;
int frecuenciaVerde = 0;
int frecuenciaAzul = 0;



int controlD=0;
