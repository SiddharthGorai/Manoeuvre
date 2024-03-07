#include <IBusBM.h>

IBusBM IBus;


int IN1 = 11;  //right
int IN2 = 3;   //right
int IN3 = 6;   //left
int IN4 = 5;   //left

int vel_thr = 0;
int vel_rotL = 0;
int vel_rotR = 0;

int speedL = 0;
int speedT = 0;


int ch1 = 0;
int ch2 = 0;
int ch3 = 0;
int ch4 = 0;
int ch5 = 0;
int ch6 = 0;


void setup() {

  Serial.begin(115200);
  IBus.begin(Serial);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  ch1 = IBus.readChannel(0);
  ch2 = IBus.readChannel(1);
  ch3 = IBus.readChannel(2);
  ch4 = IBus.readChannel(3);
  ch5 = IBus.readChannel(4);
  ch6 = IBus.readChannel(5);

  // Serial.print("Ch1: ");
  // Serial.print(ch1);
  // Serial.print(" ");
  // Serial.print("Ch3: ");
  // Serial.print(ch3);
  // Serial.print("\n");
  // delay(500);


  // mapping

  vel_thr = map(ch3, 1035, 1990, 0, 255);


  if (ch1 > 1465 && ch1 < 1510){ vel_rotL = 0; vel_rotR = 0;}
  else if (ch1 < 1465) vel_rotL = map(ch1, 1020, 1465, 255, 0);
  else if (ch1 > 1510) vel_rotR = map(ch1, 1510, 1920, 0, 255);

  if (vel_thr < 0) vel_thr = 0;
  else if (vel_thr > 255) vel_thr = 255;

  if (vel_rotL < 0) vel_rotL = 0;
  else if (vel_rotL > 255) vel_rotL = 255;
  if (vel_rotR < 0) vel_rotR = 0;
  else if (vel_rotR > 255) vel_rotR = 255;
  

  if(vel_thr > 10){
    forward(vel_thr);
  } else stop();
  if(vel_rotL > 10){
    left(vel_rotL);
  }
  else if(vel_rotR > 10){
    right(vel_rotR);
  }
  Serial.print(vel_thr);
  Serial.print(" ");
  Serial.print(vel_rotL);
    Serial.print(" ");
  Serial.println(vel_rotR);
 
}

void forward(int vel_thr) {
  analogWrite(IN1, speedL);
  analogWrite(IN2, vel_thr);
  analogWrite(IN3, speedL);
  analogWrite(IN4, vel_thr);
  // Serial.println("frrward");
}
void reverse() {
  analogWrite(IN1, vel_thr);
  analogWrite(IN2, speedL);
  analogWrite(IN3, vel_thr);
  analogWrite(IN4, speedL);
}

void right(int vel_rotR) {
  analogWrite(IN1, vel_rotR);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedL);
  analogWrite(IN4, vel_rotR);
}
void left(int vel_rotL) {
  analogWrite(IN1, speedL);
  analogWrite(IN2, vel_rotL);
  analogWrite(IN3, vel_rotL);
  analogWrite(IN4, speedL);
}
void stop() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedL);
  vel_thr = -1;
  // Serial.println("stop");
}
