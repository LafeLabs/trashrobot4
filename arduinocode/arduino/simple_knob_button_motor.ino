
int knob = 0;
int fwdpin = 3;
int rvspin = 2;

int fwddrivepin = 9;
int rvsdrivepin = 10;
boolean fwd = false;
boolean rvs = false;

void setup() {
    pinMode(11,OUTPUT); 
    pinMode(12,OUTPUT); 
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    pinMode(fwddrivepin,OUTPUT); 
    pinMode(rvsdrivepin,OUTPUT); 
    analogWrite(fwddrivepin,0);
    analogWrite(rvsdrivepin,0);
    pinMode(fwdpin,INPUT_PULLUP); 
    pinMode(rvspin,INPUT_PULLUP); 
    knob = analogRead(A2);
    Serial.begin(9600);

}

void loop() {
  knob = analogRead(A2);
  fwd = !digitalRead(fwdpin);
  rvs = !digitalRead(rvspin);
  if(fwd && !rvs){
    analogWrite(rvsdrivepin,0);
    analogWrite(fwddrivepin,knob/4);
  }
  else{
    analogWrite(rvsdrivepin,0);

    analogWrite(fwddrivepin/4,0);
  }
  if(rvs && !fwd){
    analogWrite(fwddrivepin,0);
    analogWrite(rvsdrivepin,knob/4);
  }
  else{
    analogWrite(fwddrivepin,0);
    analogWrite(rvsdrivepin,0);
  }
   Serial.println(knob); 
}
