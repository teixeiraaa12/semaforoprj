//gerencia o sinal de Wifi
#include <WiFi.h>
#include <WiFiClient.h>
//gera servico http no esp32
#include <WebServer.h>
#include <string.h>
WebServer Server(80);
//definição nome, senha e canal do wifi
//#define WIFI_SSID "devsenai"
//#define WIFI_PASSWORD "sesisenai"
//#define WIFI_CHANNEL 6
const char *ssid = "WifiTeixeira";
const char *password = "123456789";
IPAddress local_IP(192, 168, 4, 22);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);

const int ledRed1 = 15;
const int ledYel1 = 2;
const int ledGreen1 = 4;
const int ledRed2 = 5;
const int ledYel2 = 18;
const int ledGreen2 = 19;

int timeYellow = 3000;
int timeGreen = 5000;
int timeRed = 8000;


void setup(){
 Serial.begin(115200);
  //Configuração do Acess Point que ira ser fornecido pelo ESP32
  Serial.print("Configurando AP.....");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet)? "OK" : "Erro");
  Serial.println("Iniciando o Wifi.....");
  Serial.println(WiFi.softAP(ssid, password)? "OK" : "Erro");
  Serial.print("Endereço IP");
  Serial.println(WiFi.softAPIP());

  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  pinMode(ledYel1, OUTPUT);
  pinMode(ledYel2, OUTPUT);
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
  }


  void loop(){
  semaforo();

  }

  void semaforo(){

 acendeLed(ledRed2);
 acendeLed(ledGreen1);
 delay(timeGreen);
 apaga(ledGreen1);
 acendeLed(ledYel1);
 delay(timeYellow);
 apaga(ledYel1);
 apaga(ledRed2);
 acendeLed(ledRed1);
 acendeLed(ledGreen2);
 delay(timeGreen);
  apaga(ledGreen2);
 acendeLed(ledYel2);
 delay(timeYellow);
 apaga(ledRed1);
 apaga(ledYel2);


  }
  void acendeLed(int led){
    digitalWrite(led, HIGH);
  }

    void apaga(int led){
digitalWrite(led,LOW);
    }