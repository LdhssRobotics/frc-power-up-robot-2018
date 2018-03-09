/*
 * Spine.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Sayfullah
 */

#include <Commands/ArmSwingDPAD.h>
#include <Commands/SpineDPAD.h>
#include "Subsystems/SpineSubSystem.h"
#include "../RobotMap.h"
#include "Robot.h"

#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"
#include "ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h"
#include "ctre/phoenix/MotorControl/SensorCollection.h"
#include "ctre/phoenix/MotorControl/FeedbackDevice.h"

#include <algorithm>

/* Spine lead screws run at 10 rotations per inch of elevation
 * The transmission converts 3 rotations of the motor to 1 rotation of the lead screw
 * The Encoder reads 4096 pulses per rotation, it placed on motor end, so 4096 pulses per rotation of the motor itself
 * Therefore 1 inch is (1(10 *3) * 4096) = 122880 pulses
 * General Equation 122880d = pulses, where 'd' is the distance in inches
 */

#define EncConst 122880
#define percent 0.02

SpineSubSystem::SpineSubSystem() : Subsystem("SpineSubSystem")  {
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;

	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
}

void SpineSubSystem::InitDefaultCommand(){
	SetDefaultCommand(new SpineDPAD());
}

double SpineSubSystem::Converter(bool toInch, double value){
	double converted = 0;
	if (toInch){
		converted = value / EncConst;
	}else {
		converted = value * EncConst;
	}
	return converted;
}

double SpineSubSystem::AdjustSpine(bool isGoingUp) {
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
	double direction = 1;
	if (down){
		direction = -1;
	}
	double motorSpeed1 = 0.6 * direction;
	double motorSpeed2 = 0.6 * direction;

	double delta = (Robot::spine->GetSpinePos1() - Robot::spine->GetSpinePos2());
	if (abs(delta) > 8000){
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

void SpineSubSystem::SetMotorSpeed(double lspeed, double rspeed){
	if (!Robot::spine->CheckMove1()){
		Robot::spine->spineMotor2->Set(0);
		Robot::spine->spineMotor1->Set(lspeed);
	}else if (!Robot::spine->CheckMove2()){
		Robot::spine->spineMotor1->Set(0);
		Robot::spine->spineMotor2->Set(rspeed);
	} else{
		Robot::spine->spineMotor2->Set(rspeed);
		Robot::spine->spineMotor1->Set(lspeed);
	}
}

void SpineSubSystem::SetMotor(double spine1, double spine2){
	Robot::spine->spineMotor1->Set(spine1);
	Robot::spine->spineMotor2->Set(spine2);
}
int SpineSubSystem::GetSpinePos1(){
	int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->GetSelectedSensorPosition(0);
	return pos;
}

int SpineSubSystem::GetSpinePos2(){
	int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->GetSelectedSensorPosition(0);
	return pos;
}

void SpineSubSystem::ResetSpineEncoder1(){
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->SetSelectedSensorPosition(0,0,1);
}

void SpineSubSystem::ResetSpineEncoder2(){
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->SetSelectedSensorPosition(0,0,1);
}

bool SpineSubSystem::CanMoveSpine(){
	if (Robot::arm->GetArmPosition() < 10 || Robot::arm->GetArmPosition() > -5) {
		return true;
	}else if (Robot::arm->GetArmPosition() < 190 || Robot::arm->GetArmPosition() > 170){
		return true;
	}else{
		return false;
	}
}

bool SpineSubSystem::CheckMove1(){
	if (Robot::spine->spineMotor1->Get() > 0 || Robot::spine->spineMotor1->Get() < 0){
		return true;
	}else {
		return false;
	}
}

bool SpineSubSystem::CheckMove2(){
	if (Robot::spine->spineMotor2->Get() > 0 || Robot::spine->spineMotor2->Get() < 0){
		return true;
	}else {
		return false;
	}
}

void SpineSubSystem::Reset(){
	SetMotorSpeed(0,0);
	ResetSpineEncoder1();
	ResetSpineEncoder2();
}

void SpineSubSystem::CheckReset(){
	ctre::phoenix::motorcontrol::SensorCollection limit1 = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->GetSensorCollection();
	int limit = limit1.IsRevLimitSwitchClosed();
	ctre::phoenix::motorcontrol::SensorCollection limit2 = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->GetSensorCollection();
	int Limit = limit2.IsRevLimitSwitchClosed();
	if (limit == 1 || Limit == 1){
		ResetSpineEncoder1();
		ResetSpineEncoder2();
	}

	SmartDashboard::PutNumber("Limit 1", limit);
	SmartDashboard::PutNumber("Limit 2", Limit);
}


