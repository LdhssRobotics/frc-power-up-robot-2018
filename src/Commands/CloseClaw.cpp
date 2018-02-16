#include "CloseClaw.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

CloseClaw::CloseClaw() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::arm.get());
	maxcurrent = 0.6;
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CloseClaw::Initialize() {
	Robot::arm->CloseClaw();
}

// Called repeatedly when this Command is scheduled to run
void CloseClaw::Execute() {

	SmartDashboard::PutBoolean("Is Claw Closed", Robot::arm->IsClawClosed);
	SmartDashboard::PutNumber("CloseClaw-current", Robot::arm->CurrentDraw());
	SmartDashboard::PutNumber("CloseClaw-maxcurrent", maxcurrent);

}

// Make this return true when this Command no longer needs to run execute()
bool CloseClaw::IsFinished() {
	return (Robot::arm->CurrentDraw()> abs(maxcurrent));
}

// Called once after isFinished returns true
void CloseClaw::End() {
	Robot::arm->IsClawClosed = true;
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::arm->IsClawClosed);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseClaw::Interrupted() {

}
