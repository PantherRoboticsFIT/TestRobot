#include "main.h"
//#include "PID.cpp"
//#include "Turn.cpp"
//#include "define.h"





/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
 
std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
        .withMotors({-11, -12}, {20, 19})
        // Green gearset, 4 in wheel diam, 11.5 im wheel track
        // 36 to 60 gear ratio
        .withDimensions({AbstractMotor::gearset::blue},{{2.75_in, 12_in}, imev5BlueTPR})
        .build();
		

/*
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
*/


void initialize() {
}


void disabled() {
	while (inertial.is_calibrating()) {
		printf("IMU calibrating");
   	 	pros::delay(10);
  }	
}


void competition_initialize() {

}

void autonomous() {
	//moves the robot 24 inches
	PID(24);
	//
	
}

ControllerButton armUpButton(ControllerDigital::R2);
ControllerButton armDownButton(ControllerDigital::R1);

void opcontrol() {

	while (true) {
    	// Arcade drive with the left stick.
		
    	drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),
     	                          controller.getAnalog(ControllerAnalog::rightX));

	    // Wait and give up the time we don't need to other tasks.`
  	    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
   	 	pros::delay(10);
		
		if(armUpButton.isPressed()){
			armMotor.moveVelocity(150);
		}else if (armDownButton.isPressed()){
			armMotor.moveVelocity(-150);
		}else{
			armMotor.moveVelocity(0);
		}
	}
}
