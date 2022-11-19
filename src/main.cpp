#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#define LEFT_WHEELS_PORT_ONE -20
#define LEFT_WHEELS_PORT_TWO -19
#define RIGHT_WHEELS_PORT_ONE 11
#define RIGHT_WHEELS_PORT_TWO 12
#define HINGE_PORT 1
#define ROLLER_PORT 15

Motor iLeftOne(LEFT_WHEELS_PORT_ONE);
Motor iLeftTwo(LEFT_WHEELS_PORT_TWO);
Motor iRightOne(RIGHT_WHEELS_PORT_ONE);
Motor IRightTwo(RIGHT_WHEELS_PORT_TWO);

std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
        .withMotors({iLeftOne, iLeftTwo}, {iRightOne, IRightTwo})
        // Green gearset, 4 in wheel diam, 11.5 im wheel track
        // 36 to 60 gear ratio
        .withDimensions({AbstractMotor::gearset::blue}, {{2.75_in, 12_in}, imev5BlueTPR})
        .withGains(
            {1.0, 0, 0.25}, // Distance controller gains
            {1.0, 0, 0.25}, // Turn controller gains
            {1.0, 0, 0.25}  // Angle controller gains (helps drive straight)
            )
        .withDerivativeFilters(
            std::make_unique<AverageFilter<3>>(), // Distance controller filter
            std::make_unique<AverageFilter<3>>(), // Turn controller filter
            std::make_unique<AverageFilter<3>>()  // Angle controller filter
            )
        .withMaxVelocity(100)
        .withClosedLoopControllerTimeUtil(50, 5, 250_ms)
        .withLogger(
            std::make_shared<Logger>(
                TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
                "/ser/sout",                                 // Output to the PROS terminal
                Logger::LogLevel::debug                      // Most verbose log level
                ))
        .withOdometry()
        .withLogger(
            std::make_shared<Logger>(
                TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
                "/ser/sout",                                 // Output to the PROS terminal
                Logger::LogLevel::debug                      // Most verbose log level
                ))
        .withSensors(
            iLeftOne.getEncoder(), iRightOne.getEncoder()
            //  {iLeftOne.getEncoder(), iLeftTwo.getEncoder(), false},
            //  {iRightOne.getEncoder(), IRightTwo.getEncoder(), true}
            )
        .build();

Motor hinge(HINGE_PORT);
// if you wanted to set the gearbox, do it in initlization via constructor
Motor roller(ROLLER_PORT);

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
   drive->moveDistance(RQuantity<std::ratio<0>, std::ratio<1>, std::ratio<0>, std::ratio<0>>(5.0));
   // // timer
   // TimeUtil time = TimeUtilFactory::createDefault();

   // // On the switch that you connect your controller to, it has a automomous flip switch.
   // std::shared_ptr<ChassisControllerPID> robotPID = new ChassisControllerPID(
   //     time,
   //     drive->model()

   //    );
}

void opcontrol()
{
   while (true)
   {
      drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),
                                controller.getAnalog(ControllerAnalog::rightX));

      pros::delay(10);
      if (hingeButton1.changedToPressed())
      {
         hinge.moveVelocity(-10);
      }
      if (hingeButton2.changedToPressed())
      {
         hinge.moveVelocity(10);
      }
      if (hingeButton1.changedToReleased() || hingeButton2.changedToReleased() || (hingeButton1.changedToPressed() && hingeButton2.changedToPressed()))
      {
         hinge.moveVelocity(0);
      }

      if (rollerButton.changedToPressed())
      {
         roller.moveVelocity(10);
      }
      if (rollerButton.changedToReleased())
      {
         roller.moveVelocity(0);
      }
   }
}