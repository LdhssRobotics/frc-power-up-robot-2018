#include <Commands/ArmSwingDPAD.h>
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
 */

Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;
	bottomShoulderSwitch = RobotMap::bottomShoulderSwitch;

	armMotor = RobotMap::armMotor;
}

void Arm::InitDefaultCommand() {

	    SetDefaultCommand(new ArmSwingDPAD());
}

void Arm::SetArmSpeed(float speed){
	/* Function sets speed of both arm motors (one of the motors is set to be inverted).
	 * One of these motors is actually not on the physical robot, when removed it cause errors.
	 * speed - any value between '-1' and '1', positive values lead the arm upwards.
	 */
	armMotor->Set(speed);
}

float Arm::GetArmPosition(){
	/* Function returns the current reading on the arm motor encoder.
	 */
	return armEncoder->GetRaw();
}

void Arm::Reset(){
	/* Function is called when a full reset of the arm subsystem is required.
	 * Sets all motors to '0' and resets the the arm encoder.
	 */
	ResetArmEncoder();  // ASA should reset encoder after motors are stopped...
	armMotor->Set(0);
	Log();
}

void Arm::ResetArm(){
	/* Function resets the encoder and motors on the arm,
	 * when the limit switch is triggered.
	 */
	if (!bottomShoulderSwitch->Get()){
		armMotor->Set(0);
		ResetArmEncoder();
	}
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
