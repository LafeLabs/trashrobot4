/*
 * TRASH ROBOT SIMPLE ANALOG READ
 * 
 * NO COPYRIGHTS NO PATENTS NO PROPERTY NO MONEY NO MINING
 * 
 * 
 * foo
 */

int mainPin = A1;
int x = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  x = analogRead(mainPin);
  Serial.println(x);
}
