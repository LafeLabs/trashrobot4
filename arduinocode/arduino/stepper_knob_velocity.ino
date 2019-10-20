
/*
www.trashrobot.org
FREE, PUBLIC DOMAIN
NO COPYRIGHT

*/

int pinArray[] = {10,12,11,13};
int pinIndex = 0;
int pulseTime = 10;//ms
int knob = 512;
int x = 512;

int maxTime = 100;
int minTime = 10;

void setup() {
  Serial.begin(115200);
  pinMode(pinArray[0],OUTPUT);
  pinMode(pinArray[1],OUTPUT); 
  pinMode(pinArray[2],OUTPUT); 
  pinMode(pinArray[3],OUTPUT);
  digitalWrite(pinArray[0],LOW);
  digitalWrite(pinArray[1],LOW);
  digitalWrite(pinArray[2],LOW);
  digitalWrite(pinArray[3],LOW);
  knob = analogRead(A2);  
}

void loop() {
  knob = analogRead(A2);  
  if(knob > 612){
     pulseTime = maxTime - (maxTime - minTime)*(knob - 612.0)/412.0;
     x++;
     digitalWrite(pinArray[x%4],HIGH);
     delay(pulseTime);
     digitalWrite(pinArray[x%4],LOW);
     Serial.println(pinArray[x%4]);  

  }
  if(knob < 412){
     pulseTime = maxTime - (maxTime - minTime)*(412.0 - knob)/412.0;
     x--;
     digitalWrite(pinArray[x%4],HIGH);
     delay(pulseTime);
     digitalWrite(pinArray[x%4],LOW);
     Serial.println(pinArray[x%4]);  
  }
  
  if(x > 1024){
    x = 0;
  }
  if(x < -1024){
    x = 0;
  }
}
 
  
