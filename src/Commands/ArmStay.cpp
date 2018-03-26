/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArmStay.h"
#include "ArmSwing.h"

ArmStay::ArmStay() {
	Requires(Robot::arm.get());
	armTargetPOS = 0;
}

// Called just before this Command runs the first time
void ArmStay::Initialize() {
	armTargetPOS = Robot::arm->armTarget;
}

// Called repeatedly when this Command is scheduled to run
void ArmStay::Execute() {
	SmartDashboard::PutNumber("ArmCurrentPosition",Robot::arm->GetArmPosition());

	if (armTargetPOS < Robot::arm->GetArmPosition()) { //ASA shouldn't this be >? with an offset?, What stops it?
		Robot::arm->SetArmSpeed(0.15);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ArmStay::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmStay::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmStay::Interrupted() {
	End();
}
