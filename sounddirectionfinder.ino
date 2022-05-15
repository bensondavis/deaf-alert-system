/*
 File/Sketch Name: SoundDirectionFinder

 Version No.: v1.0 Created 14 August, 2019
 
 Original Author: Clyde A. Lettsome, PhD, PE, MEM
 
 Description:  This code/sketch makes finding the general direction of sound easy. This code/sketch drives to LEDs to indicate which of two microphones is receiving an audible sound.
 If both microphone sensors detect sound both (left and right) LEDs light indicating that both microphones have detected sound. If one microphone sensor (left or right) detects sound,
 then the corresponding LED (left or right) will light up. If both microphone sensors detect sound then both LEDs will light up.


 License: This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) version 3, or any later
 version of your choice, as published by the Free Software Foundation.

 Notes: Copyright (c) 2019 by C. A. Lettsome Services, LLC
 For more information visit https://clydelettsome.com/blog/2019/08/15/my-weekend-project-sound-direction-tester/

 */

int leftLedPin=13;
int rightLedPin=12;
int rightSensorPin=7;
int leftSensorPin=8;
boolean rightVal = 0;
boolean leftVal = 0;

void setup()
{
  pinMode(leftLedPin, OUTPUT);
  pinMode(rightLedPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop ()
{
  rightVal =digitalRead(rightSensorPin);
  leftVal =digitalRead(leftSensorPin);
  
  // when the sensor detects a signal above the threshold value, LED flashes
  if (leftVal==LOW && rightVal==LOW) 
  {
    digitalWrite(leftLedPin, LOW);
    digitalWrite(rightLedPin, LOW);
    Serial.println("None");
  }
  else if (leftVal==LOW && rightVal==HIGH)
  {
    digitalWrite(leftLedPin, LOW);
    digitalWrite(rightLedPin, HIGH);
    Serial.println("Right");
  }
  else if (leftVal==HIGH && rightVal==LOW)
  {
    digitalWrite(leftLedPin, HIGH);
    digitalWrite(rightLedPin, LOW);
    Serial.println("Left");
  }
  else 
  {
    digitalWrite(leftLedPin, HIGH);
    digitalWrite(rightLedPin, HIGH);
    Serial.println("Both");
  }
}

