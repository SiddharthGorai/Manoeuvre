// char data = '0';

int IN1 = 11;  //right
int IN2 = 3;   //right
int IN3 = 6;   //left
int IN4 = 5;   //left
int speedH = 150;
int speedT = 0;
int speedL = 0;


int ch1=2;
int ch2=4;

double val1 = 0;
double val2 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

}

void loop() {
val1 = pulseIn(ch1,HIGH);
val2 = pulseIn(ch2,HIGH);

Serial.print("Ch1: ");
Serial.print(val1);
Serial.print("\n");
Serial.print("Ch2: ");
Serial.print(val2);
Serial.print("\n");
// delay(500);

// if(val1 > 1400 && val1 < 1600){
//   forward();
// }
// else if(val1 < 700 && val1 > 500){
//   reverse();
// }
// else{
//   stop();
// }
}

void forward() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedH);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedH);
  // Serial.println("frrward");
}
void reverse() {
  analogWrite(IN1, speedH);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedH);
  analogWrite(IN4, speedL);
}

void right() {
  analogWrite(IN1, speedH);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedH);
}
void left() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedH);
  analogWrite(IN3, speedH);
  analogWrite(IN4, speedL);
}
void stop() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedL);
  Serial.println("stop");
}
