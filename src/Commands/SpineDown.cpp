#include "SpineDown.h"

SpineDown::SpineDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void SpineDown::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	Robot::arm->SetMotorSpeedSpine(-0.4);

}

// Called repeatedly when this Command is scheduled to run
void SpineDown::Execute() {
	Robot::arm->Log();

}

// Make this return true when this Command no longer needs to run execute()
bool SpineDown::IsFinished() {

}

// Called once after isFinished returns true
void SpineDown::End() {
	Robot::arm->SetMotorSpeedSpine(0);
	SmartDashboard::PutString("Spine", "Finished");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpineDown::Interrupted() {
	End();

}
