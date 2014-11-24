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
    digitalWrite(10, HIGH);

    for(int i = 0; i < 32 * 16; i++) {
      digitalWrite(11, HIGH);
      delay(10);
      digitalWrite(11, LOW);
      delay(10);  
    }
    
    delay(1000);
    
    digitalWrite(10, LOW);
  
    for(int i = 0; i < 32 * 16; i++) {
      digitalWrite(11, HIGH);
      delay(10);
      digitalWrite(11, LOW);
      delay(10);  
    }
  
    delay(1000);
}
