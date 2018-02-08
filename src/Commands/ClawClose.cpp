#include "ClawClose.h"

ClawClose::ClawClose() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void ClawClose::Initialize() {
	SmartDashboard::PutString("Claw", "Close");
	Robot::arm->SetMotorSpeedClaw(-0.4);
}

// Called repeatedly when this Command is scheduled to run
void ClawClose::Execute() {
	Robot::arm->Log();

}

// Make this return true when this Command no longer needs to run execute()
bool ClawClose::IsFinished() {
	return Robot::arm->SetMinPositionClaw();
}

// Called once after isFinished returns true
void ClawClose::End() {
	Robot::arm->SetMotorSpeedClaw(0);
	SmartDashboard::PutString("Claw", "Finished");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawClose::Interrupted() {
	End();

}