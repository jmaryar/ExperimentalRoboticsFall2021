#include <Arduino.h>

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include "driveControl.h"

#include <package_name/TutorialsConfig.h> NOTE! CHANGE string 'Tutorials' to whatever you use in dynamic reconfigure cfg file"

#define LEFTPWM 3
#define LEFTA 2
#define LEFTB 4

#define RIGHTPWM 6
#define RIGHTA 5
#define RIGHTB 7

#define LEFT_SERVO_PWM_PIN 9
#define RIGHT_SERVO_PWM_PIN 10
#define LEFT_SERVO_POS 90
#define RIGHT_SERVO_POS 90


ros::NodeHandle nh;

Controller Left;
Controller Right;

Gripper Gripper;

DriveControl Control;

void leftCallback(geometry_msgs::Twist& cmd_vel){
    Left.Drive(cmd_vel.linear.x, 1);
}

void rightCallback(geometry_msgs::Twist& cmd_vel){
    Right.Drive(cmd_vel.linear.x, 1);
}

void dynamicCallback(package_name::TutorialsConfig &config uint32_t level){
    if(config.IsOpen){
        Gripper.Open();
    }else{
        Gripper.Close();
    }
}

ros::Subscriber<geometry_msgs::Twist> leftSub("leftDrive", leftCallback);
ros::Subscriber<geometry_msgs::Twist> rightSub("rightDrive", rightCallback);

dynamic_reconfigure::Server<package_name::TutorialConfig> server;
dynamic_reconfigure::Server<dynamic_tutorials::TutorialsConfig>::CallbackType f;

void setup() {
    nh.initNode();
    nh.subscribe(leftSub);
    nh.subscribe(rightSub);
    
    
    Gripper.init(LEFT_SERVO_PWM_PIN, RIGHT_SERVO_PWM_PIN, LEFT_SERVO_POS, RIGHT_SERVO_POS);
    Left.init(LEFTPWM, LEFTA, LEFTB);
    Right.init(RIGHTPWM, RIGHTA, RIGHTB);
    
    f= boost::bind(&dynamicCallback, _1,_2);
    server.setCallback(f);

    Control.setControllers(Left, Right);
}

void loop() {
    nh.spinOnce();
    delay(1);
}
