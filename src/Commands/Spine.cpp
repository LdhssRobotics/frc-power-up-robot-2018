#include "Spine.h"

Spine::Spine() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void Spine::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Spine::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Spine::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Spine::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Spine::Interrupted() {

}
