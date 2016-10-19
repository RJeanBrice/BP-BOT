
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
LiquidCrystal lcd(12, 11, 10, 8, 9, 7);


// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
    lcd.begin(16, 2);


      lcd.clear();
      lcd.print(" Auto Jog Mode! ");
      lcd.setCursor(0,1); 
      lcd.print("     READY!");

      AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

void loop() {
  // put your main code here, to run repeatedly:

}
