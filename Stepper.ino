struct Stepper {
  int step;
  int dir;
};

struct Stepper right = {13, 12};
struct Stepper left = {11, 10};
void setup() {
  
  Serial.begin(115200);
  
  pinMode(right.step, OUTPUT);
  pinMode(right.dir, OUTPUT);    
     
  pinMode(left.step, OUTPUT);
  pinMode(left.dir, OUTPUT);
}

void loop() {
  
 if(Serial.available()) {
    char in = Serial.read();
   
    if(in == 'l'){
      move(1, -1, 32 * 16);
    } 
    if(in == 'r'){
      move(-1, 1, 32 * 16);
    }
    if(in == 'f'){
      move(1, 1, 32 * 16);
    }
    if(in == 'b'){
      move(-1, -1, 32 * 16);  
    }
  }
}

void move(int r, int l, int step) {

  if(r > 0) {
    digitalWrite(right.dir, HIGH);  
  } else {
    digitalWrite(right.dir, LOW);
  }
    
  if(l > 0) {
    digitalWrite(left.dir, LOW);  
  } else {
    digitalWrite(left.dir, HIGH);
  }
  
   for(int i = 0; i < step; i++) {
      digitalWrite(right.step, HIGH);
      digitalWrite(left.step, HIGH);
      delay(10);
      digitalWrite(right.step, LOW);
      digitalWrite(left.step, LOW);
      delay(10);  
    }
  
}
