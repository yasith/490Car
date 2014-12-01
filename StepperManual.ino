#include <Servo.h>

#define STEP 32
#define TURN 16

#define UP 135
#define DOWN 90

struct Stepper {
  int step;
  int dir;
};

struct Stepper right = {13, 12};
struct Stepper left = {11, 10};
int m = 1;

Servo servo;

void setup() {               
  
  Serial.begin(115200);
  
  pinMode(right.step, OUTPUT);
  pinMode(right.dir, OUTPUT);       
  pinMode(left.step, OUTPUT);
  pinMode(left.dir, OUTPUT);
  
  servo.attach(10);
  servo.write(UP);
}


void loop() {
  
  if(Serial.available()) {
    char in = Serial.read();
   
    if(in == 'l'){
      move(1, -1, TURN);
    } 
    if(in == 'r'){
      move(-1, 1, TURN);
    }
    if(in == 'f'){
      move(1, 1, 1);
    }
    if(in == 'b'){
      move(-1, -1, 1);  
    }
    if(in == 'm'){
      servo.write(m == 1 ? DOWN : UP);
      m = m == 1 ? 0 : 1;  
    }
  }
}

void move(int l, int r, int steps){
  
  digitalWrite(right.dir, l > 0 ? HIGH : LOW);
  digitalWrite(left.dir, r > 0 ? HIGH : LOW); 

  for(int i = 0; i < STEP * steps; i++) {
    digitalWrite(right.step, HIGH);
    digitalWrite(left.step, HIGH);
    delay(5);
    digitalWrite(right.step, LOW);
    digitalWrite(left.step, LOW);
    delay(5);
  }
}
