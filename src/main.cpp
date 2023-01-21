#include "main.h"
#include <iostream>
MotorGroup leftMotors ({-20,-19});
MotorGroup rightMotors ({11,12});
/*
std::shared_ptr<ChassisController> drive =
	ChassisControllerBuilder()
		.withMotors({-20, -19}, {11, 12})
		// Green gearset, 4 in wheel diam, 11.5 im wheel track
		// 36 to 60 gear ratio
		.withGains(
        {2/100, 0, 5/100}, // Distance controller gains
        {0.001, 0, 0.0001}, // Turn controller gains
        {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    	)
		.withDimensions({AbstractMotor::gearset::blue,(60.0/36.0)},{{3.25_in, 12_in}, imev5BlueTPR})
		.build();
*/
std::shared_ptr<OdomChassisController> odom =
	ChassisControllerBuilder()
		.withMotors({-20, -19}, {11, 12})
		// Green gearset, 4 in wheel diam, 11.5 im wheel track
		// 36 to 60 gear ratio
		.withGains(
        {2, 0, 0}, // Distance controller gains
        {.4, 0, 0.2}, // Turn controller gains
        {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    	)
		.withDimensions({AbstractMotor::gearset::blue,(60.0/36.0)},{{3.25_in, 12_in}, imev5BlueTPR})
		.withOdometry(StateMode::CARTESIAN)
    	.buildOdometry(); // build an odometry chassis
Controller controller;
ControllerButton ArmButtonUp (ControllerDigital::L1);
ControllerButton ArmButtonDown (ControllerDigital::R1);
Motor arm {15};
void on_center_button() {
	
}
//lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
//lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);

void initialize() {
	//lv_label_set_text(label1,"testing");
	//lv_obj_align(label1, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10);
	//lv_label_set_text(label2,"#2");
	//lv_obj_align(label2, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 30);
	//arm.moveVelocity(-600);
	//pros::delay(1000);
	//arm.moveVelocity(0);
	odom->setState({0_in, 0_in, 0_deg});
	odom->turnToAngle(90_deg);
	//odom->driveToPoint({0_ft,2_ft});
	
	
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	/*
	while (true) {
		drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));
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
	

	int targetPosition = 500;
	double kp = 2.2;
	double kd = 5;  //5

	double error, lastError = 0;
	double output;
	while(true){
		int currentPosition = (leftMotors.getPosition()+rightMotors.getPosition())/2;

		error = targetPosition - currentPosition;

		output = kp*error+kd*(error - lastError);

		leftMotors.moveVelocity(output);
		rightMotors.moveVelocity(output);

		lastError=error;
		pros::delay(20);
	}
	*/
}
