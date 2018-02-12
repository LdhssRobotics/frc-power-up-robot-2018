#include "Arm.h"
#include "../RobotMap.h"
#include "Robot.h"

#include "Commands/ArmSwing.h"

Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	bottomSpineSwitch1 = RobotMap::bottomSpineSwitch1;
	topSpineSwitch1 = RobotMap::topSpineSwitch1;
	bottomSpineSwitch2 = RobotMap::bottomSpineSwitch2;
	topSpineSwitch2 = RobotMap::topSpineSwitch2;
	bottomShoulderSwitch = RobotMap::bottomShoulderSwitch;
	frontClawSwitch = RobotMap::frontClawSwitch;
	rearClawSwitch = RobotMap::rearClawSwitch;

	armMotor1 = RobotMap::armMotor1;
	armMotor2 = RobotMap::armMotor2;
	clawMotor = RobotMap::clawMotor;
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmSwing());
}

void Arm::SetMotorSpeedArm(float speed){
	armMotor1->Set(speed);
	armMotor2->Set(speed);
}

void Arm::SetMotorSpeedSpine(float speed) {
	spineMotor1->Set(speed);
	spineMotor2->Set(speed);
}

void Arm::SetMotorSpeedClaw(float speed) {
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

bool Arm::InSpineMaxPosition() {
	return (topSpineSwitch1->Get() && topSpineSwitch2->Get());
}

bool Arm::InSpineMinPosition() {
	return (bottomSpineSwitch1->Get() && bottomSpineSwitch2->Get());
}

void Arm::ResetSpine(){
	if (bottomSpineSwitch1->Get() && bottomSpineSwitch2->Get()){
		SetMotorSpeedSpine(0);
		Reset();
	}
}

void Arm::Reset(){
	ResetEncoder();
	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	spineMotor1->Set(0);
	spineMotor2->Set(0);
	Log();
}

void Arm::ResetEncoder(){

	armEncoder->Reset();
	spineEncoder1->Reset();
	spineEncoder2->Reset();

}

void Arm::Log(){
	SmartDashboard::PutNumber("Arm Encoder:", GetArmPosition());
}
