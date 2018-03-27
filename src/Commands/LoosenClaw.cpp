/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LoosenClaw.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

LoosenClaw::LoosenClaw() {
	Requires(Robot::claw.get());

}

// Called just before this Command runs the first time
void LoosenClaw::Initialize() {
	SmartDashboard::PutString("Claw: ", "Loosening");
	SetTimeout(0.1);
	Robot::claw->SetClawSpeed(0.8);
}

// Called repeatedly when this Command is scheduled to run
void LoosenClaw::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LoosenClaw::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void LoosenClaw::End() {
	Robot::claw->SetClawSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoosenClaw::Interrupted() {

}
