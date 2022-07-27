#include <Servo.h>

#define LEYE 8
#define REYE 7
#define PSERVO 6
#define SERVO 10 
#define PIR 0
#define OWL 1

Servo Myservo;
int pos = 0;

long now = 0;
long last = 0;
const int period = 200;

void chipmonkBeGone();
void blink();
void move();


void setup() {
  pinMode(PIR, INPUT);
  pinMode(LEYE, OUTPUT);
  pinMode(OWL, OUTPUT);
  pinMode(REYE, OUTPUT);
  pinMode(PSERVO, OUTPUT);
  digitalWrite(LEYE, 0);
  digitalWrite(REYE, 0);
  digitalWrite(PSERVO, 0);
  digitalWrite(OWL, 1);
  Myservo.attach(SERVO);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PIR) == 1) {
    delay(300);
    if (digitalRead(PIR) == 1){
      digitalWrite(OWL, 0);
      chipmonkBeGone();
      delay(7000);
      digitalWrite(OWL, 1);
    }
  } 
  
}

void chipmonkBeGone() {
  move();
  blink();
}

void blink() {
  for (int i=0; i<10; i++) {
    digitalWrite(REYE, 1);
    digitalWrite(LEYE, 1);   
    delay(50);                       
    digitalWrite(REYE, 0);
    digitalWrite(LEYE, 0);   
    delay(50);
  }
}

void move() { 
  digitalWrite(PSERVO, 1);
  for (pos = 0; pos <= 80; pos+=2) { 
    Myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 80; pos >= 0; pos-=2
  ) { 
    Myservo.write(pos);              
    delay(15);                       
  }  
  digitalWrite(PSERVO, 0);
 }

