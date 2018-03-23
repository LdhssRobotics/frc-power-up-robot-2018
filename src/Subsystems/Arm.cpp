#include <Commands/ArmStay.h>
#include "Arm.h"
#include "../RobotMap.h"
#include "Robot.h"
#include "WPILib.h"
#include "SmartDashboard/Sendable.h"

#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"
/* The arm subsystem deals with the 2 PWM arm motors and the 1 CAN WPI_TalonSRX claw motor.
 * They are defined as armMotor1, armMotor2 and clawMotor respectively.
 * There is only one encoder, armEncoder and one limit switch, bottomshoulderSwitch.
 *
 * To get any sensor information on the claw motor, function from the ctre::phoenix library must be called.
 * But setting speeds is the same as a normal speed/motor controller.
 *
 * On the physical robot the second arm motor is not there, but when trying to remove from the software,
 * many errors occurred.
 */

Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;
	bottomShoulderSwitch = RobotMap::bottomShoulderSwitch;

	armMotor1 = RobotMap::armMotor1;
	armMotor2 = RobotMap::armMotor2;
	clawMotor = RobotMap::clawMotor;

	IsClawClosed = false;
	armTarget = 0;

}

void Arm::InitDefaultCommand() {

	SetDefaultCommand(new ArmStay());
}

void Arm::SetArmSpeed(float speed){
	/* Function sets speed of both arm motors (one of the motors is set to be inverted).
	 * One of these motors is actually not on the physical robot, when removed it cause errors.
	 * speed - any value between '-1' and '1', positive values lead the arm upwards.
	 */
	armMotor1->Set(speed);
	armMotor2->Set(speed);
}

void Arm::SetClawSpeed(float speed) {
	/* Function sets the speed of the motor.
	 * speed - any value between '-1' and '1', positive opens the claw.
	 */
	clawMotor->Set(speed);
}

float Arm::GetArmPosition(){
	/* Function returns the current reading on the arm motor encoder.
	 * <Needs to be Tested>
	 */
	return armEncoder->GetDistance();
}

void Arm::ResetArm(){
	/* Function resets the encoder and motors on the arm,
	 * when the limit switch is triggered.
	 */
	if (bottomShoulderSwitch->Get()){
		armMotor1->Set(0);
		armMotor2->Set(0);
		ResetArmEncoder();
	}
}

void Arm::Reset(){
	/* Function is called when a full reset of the arm subsystem is required.
	 * Sets all motors to '0' and resets the the arm encoder.
	 */
	ResetArmEncoder();
	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	Log();
}

void Arm::ResetArmEncoder(){
	//Function is called when the arm encoder needs to be reset to '0'
	armEncoder->Reset();
}

void Arm::Log(){
	/* Function displays the current reading on the arm encoder
	 * on the SmartDashboard.
	 */
	SmartDashboard::PutNumber("Arm Encoder:", GetArmPosition());
}

void Arm::OpenClawMotor(){
	// Sets the claw motor at '0.8' speed to open the claw.
	clawMotor->Set(0.8);
}
void Arm::CloseClawMotor(){
	// Sets the claw motor at '-0.8' speed to close the claw.
	clawMotor->Set(-0.8);
}
void Arm::StopClaw(){
	// Sets the claw motor speed to '0' to stop movement.
	clawMotor->Set(0);
}

double Arm::CurrentDraw(){
	/* Function reads and returns the output current from the claw motor.
	 * It also displays this current on the SmartDashboard.
	 */
	double current = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(clawMotor)->GetOutputCurrent();
	SmartDashboard::PutNumber("Talon SRX - current: ", current);
	return (current);
}
