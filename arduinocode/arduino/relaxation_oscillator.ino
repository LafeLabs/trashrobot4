/*
 * TRASH ROBOT RELAXATION OSCILLATOR BOARD PROGRAM
 * 
 * NO COPYRIGHTS NO PATENTS NO PROPERTY NO MONEY NO MINING
 * 
 * 
 * 
 */


int v0Pin = A1;
int deltavPin = A2;
int signalPin = A0;

int deltav = 100;
int v0 = 500;

int x = 0;

int outPin = 5;

void setup() {
  Serial.begin(115200);
  pinMode(outPin,OUTPUT); 
  digitalWrite(outPin,LOW); 
  deltav = analogRead(deltavPin)/2;//range from 0  to 512 
  v0 = analogRead(v0Pin); //whole range
}

void loop() {
  deltav = analogRead(deltavPin);
  v0 = analogRead(v0Pin);
 // v0 = 512;
//  deltav = 100;
  x = analogRead(signalPin);
  if((x > v0 + deltav) || (x > 1010)){
    digitalWrite(outPin,LOW);
  }

  if((x < v0 - deltav) || (x < 10)){
    digitalWrite(outPin,HIGH);
  }

  Serial.println(x);
//  delay(1);

}
