/*
 * SpineSubSystem.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Sayfullah
 */

#include <Commands/SpineDPAD.h>
#include "Subsystems/SpineSubSystem.h"
#include "../RobotMap.h"
#include "Robot.h"
#include "WPILib.h"

#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"
#include "ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h"
#include "ctre/phoenix/MotorControl/SensorCollection.h"
#include "ctre/phoenix/MotorControl/FeedbackDevice.h"


/* The spine subsystem deals with the 2 CAN WPI_TalonSRX motors that drive the spine lead screws up and down.
 * These 2 motors are defined as spineMotor1 and spineMotor2, their speed is set like a normal speed/motor controller.
 * But the sensor functions are placed in the ctre::phoenix libraries.
 *
 * Spine lead screws run at 10 rotations per inch of elevation.
 * The transmission converts 3 rotations of the motor to 1 rotation of the lead screw.
 * The Encoder reads 4096 pulses per rotation, it placed on motor end, so 4096 pulses per rotation of the motor itself.
 * Therefore 1 inch is (1(10 *3) * 4096) = 122880 pulses.
 * General Equation 122880d = pulses, where 'd' is the distance in inches.
 */

#define EncConst 122880
#define percent 0.02

SpineSubSystem::SpineSubSystem() : Subsystem("SpineSubSystem")  {
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;

	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
}

void SpineSubSystem::InitDefaultCommand(){
	/* This function sets the default command so that it can be
	 * automatically called when the Spine subsystem is initialized.
	 */
	SetDefaultCommand(new SpineDPAD());
}

double SpineSubSystem::Converter(bool toInch, double value){
	/* Converts the value given from pulses to inches or inches to pulses using the math derived at the top
	 * General Equation 122880d = pulses, where 'd' is the distance in inches
	 * toInch - Set true to convert from pulses to inches, set false for inches to pulses
	 */
	double converted = 0;
	if (toInch){
		converted = value / EncConst;
	}else {
		converted = value * EncConst;
	}
	return converted;
}

double SpineSubSystem::AdjustSpine(bool isGoingUp) {
	/* An advanced spine adjust code.
	 * The first 2 sections of the if/else statement deal with any motor slips in the gear box.
	 * The second 2 parts calculate an increment to be added to the speed of the Spine2 motor.
	 * This increment outputs a larger increment as the difference between the motors increases.
	 * It outputs a smaller increment when the difference is smaller than 0.2 inches, for fine tuning.
	 * isGoingUp - Set true if spine is going up, false if down
	 */
	float increment;
	double variance = Converter(false, 0.25);
	if (Robot::spine->GetSpinePos1() - Robot::spine->GetSpinePos2() < -variance){
		std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->SetSelectedSensorPosition(Robot::spine->GetSpinePos2(),0,1);
		increment = 0;
	}else if (Robot::spine->GetSpinePos1() - Robot::spine->GetSpinePos2() > variance){
		std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->SetSelectedSensorPosition(Robot::spine->GetSpinePos1(),0,1);
		increment = 0;
	}else if (isGoingUp) {
		increment = (percent/Converter(false, 0.2))*(Robot::spine->GetSpinePos1() - Robot::spine->GetSpinePos2());
	} else {
		increment = (percent/Converter(false, 0.2))*(Robot::spine->GetSpinePos1() - Robot::spine->GetSpinePos2());
	}
	return increment;
}

void SpineSubSystem::AdjustSimple(bool down){
	/* Simple function trying to keep the spine motors level when
	 * going up or down. Does this by stopping the motor that is ahead.
	 * Keeps the motors within 0.06 inches of each other.
	 */
	double direction = 1;
	if (down){
		direction = -1;
	}
	double motorSpeed1 = 0.6 * direction;
	double motorSpeed2 = 0.6 * direction;

	double delta = (Robot::spine->GetSpinePos1() - Robot::spine->GetSpinePos2());
	if (abs(delta) > Converter(false, 0.06)){
		delta = delta * direction;
		if (delta > 0){
			motorSpeed1 = 0;
		}
		else {
			motorSpeed2 = 0;
		}
	}
	Robot::spine->spineMotor1->Set(motorSpeed1);
	Robot::spine->spineMotor2->Set(motorSpeed2);
}

void SpineSubSystem::SetMotorSpeed(double Spine1Speed, double Spine2Speed){
	/*	Function to set both Spine motors to a speed,
	 * 	with a check if there is any stalling.
	 * 	And tries to correct the stalling
	 * 	<INCOMPLETE>
	 */
	if (!Robot::spine->CheckMove1()){
		Robot::spine->spineMotor2->Set(0);
		Robot::spine->spineMotor1->Set(Spine1Speed);
	}else if (!Robot::spine->CheckMove2()){
		Robot::spine->spineMotor1->Set(0);
		Robot::spine->spineMotor2->Set(Spine2Speed);
	} else{
		Robot::spine->spineMotor2->Set(Spine2Speed);
		Robot::spine->spineMotor1->Set(Spine1Speed);
	}
}

void SpineSubSystem::SetMotor(double spine1, double spine2){
	/* A simple function to quickly assign different speed to each spine motor
	 */
	Robot::spine->spineMotor1->Set(spine1);
	Robot::spine->spineMotor2->Set(spine2);
}
int SpineSubSystem::GetSpinePos1(){
	/* Returns current Spine1 encoder reading in pulses.
	 */
	int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->GetSelectedSensorPosition(0);
	return pos;
}

int SpineSubSystem::GetSpinePos2(){
	/* Returns current Spine2 encoder reading in pulses
	 */
	int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->GetSelectedSensorPosition(0);
	return pos;
}

void SpineSubSystem::ResetSpineEncoder1(){
	/* Sets Encoder on Spine1 to 0
	 */
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->SetSelectedSensorPosition(0,0,1);
}

void SpineSubSystem::ResetSpineEncoder2(){
	/* Sets Encoder on Spine2 to 0
	 */
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->SetSelectedSensorPosition(0,0,1);
}

bool SpineSubSystem::CanMoveSpine(){
	/* Check if the arm is in a safe position where the spine can be manually moved
	 * This is true either if the arm is vertically down, to allow the robot to pick up a cube
	 * or if the arm is vertically up to allow for control when doing the scale/climb
	 */
	if (Robot::arm->GetArmPosition() < 10 || Robot::arm->GetArmPosition() > -5) {
		return true;
	}else if (Robot::arm->GetArmPosition() < 190 || Robot::arm->GetArmPosition() > 170){
		return true;
	}else{
		return false;
	}
}

bool SpineSubSystem::CheckMove1(){
	/*Checks if the Spine1 motor is moving currently
	 */
	if (Robot::spine->spineMotor1->Get() > 0 || Robot::spine->spineMotor1->Get() < 0){
		return true;
	}else {
		return false;
	}
}

bool SpineSubSystem::CheckMove2(){
	/*Checks if the Spine2 motor is moving currently
	 */
	if (Robot::spine->spineMotor2->Get() > 0 || Robot::spine->spineMotor2->Get() < 0){
		return true;
	}else {
		return false;
	}
}

void SpineSubSystem::Reset(){
	/*Called when the spine needs to stop and reset the encoders
	 */
	SetMotorSpeed(0,0);
	ResetSpineEncoder1();
	ResetSpineEncoder2();
}

void SpineSubSystem::CheckReset(){
	/* The function checks if either of the limit switches have been triggered.
	 * A SensorCollection object has to be created for each limit switch, Spine1Limit and Spine2Limit.
	 * The IsRevLimitSwitchClosed() is called on both of these objects to check if the switch is triggered.
	 * This returns '1' or '0', true or false respectively.
	 * If either of these returns '1' the spine is stopped and the encoders reset.
	 * The values are displayed on the SmartDashboard for debugging
	 */
	ctre::phoenix::motorcontrol::SensorCollection Spine1Limit = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->GetSensorCollection();
	int Limit1 = Spine1Limit.IsRevLimitSwitchClosed();
	ctre::phoenix::motorcontrol::SensorCollection Spine2Limit = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->GetSensorCollection();
	int Limit2 = Spine2Limit.IsRevLimitSwitchClosed();
	if (Limit2 == 1 || Limit1 == 1){
		Reset();
	}

	SmartDashboard::PutNumber("Spine Limit Switch 1", Limit1);
	SmartDashboard::PutNumber("Spine Limit Switch 2", Limit2);
}


