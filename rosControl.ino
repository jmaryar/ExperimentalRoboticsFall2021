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

void driveCallback(geometry_msgs::Twist& cmd_vel){
    bool direction = FORWARD;
    if (cmd_vel.linear.x == 0){
        Left.Stop();
        Right.Stop();
    } else if (cmd_vel.linear.x < 0){
        direction = BACKWARD;
    }
    Left.Drive(100, direction);
    Right.Drive(100, direction);
}

void leftTurnCallback(geometry_msgs::Twist& cmd_vel){
    Left.Drive(cmd_vel.linear.x*255, 1);
}

void rightTurnCallback(geometry_msgs::Twist& cmd_vel){
    Right.Drive(cmd_vel.linear.x*255, 1);
}
ros::Subscriber<geometry_msgs::Twist> driveSub("drive", driveCallback);
ros::Subscriber<geometry_msgs::Twist> leftSub("leftTurn", leftTurnCallback);
ros::Subscriber<geometry_msgs::Twist> rightSub("rightTurn", rightTurnCallback);

void setup() {
    nh.initNode();
    nh.subscribe(driveSub);
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
