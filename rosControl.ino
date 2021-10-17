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

ros::NodeHandle nh;

Controller Left;
Controller Right;

DriveControl Control;

void leftCallback(geometry_msgs::Twist& cmd_vel){
    Left.Drive(cmd_vel.linear.x, 1);
}

void rightCallback(geometry_msgs::Twist& cmd_vel){
    Right.Drive(cmd_vel.linear.x, 1);
}

ros::Subscriber<geometry_msgs::Twist> leftSub("leftDrive", leftCallback);
ros::Subscriber<geometry_msgs::Twist> rightSub("rightDrive", rightCallback);

void setup() {
    nh.initNode();
    nh.subscribe(leftSub);
    nh.subscribe(rightSub);

    Left.init(LEFTPWM, LEFTA, LEFTB);
    Right.init(RIGHTPWM, RIGHTA, RIGHTB);

    Control.setControllers(Left, Right);
}

void loop() {
    nh.spinOnce();
    delay(1);
}
