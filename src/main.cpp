#include "main.h"
std::shared_ptr<ChassisController> drive =
	ChassisControllerBuilder()
		.withMotors({-11, -12}, {20, 19})
		// Green gearset, 4 in wheel diam, 11.5 im wheel track
		// 36 to 60 gear ratio
		.withDimensions({AbstractMotor::gearset::blue},{{2.75_in, 12_in}, imev5BlueTPR})
		.build();

void on_center_button() {
	
}


void initialize() {
	
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	while (true) {
		
	}
}
