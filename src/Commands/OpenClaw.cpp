#include "OpenClaw.h"
#include "CloseClaw.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Arm.h"
#include "Robot.h"
#include "RobotMap.h"

OpenClaw::OpenClaw() {
	Requires(Robot::claw.get());
	maxcurrent = 15.0;
}

void OpenClaw::Initialize() {
	Robot::claw->OpenClawMotor();
	SetTimeout(2.5);
}

void OpenClaw::Execute() {
	SmartDashboard::PutString("Claw: ", "Opening");
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::claw->IsClawClosed);
	SmartDashboard::PutNumber("OpenClaw-current", Robot::claw->CurrentDraw());
	SmartDashboard::PutNumber("OpenClaw-maxcurrent", maxcurrent);
}

bool OpenClaw::IsFinished() {
	return (abs(Robot::claw->CurrentDraw())> abs(maxcurrent)) or IsTimedOut();
}
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
