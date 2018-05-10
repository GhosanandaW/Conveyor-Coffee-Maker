#include <Servo.h> 
//servo variable declaration
Servo servo1; 
Servo servo2; 
int pos0=0;
// Sensor variable declaration
int ir1=51;
int ir2=52; 
int ir3=53;
// Driving motor variable declaration
int enA = 2;
int in1 = 22;
int in2 = 3;
// Driving motor 2 variable declaration
int enAb= 6;
int in1b=24;
int in2b=7;  
// Pump variable declaration
int enB = 4;
int in3 = 23;
int in4 = 5;
//Stirrer motor variable declaration
int enBb= 11; 
int in3b=25; 
int in4b=12;  
//initial time for stirrer movement
unsigned long initial_time=0; 


void setup() {
  //servo setup, attached to PWM pin 9
  servo1.attach(9);
  servo2.attach(10); 
  // driver modules setup, where enA and enB (A and B enable, respectively) are components of driving module 1 and enAb is component of driving module 2
  pinMode(ir1, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enAb, OUTPUT); 
  // driver modules setup, where in1, in2, in3, and in4 digital inputs to the driver module 1 
  // driver modules setup, where in1b and in2b are digital inputs to the driver module 2
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in1b, OUTPUT); 
  pinMode(in2b, OUTPUT); 
  pinMode(in3b, OUTPUT); 
  pinMode(in4b, OUTPUT); 
  // serial data transmission in bits per second (baud)
  servo1.write(0);
  servo1.write(0);
  Serial.begin(9600); 
  delay(150);
}

void motoron()
{
  // the function runs the motors 
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in1b, HIGH); 
  digitalWrite(in2b, LOW); 
  // set speed to 255 (range can go from 0 to 255)
  analogWrite(enA, 255);
  analogWrite(enAb, 255); 
}

void pumpon()
{ 
   // turn on the water pump
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 255 (the range is from 0 to 255)
  analogWrite(enB, 255);
}

void pumpR()
{
  // reverse pump flow to empty out residual water inside the tube
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  // set speed to 255 (the range is from 0 to 200)
  analogWrite(enB, 200);
}

void motoroff()
{
  // turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in1b, LOW);
  digitalWrite(in2b, LOW); 
}

void pumpoff()
{
  // turn off pump
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void Powder180()
{
  //turn on servo to 180 degree position, pour out the powder
  servo1.write(180);
  //Serial.println(1);
  delay(1000);
  }

void Powder0()
{ 
  //turn the servo to initial position, closing the powder container
  servo1.write(0);
  delay(1000);
}

void stirrerdown() 
{ 
  //turn on the motor to initiate down rack and pinion movement
  digitalWrite(in3b, HIGH); 
  digitalWrite(in4b, LOW);  
  analogWrite(enBb, 1); 
}

void stirrerstop() 
{ 
  //turn off the motor to keep rack and pinion at a fixed position
  digitalWrite(in3b, LOW); 
   digitalWrite(in4b, LOW);  
}
void stirrerup() 
{
  //turn on the motor to initiate up rack and pinion movement
  digitalWrite(in3b, LOW); 
  digitalWrite(in4b, HIGH);  
  analogWrite(enBb, 1); 
}

void stir() 
{
  //turn on the stirring servo for 5 seconds
initial_time=millis(); 
  while((millis()-initial_time)<5000)
    {
    Serial.println(initial_time);
    servo2.write(180);
    Serial.println("one");
    delay(1000); 
    servo2.write(0);
    Serial.println("two");
    delay(1000); 
    }
}

void loop(){
  motoron();
}

