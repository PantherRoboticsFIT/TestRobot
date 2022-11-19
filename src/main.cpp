#include "main.h"
std::shared_ptr<ChassisController> drive =
	ChassisControllerBuilder()
		.withMotors({-20, -19}, {11, 12})
		// Green gearset, 4 in wheel diam, 11.5 im wheel track
		// 36 to 60 gear ratio
		.withDimensions({AbstractMotor::gearset::blue},{{2.75_in, 12_in}, imev5BlueTPR})
		.build();

ControllerButton ArmButtonUp (ControllerDigital::L1);
ControllerButton ArmButtonDown (ControllerDigital::R1);
Motor arm {15};
void on_center_button() {
	
}


void initialize() {
	
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	while (true) {
		if (ArmButtonUp.isPressed()){
			arm.moveVelocity(-600);
		}
		else if (ArmButtonDown.isPressed()){
			arm.moveVelocity(600);
		}
		else{
			arm.moveVelocity(0);
		}
	}
}
