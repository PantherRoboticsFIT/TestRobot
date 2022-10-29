#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#define LEFT_WHEELS_PORT -11
#define RIGHT_WHEELS_PORT -12
#define HINGE_PORT 1
#define ROLLER_PORT 15


std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
        .withMotors({-20, -19}, {11, 12})
        // Green gearset, 4 in wheel diam, 11.5 im wheel track
        // 36 to 60 gear ratio
        .withDimensions({AbstractMotor::gearset::blue}, {{2.75_in, 12_in}, imev5BlueTPR})
        .build();

// Motor hinge({HINGE_PORT, okapi::AbstractMotor::setGearing()});
// if you wanted to set the gearbox, do it in initlization via constructor
Motor roller({ROLLER_PORT});

Controller controller;

ControllerButton hingeButton1(ControllerDigital::L1);
ControllerButton hingeButton2(ControllerDigital::R1);
ControllerButton rollerButton(ControllerDigital::A);


void on_center_button()
{
   // any time
}

void initialize()
{
   hinge.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
   hinge.tarePosition();
   roller.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
   roller.tarePosition();
}

void disabled()
{
   // signal to not start
}

void competition_initialize()
{
   // I believe, I have got it written down somewhere let me bring that up
}

void autonomous()
{
   // On the switch that you connect your controller to, it has a automomous flip switch.
}

void opcontrol()
{
   while (true)
   {
      drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),
                                controller.getAnalog(ControllerAnalog::rightX));
      
      pros::delay(10);
      if (hingeButton1.changedToPressed()) {
         hinge.moveVelocity(-10);
      }
      if (hingeButton2.changedToPressed()) {
         hinge.moveVelocity(10);
      }
      if (hingeButton1.changedToReleased() || hingeButton2.changedToReleased() 
            || (hingeButton1.changedToPressed() && hingeButton2.changedToPressed())) {
         hinge.moveVelocity(0);
      }

      if (rollerButton.changedToPressed()) {
         roller.moveVelocity(10);
      }
      if (rollerButton.changedToReleased()) {
         roller.moveVelocity(0);
      }
   }
}