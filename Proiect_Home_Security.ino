//definim frecventa si viteza sunetului
#define SOUND_SPEED (0.0343)
#define FREQ 1200
//pinul 10 e folosit de buzzer
const int buzzerPin = 10;
const int redLEDPin=13;
const int greenLEDPin=12;
const int stateLEDPin=8;
//citire senzor ultrasonic
const int echoHQPin=5;
//trimitere senzor ultrasonic
const int trigHQPin=6;
//analog pin for smoke detector
const int smokeDetectorPin=A0;
const int potetiometerPin=A1;
unsigned int systemState=0;
unsigned long elapsedTime=0;
unsigned int distance;
unsigned int smokeThreshold=400;
unsigned int smokeLevel;
unsigned int smokeDetected=0;
// senzor de sunet pin digital
// ia sunetul ca intrare digitala
// pin de intrerupere
unsigned int soundPin=3;
// buton pe pinul 2
unsigned int pushButtonPin=2;
unsigned int soundDetected=0;
unsigned int intruderDetected=0;
int myDelay(int val)
{
for(int i=0;i<val;i++)
  delay(100);
}
void soundDetectedRoutine()
{
  soundDetected=1;
}
void pushButtonDetected()
{
  systemState=!systemState;
  delayMicroseconds(50);
  intruderDetected=0;
  soundDetected=0;
  smokeDetected=0;
}
void setup()
{
  pinMode(redLEDPin,OUTPUT);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(stateLEDPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(trigHQPin,OUTPUT);
  pinMode(echoHQPin,INPUT);
  pinMode(soundPin,INPUT_PULLUP);
  pinMode(smokeDetectorPin,INPUT);
  pinMode(potetiometerPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(soundPin),soundDetectedRoutine,HIGH);
  attachInterrupt(digitalPinToInterrupt(pushButtonPin),pushButtonDetected,RISING);
  Serial.begin(9600);
  Serial.println("Ultrasonic sensor:");
}

void loop()
{
    digitalWrite(stateLEDPin,systemState);
    smokeLevel=analogRead(smokeDetectorPin);
    smokeThreshold=analogRead(potetiometerPin);
    Serial.print("Potentiometer: ");
    Serial.println(smokeThreshold);
    digitalWrite(trigHQPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigHQPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigHQPin,LOW);
    //citeste echoHQPin; returneaza timpul de transmitere in microsecunde
    elapsedTime=pulseIn(echoHQPin,HIGH);
    distance=elapsedTime*SOUND_SPEED/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.print("Smoke: ");
    Serial.println(smokeLevel);
    Serial.println(systemState);
    if(distance<=10)
    {
      intruderDetected=1;
    }
    if(smokeLevel>smokeThreshold)
    {
      smokeDetected=1;
    }
    if((intruderDetected||soundDetected||smokeDetected)&&systemState)
    {
    digitalWrite(redLEDPin,HIGH);
    digitalWrite(greenLEDPin,LOW);
    tone(buzzerPin,FREQ,50);
    myDelay(5);
    }
    else
    {
      digitalWrite(redLEDPin,LOW);
      digitalWrite(greenLEDPin,HIGH);
    }
}
