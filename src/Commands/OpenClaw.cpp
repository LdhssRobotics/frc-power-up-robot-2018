#include "OpenClaw.h"
#include "CloseClaw.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Arm.h"
#include "Robot.h"
#include "RobotMap.h"

OpenClaw::OpenClaw() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::claw.get());
	maxcurrent = 15.0;
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OpenClaw::Initialize() {
	Robot::claw->OpenClawMotor();
	SetTimeout(2.5);
}

// Called repeatedly when this Command is scheduled to run
void OpenClaw::Execute() {
	SmartDashboard::PutString("Claw: ", "Opening");
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::claw->IsClawClosed);
	SmartDashboard::PutNumber("OpenClaw-current", Robot::claw->CurrentDraw());
	SmartDashboard::PutNumber("OpenClaw-maxcurrent", maxcurrent);
}

// Make this return true when this Command no longer needs to run execute()
bool OpenClaw::IsFinished() {
	return (abs(Robot::claw->CurrentDraw())> abs(maxcurrent)) or IsTimedOut();
	//return false;
}
// Called once after isFinished returns true
void OpenClaw::End() {
	Robot::claw->IsClawClosed = false;
	Robot::claw->StopClaw();
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::claw->IsClawClosed);
	SmartDashboard::PutNumber("OpenClaw-current", Robot::claw->CurrentDraw());
	SmartDashboard::PutNumber("OpenClaw-maxcurrent", maxcurrent);
}


// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenClaw::Interrupted() {
	End();
}
