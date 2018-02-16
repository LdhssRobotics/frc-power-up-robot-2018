#include "Arm.h"
#include "../RobotMap.h"
#include "Robot.h"

#include <algorithm>

#include "Commands/ArmSwing.h"

Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	bottomShoulderSwitch = RobotMap::bottomShoulderSwitch;
	topShoulderSwitch = RobotMap::topShoulderSwitch;


	armMotor1 = RobotMap::armMotor1;
	armMotor2 = RobotMap::armMotor2;
	clawMotor = RobotMap::clawMotor;
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;

	differentialSpine = RobotMap::differentialSpine;

	SPEED_MULTIPLIER = 0.02;
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmSwing());
}

void Arm::SetArmSpeed(float speed){
	armMotor1->Set(speed);
	armMotor2->Set(speed);
}

void Arm::DifferentialSpine(double leftSpeed, double rightSpeed) {
	differentialSpine->TankDrive(leftSpeed, rightSpeed);
}

void Arm::SetClawSpeed(float speed) {
	clawMotor->Set(speed);
}

float Arm::GetArmPosition(){
	return armEncoder->GetDistance();
}

float Arm::GetSpinePos1(){
	return spineEncoder1->GetDistance();
}

float Arm::GetSpinePos2(){
	return spineEncoder2->GetDistance();
}

void Arm::ResetArm(){
	if (bottomShoulderSwitch->Get()){
		armMotor1->Set(0);
		armMotor2->Set(0);
		ResetArmEncoder();
	}
}

bool Arm::CanMoveSpine(){
	if(Robot::arm->GetArmPosition() > -5 && Robot::arm->GetArmPosition() < 10){
		return true;
	}else if (Robot::arm->GetArmPosition() > 170 && Robot::arm->GetArmPosition() < 190){
		return true;
	}else return false;
}

void Arm::Reset(){
	ResetArmEncoder();
	ResetSpineEncoder1();
	ResetSpineEncoder2();
	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	spineMotor1->Set(0);
	spineMotor2->Set(0);
	Log();
}

void Arm::ResetArmEncoder(){
	armEncoder->Reset();
}

void Arm::ResetSpineEncoder1(){
	spineEncoder1->Reset();
}

void Arm::ResetSpineEncoder2(){
	spineEncoder2->Reset();
}

void Arm::Log(){
	SmartDashboard::PutNumber("Arm Encoder:", GetArmPosition());
}
