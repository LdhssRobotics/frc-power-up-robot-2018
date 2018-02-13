#include "ClawOpen.h"

ClawOpen::ClawOpen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void ClawOpen::Initialize() {
	SmartDashboard::PutString("Claw", "Open");
	Robot::arm->SetClawSpeed(0.4);
}

// Called repeatedly when this Command is scheduled to run
void ClawOpen::Execute() {
	Robot::arm->Log();
}

// Make this return true when this Command no longer needs to run execute()
bool ClawOpen::IsFinished() {

}

// Called once after isFinished returns true
void ClawOpen::End() {
	Robot::arm->SetClawSpeed(0);
	SmartDashboard::PutString("Claw", "Finished");


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOpen::Interrupted() {
	End();

}
