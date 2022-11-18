#include "main.h"
#include "define.h"

float TurnkP = 1;
float TurnkI = 0;
float TurnkD = 0;
float TurnkT = 0;

float Turnerror;
float TurnprevError;

float TurndesiredHeading;
float TurnheadingError;
float TurnprevHeading;

float Turnproportion;
float Turnderivative;
float Turnintegral;

double TurnleftMotorSpeed;
double TurnrightMotorSpeed;

double maxspeed;

int facing = 0;

void Turn(int heading, int speed){

    int counter = 1;
    
      float dH = heading - (360 - tracker.get_position());

    while ((abs(dH) >= 1) || (abs(maxspeed) >= 5 && counter != 0)) {

        counter = 1;

        while (abs(dH) > 180) {
          // if so, determine i++f positive or negative
          if (dH > 0) {
              // if positive, subtract 360
              dH -= 360;
          }
          else {
              // else, add 360
              dH += 360;
          }
      }
      

    }

}