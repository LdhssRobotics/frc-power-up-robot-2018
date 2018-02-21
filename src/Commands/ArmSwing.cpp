/*
 * ArmClimb.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#include <Commands/ArmSwing.h>


ArmSwing::ArmSwing(float P) {
	// TODO Auto-generated constructor stub
	Position = P;
	Requires(Robot::arm.get());
}

void ArmSwing::Initialize(){
	Robot::arm->SetArmSpeed(0);
}

void ArmSwing::Execute(){
	if (Robot::arm->GetArmPosition() < Position) {
		Robot::arm->SetArmSpeed(0.4);
	}else if (Robot::arm->GetArmPosition() > Position){
		Robot::arm->SetArmSpeed(-0.4);
	}else {
		End();
	}
}

void ArmSwing::End(){
	Robot::arm->SetArmSpeed(0);
}

bool ArmSwing::IsFinished(){
	return false;
}

void ArmSwing::Interrupted(){
	End();
}
