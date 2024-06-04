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