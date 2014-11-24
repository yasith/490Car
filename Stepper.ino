struct Stepper {
  int step;
  int dir;
};

struct Stepper right = {11, 10};

void setup() {
  
  Serial.begin(115200);
  
  pinMode(right.step, OUTPUT);
  pinMode(right.dir, OUTPUT);    
}

void loop() {

    move(1, 1, 32 * 16);
    
    delay(1000);
    
    digitalWrite(10, LOW);
  
    for(int i = 0; i < 32 * 16; i++) {
      digitalWrite(right.step, HIGH);
      delay(10);
      digitalWrite(right.step, LOW);
      delay(10);  
    }
  
    delay(1000);
}

void move(int r, int l, int step) {

  if(r > 0) {
    digitalWrite(right.dir, HIGH);  
  } else {
    digitalWrite(right.dir, LOW);
  }
  
   for(int i = 0; i < step; i++) {
      digitalWrite(right.step, HIGH);
      delay(10);
      digitalWrite(right.step, LOW);
      delay(10);  
    }
  
}
