#include "DriveDistance.h"
#include "../Robot.h"

const float kP = 0.025;

DriveDistance::DriveDistance(float distance):
	targetDistance(distance)
{
	Requires(Robot::drivetrain.get());
}

// Called just before the Command runs the first time
void DriveDistance::Initialize() {
	Robot::drivetrain->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	SmartDashboard::PutNumber("Distance travelled", Robot::drivetrain->GetDistance());
	SmartDashboard::PutNumber("target distance", targetDistance);
	Robot::drivetrain->ArcadeDrive(-0.65, 0.05);
}

// Make this return true when this Command no longer needs to run execute()
 bool DriveDistance::IsFinished() {
	return (Robot::drivetrain->GetDistance() >= targetDistance) || (Robot::drivetrain->GetDistance() <= (-1 *targetDistance));
}

// Runs once after IsFinished return true
 void DriveDistance::End() {
	 Robot::drivetrain->Stop();
	 Wait (1);
 }


// Called when another Command which requires one or more of the same
// subsystem is scheduled to run
 void DriveDistance::Interrupted() {
	 End();
 }
