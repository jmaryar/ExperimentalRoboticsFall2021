#include "gripper.h"


Gripper::Gripper(){
};

void Gripper::init(int LEFT_SERVO_PWM_PIN, int RIGHT_SERVO_PWM_PIN, int LEFT_SERVO_POS, int RIGHT_SERVO_POS){
    LEFT_SERVO_PWM_PIN = _LEFT_SERVO_PWM_PIN;
    RIGHT_SERVO_PWM_PIN = _RIGHT_SERVO_PWM_PIN;

    LEFT_SERVO.attach(LEFT_SERVO_PWM_PIN);
    RIGHT_SERVO.attach(RIGHT_SERVO_PWM_PIN);

    LEFT_SERVO.write(LEFT_SERVO_POS);
    RIGHT_SERVO.write(RIGHT_SERVO_POS);
}

Gripper::~Gripper(){};

void Gripper::Open() {
   RIGHT_SERVO.write(???????);
   LEFT_SERVO.write(???????);
   delay(100);
};

void Gripper::Close() {
   RIGHT_SERVO.write(???????);
   LEFT_SERVO.write(???????);
   delay(100);
};
