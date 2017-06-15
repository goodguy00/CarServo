/*
 * Library for moving the car with a L298n board
 */

#include "CarServo.h"

CarServo::CarServo(){
}

void CarServo::begin(
    int in1
  , int in2
  , int in3
  , int in4
){
  pinRF=in1;
  pinRB=in2;
  pinLB=in3;
  pinLF=in4;
  pinMode(pinRB,OUTPUT);
  pinMode(pinRF,OUTPUT);
  pinMode(pinLB,OUTPUT);
  pinMode(pinLF,OUTPUT);
//  Serial.begin(9600);
}

void CarServo::foreward(int speed = _PWM_MAX)
{
  analogWrite(pinRB,_PWM_MIN);
  analogWrite(pinRF,speed);
  analogWrite(pinLB,_PWM_MIN);
  analogWrite(pinLF,speed);
  delay(move_delay * 100);
//   Serial.print("FWD::");
//   Serial.print(pinRF);
//   Serial.print("::");
//   Serial.println(speed);
}

void CarServo::backward(int speed = _PWM_MAX)
{
  analogWrite(pinRB,speed);
  analogWrite(pinRF,_PWM_MIN);
  analogWrite(pinLB,speed);
  analogWrite(pinLF,_PWM_MIN);
  delay(move_delay * 100);
//   Serial.print("BCK::");
//   Serial.print(pinRF);
//   Serial.print("::");
//   Serial.println(speed);
}

void CarServo::fullstop()
{
  analogWrite(pinRB,_PWM_MAX);
  analogWrite(pinRF,_PWM_MAX);
  analogWrite(pinLB,_PWM_MAX);
  analogWrite(pinLF,_PWM_MAX);
  delay(move_delay * 100);
}

void CarServo::goleft(int speed = _PWM_MAX)
{
  analogWrite(pinRB,_PWM_MIN);
  analogWrite(pinRF,speed);
  analogWrite(pinLB,speed/2);
  analogWrite(pinLF,speed);
  delay(move_delay * 100);
}

void CarServo::goright(int speed = _PWM_MAX)
{
  analogWrite(pinRB,speed/2);
  analogWrite(pinRF,speed);
  analogWrite(pinLB,_PWM_MIN);
  analogWrite(pinLF,speed);
  delay(move_delay * 100);
}

void CarServo::backleft(int speed = _PWM_MAX)
{
  analogWrite(pinRB,speed);
  analogWrite(pinRF,_PWM_MIN);
  analogWrite(pinLB,speed);
  analogWrite(pinLF,speed/2);
  delay(move_delay * 100);
}

void CarServo::backright(int speed = _PWM_MAX)
{
  analogWrite(pinRB,speed);
  analogWrite(pinRF,speed/2);
  analogWrite(pinLB,speed);
  analogWrite(pinLF,_PWM_MIN);
  delay(move_delay * 100);
}

void CarServo::turnleft(int speed = _PWM_FAST)
{
  analogWrite(pinRB,_PWM_MIN);
  analogWrite(pinRF,speed);
  analogWrite(pinLB,speed);
  analogWrite(pinLF,_PWM_MIN);
  delay(move_delay * 100);
}

void CarServo::turnright(int speed = _PWM_FAST)
{
  analogWrite(pinRB,speed);
  analogWrite(pinRF,_PWM_MIN);
  analogWrite(pinLB,_PWM_MIN);
  analogWrite(pinLF,speed);
  delay(move_delay * 100);
}

void CarServo::set_delay(int setd)
{
  move_delay=setd;
}

CarServo Car=CarServo();
