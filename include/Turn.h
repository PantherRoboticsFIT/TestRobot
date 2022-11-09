#include "main.h"
#include "define.h"

inline float TurnkP = 1;
inline float TurnkI = 0;
inline float TurnkD = 0;
inline float TurnkT = 0;

inline float Turnerror;
inline float TurnprevError;

inline float TurndesiredHeading;
inline float TurnheadingError;
inline float TurnprevHeading;

inline float Turnproportion;
inline float Turnderivative;
inline float Turnintegral;

inline double TurnleftMotorSpeed;
inline double TurnrightMotorSpeed;

inline double maxspeed;

inline int facing = 0;

inline void Turn(int heading, int speed){

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