
int knob = 0;
int fwdpin = 3;
int rvspin = 2;

int fwddrivepin = 13;
int rvsdrivepin = 12;
boolean fwd = false;
boolean rvs = false;

void setup() {
    pinMode(10,OUTPUT); 
    pinMode(11,OUTPUT); 
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    pinMode(fwddrivepin,OUTPUT); 
    pinMode(rvsdrivepin,OUTPUT); 
    analogWrite(fwddrivepin,0);
    analogWrite(rvsdrivepin,0);
    pinMode(fwdpin,INPUT_PULLUP); 
    pinMode(rvspin,INPUT_PULLUP); 
    knob = analogRead(A2);
      Serial.begin(115200);

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
