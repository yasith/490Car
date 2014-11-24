
#define STEP 32

struct Stepper {
  int step;
  int dir;
};

struct Stepper right = {9, 8};
struct Stepper left = {11, 10};

void setup() {               
  
  pinMode(right.step, OUTPUT);
  pinMode(right.dir, OUTPUT);       
  pinMode(left.step, OUTPUT);
  pinMode(left.dir, OUTPUT);
  
  //servo.attach(6);
  //servo.write(UP);
}


void loop() {
  move(1, 1, 8);
  move(-1, -1, 8);
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
