#include <Arduino.h>

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include "driveControl.h"

#define LEFTPWM 3
#define LEFTA 2
#define LEFTB 4

#define RIGHTPWM 6
#define RIGHTA 5
#define RIGHTB 7

ros::NodeHandle leftNode;
ros::NodeHandle rightNode;

Controller::Controller Left;
Controller::Controller Right;

DriveControl::DriveControl Control;

void leftCallback(geometry_msgs::Twist& cmd_vel){
    Left.Drive(cmd_vel.linear.x);
}

void rightCallback(geometry_msgs::Twist& cmd_vel){
    Right.Drive(cmd_vel.linear.x);
}

ros::Subscriber<geometry_msgs::Twist> leftSub("leftDrive", leftCallback);
ros::Subscriber<geometry_msgs::Twist> rightSub("rightDrive", rightCallback);

void setup() {
    leftNode.initNode();
    leftNode.subscribe(leftSub);

    rightNode.initNode();
    rightNode.subscribe(rightSub);

    Left.init(LEFTPWM, LEFTA, LEFTB);
    Right.init(RIGHTPWM, RIGHTA, RIGHTB);

    Control.setControllers(Left, Right);
}

void loop() {
    leftNode.spinOnce();
    rightNode.spinOnce();
    delay(1);
}
