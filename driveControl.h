#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H

#include "controller.h"

class DriveControl {

    public:
        DriveControl();
        void setControllers(Controller::Controller _Left, Controller::Controller _Right)
        ~DriveControl();
        
        void Forward(byte Speed);
        void Reverse(byte Speed);
        void TurnLeft(int Degrees);
        void TurnRight(int Degrees);

    private:
        Controller::Controller Left;
        Controller::Controller Right;

};

#endif