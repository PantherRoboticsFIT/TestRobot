#pragma once
#include "main.h"

inline Controller controller;

inline Motor armMotor(15);

inline Motor leftFront(-19);
inline Motor leftMiddle(2);
inline Motor leftBack(-20);
inline Motor rightFront(12);
inline Motor rightMiddle(5);
inline Motor rightBack(11);

inline pros::Rotation tracker(19);
inline pros::Imu inertial(20);

extern void PID(int desired);