#include "main.h"
#include "define.h"

float kP = 1;
float kD = 0;
float kI = 0;
float kT = 0;

float error;
float prevError;

float desiredHeading;
float headingError;
float prevHeading;

float proportion;
float derivative;
float integral;

float headingPropotion;
float headingDerivative;

float leftMotorSpeed;
float rightMotorSpeed;
float leftTurnSpeed;
float rightTurnSpeed;

void PID (int desired){
    //error = distance the robot needs to move in inches.
    float error = desired - ((2.75 * M_PI * tracker.get_position()) / 360);

    //resets the tracking wheel's rotation sensor
    tracker.set_position(0);

    //aids in ensuring the loop is able to start. 
    int counter = 0;

    while (error > 1 || (fabs(leftMotorSpeed) >= 3 && counter != 0 && fabs(rightMotorSpeed) >= 3)){

        counter = 1;

        error = desired - ((2.75 * M_PI * tracker.get_position()) / 360);
        
        proportion = error;

        derivative = prevError - error;
 
        headingError = desiredHeading - inertial.get_rotation();
  
        headingPropotion = headingError * kT;
 
        leftTurnSpeed = -headingPropotion;
        rightTurnSpeed = headingPropotion;

        leftMotorSpeed = (proportion * kP) + (derivative * kD) + leftTurnSpeed;
        rightMotorSpeed = (proportion * kP) + (derivative * kD) + rightTurnSpeed;

        leftFront.moveVelocity(leftMotorSpeed);
        leftMiddle.moveVelocity(leftMotorSpeed);
        leftBack.moveVelocity(leftMotorSpeed);
        rightFront.moveVelocity(rightMotorSpeed);
        rightMiddle.moveVelocity(rightMotorSpeed);
        rightBack.moveVelocity(rightMotorSpeed);
    }
    leftFront.moveVelocity(0);
    leftMiddle.moveVelocity(0);
    leftBack.moveVelocity(0);
    rightFront.moveVelocity(0);
    rightMiddle.moveVelocity(0);
    rightBack.moveVelocity(0);
}