
// Author: Reggie Jean-Brice
// Date: 4/28/2014
// Objective: Code for the z stage dominator. The z stage dominator is a device that moves the z stage up and down independently from the main electronics of a 3d printer. 
//            Mainly used on the assembly line during z stage assembly

#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *RightMotor = AFMS.getMotor(2);


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 lcd.begin(16, 2);


  lcd.clear();
  lcd.print(" BEER PONG BOT! ");
  lcd.setCursor(0,1); 
  lcd.print("     READY!");

  AFMS.begin();  // create with the default frequency 1.6KHz
//AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  forward(150,159);
  delay(1000);
  left(150,150);
  delay(1000);
  backward(150,150);
  delay(1000);
  right(150,150);  
}

void loop() {
  // put your main code here, to run repeatedly:

 int count = 0;
 
 while (count < 6) {
  
  forward(150,159);
  delay(250);
  left(150,150);
  delay(250);
  backward(150,150);
  delay(250);
  right(150,150);
  delay(250);

  count++;
 }

 
}

void forward(int SetSpeed, double cycles) {
   uint8_t i;

  Serial.println("moving forward");

  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
  
  for (i=0; i<cycles; i++) {
    LeftMotor->setSpeed(SetSpeed);  
    RightMotor->setSpeed(SetSpeed);  
    delay(10);
    Serial.println(i);
  }

  Serial.println("shut motor off");
  
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);  

  return;
}

void backward(int SetSpeed, int cycles) {
   uint8_t i;

  Serial.print("moving forward");

  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);
  
  for (i=0; i<cycles; i++) {
    LeftMotor->setSpeed(SetSpeed);  
    RightMotor->setSpeed(SetSpeed);  
    delay(10);
  }
  
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);  
  

  return;
}

void left(int SetSpeed, int cycles) {
   uint8_t i;

  Serial.print("moving forward");

  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  
  for (i=0; i<cycles; i++) {
    LeftMotor->setSpeed(SetSpeed);  
    RightMotor->setSpeed(SetSpeed);  
    delay(10);
  }
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);  
  

  return;
}

void right(int SetSpeed, int cycles) {
   uint8_t i;

  Serial.print("moving forward");

  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  
  for (i=0; i<cycles; i++) {
    LeftMotor->setSpeed(SetSpeed);  
    RightMotor->setSpeed(SetSpeed);  
    delay(10);
  }
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);  
  

  return;
}
