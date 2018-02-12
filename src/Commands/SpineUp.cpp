#include "SpineUp.h"

SpineUp::SpineUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void SpineUp::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	Robot::arm->SetMotorSpeedSpine(0.4);

}

// Called repeatedly when this Command is scheduled to run
void SpineUp::Execute() {
	Robot::arm->Log();

}

// Make this return true when this Command no longer needs to run execute()
bool SpineUp::IsFinished() {


}

// Called once after isFinished returns true
void SpineUp::End() {
	Robot::arm->SetMotorSpeedSpine(0);
	SmartDashboard::PutString("Spine", "Finished");
	Robot::arm->ResetEncoder();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpineUp::Interrupted() {
	End();

}
