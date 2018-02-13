/*
 * ArmSwing.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Sayfullah
 */

#include <Commands/ArmSwing.h>


ArmSwing::ArmSwing() {
	Requires(Robot::arm.get());
}

void ArmSwing::Initialize(){
	SmartDashboard::PutString("Arm", "Start");
	Robot::arm->SetArmSpeed(0);
}

void ArmSwing::Execute(){
	float speed = (0.4 * Robot::oi->driveStick2->GetRawAxis(OI::LEFT_Y_AXIS));
	SmartDashboard::PutString("Arm", "Moving");
	Robot::arm->SetArmSpeed(speed);
	SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
}

bool ArmSwing::IsFinished(){
	return false;
}

void ArmSwing::End(){
	Robot::arm->SetArmSpeed(0);
	SmartDashboard::PutString("Arm","Finished");
}

void ArmSwing::Interrupted(){
	End();
}
