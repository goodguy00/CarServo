/*
 * Library for moving the car with a L298n board
 *
 * PINS on the board
 * EN A : enable motor A (right)
 * IN 1 : backward :: pinRB
 * IN 2 : foreward :: pinRF
 * EN B : enable motor B (left)
 * IN 3 : foreward :: pinLF
 * IN 4 : backward :: pinLB
 *
 * Tips : set EN-pins to H and regulate speed with PWM (analogWrite) on the digitalPins
 */

#ifndef CarServo_h
#define CarServo_h

#include <Servo.h>
#include <Arduino.h>

// defaults if not given otherwise
#define _pinRB 11
#define _pinRF 10
#define _pinLF 9
#define _pinLB 6

#define _PWM_MIN  0
#define _PWM_SLOW 100
#define _PWM_FAST 191
#define _PWM_MAX  255

#define _move_delay 1

class CarServo{
        public:
                CarServo();
                void begin(
                      int in1
                    , int in2
                    , int in3
                    , int in4
                );
                void foreward(int speed = _PWM_MAX);
                void backward(int speed = _PWM_MAX);
                void fullstop();
                void goright(int speed = _PWM_MAX);
                void goleft(int speed = _PWM_MAX);
                void backright(int speed = _PWM_MAX);
                void backleft(int speed = _PWM_MAX);
                void turnright(int speed = _PWM_FAST);
                void turnleft(int speed = _PWM_FAST);
                void set_delay(int setd); // *100 in ms
        private:
                int move_delay = _move_delay;
                int pinRB; // in 1
                int pinRF; // in 2
                int pinLB; // in 3
                int pinLF; // in 4

};

extern CarServo Car;

#endif
