#include "OpenClaw.h"
#include "Subsystems/Arm.h"
#include "Robot.h"
#include "RobotMap.h"

OpenClaw::OpenClaw() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::arm.get());
	maxcurrent = 0.6;
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OpenClaw::Initialize() {
	Robot::arm->OpenClaw();
}

// Called repeatedly when this Command is scheduled to run
void OpenClaw::Execute() {

	SmartDashboard::PutNumber("OpenClaw-current", Robot::arm->CurrentDraw());
	SmartDashboard::PutNumber("OpenClaw-maxcurrent", maxcurrent);

}

// Make this return true when this Command no longer needs to run execute()
bool OpenClaw::IsFinished() {
	return (Robot::arm->CurrentDraw()< abs(maxcurrent));

}

// Called once after isFinished returns true
void OpenClaw::End() {
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::arm->IsClawClosed);
	Robot::arm->IsClawClosed = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenClaw::Interrupted() {

}
