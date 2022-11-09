#include "main.h"
#include "define.h"

inline float kP = 1;
inline float kI = 0;
inline float kD = 0;
inline float kT = 0;

inline float error;
inline float prevError;

inline float desiredHeading;
inline float headingError;
inline float prevHeading;

inline float proportion;
inline float derivative;
inline float integral;

inline  float headingPropotion;
inline float headingDerivative;

inline float leftMotorSpeed;
inline float rightMotorSpeed;
inline float leftTurnSpeed;
inline float rightTurnSpeed;

inline void PID (int desired){
    //error = distance the robot needs to move in inches.
    float error = desired - ((2.75 * M_PI * tracker.get_position()) / 360);

    //resets the tracking wheel's rotation sensor
    tracker.set_position(0);

    //aids in ensuring the loop is able to start. 
    int counter = 0;

    while (error > 1 || (fabs(leftMotorSpeed) >= 3 && counter != 0 && fabs(rightMotorSpeed) >= 3)){

        counter = 1;

        error = desired - ((2.75 * M_PI * tracker.get_position()) / 360);
        
        proportion = error * kP;

        derivative = prevError - error;
 
        headingError = desiredHeading - inertial.get_rotation();
  
        headingPropotion = headingError * kT;

        headingDerivative = prevHeading - headingError;
 
        leftTurnSpeed = -(headingPropotion + headingDerivative);
        rightTurnSpeed = headingPropotion + headingDerivative;

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