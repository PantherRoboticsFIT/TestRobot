#pragma once
#include "main.h"

inline Controller controller;

inline Motor armMotor(15);

inline Motor leftFront(1);
inline Motor leftMiddle(2);
inline Motor leftBack(3);
inline Motor rightFront(4);
inline Motor rightMiddle(5);
inline Motor rightBack(6);

inline pros::Rotation tracker(19);
inline pros::Imu inertial(20);