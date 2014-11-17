#include <Servo.h>
#include <Stepper.h>

#define STEPS 32*16

#define UP 135
#define DOWN 90

Stepper stepper1(STEPS, 9, 8);
Stepper stepper2(STEPS, 12, 13);

Servo servo;

int stepSpeed = 200;

int l = 0;
int r = 0;
int m = 1; // 1 = UP, 0 = DOWN

int pos = 0;

void setup() {
  
  Serial.begin(115200);

  servo.attach(6);
  servo.write(UP);
  
  stepper1.setSpeed(stepSpeed);
  stepper2.setSpeed(stepSpeed);
}

void loop() {
  
  if(Serial.available()){
    char inByte = Serial.read();

    if(inByte == 'l'){
      l = 1;
      r = 0;
    }
    if(inByte == 'r'){
      r = 1;
      l = 0;
    }
    if(inByte == 'f'){
      l = 1;
      r = 1;
    }
    if(inByte == 's'){
      l = 0;
      r = 0;
    }
    if(inByte == 'm'){
      servo.write(m == 1 ? DOWN : UP);
      m = m == 1 ? 0 : 1;
    }
    
    Serial.println("Moved");
    Serial.println(inByte); 
  }
  
  // put your main code here, to run repeatedly:
    if(l == 1){
      stepper1.step(100);
    }else {
      stepper1.step(1);
    }
    if(r == 1){
      stepper2.step(100);
    }else {
      stepper2.step(1);
    }
}
