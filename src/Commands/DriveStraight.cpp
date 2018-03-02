#include "DriveStraight.h"
#include "RobotMap.h"
#include <chrono>
#include <thread>

// Set value for dampener
const float kP = 0.025;
const float speed = -0.5;

DriveStraight::DriveStraight(float distance):
	targetdistance(distance)
{
	Requires (Robot::drivetrain.get());
	straight = 0;
	SmartDashboard::PutNumber("Is DriveStraight initialized: ", 0);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	Robot::drivetrain->ResetEncoder();
	Robot::drivetrain->gyro->Reset();
	SmartDashboard::PutNumber("Is DriveStraight initialized: ", 1);

	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//Robot::drivetrain->gyro->Calibrate();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	//Determine amount to turn
	SmartDashboard::PutNumber("Is DriveStraight initialized: ", 2);
	float currentheading = Robot::drivetrain->gyro->GetAngle();
	Robot::drivetrain->ArcadeDrive(speed, (straight + currentheading) * kP);
	SmartDashboard::PutNumber("Current Heading: ", currentheading);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	return ((abs(Robot::drivetrain->GetLeftDistance()) >= targetdistance) || ((abs(Robot::drivetrain->GetRightDistance()) >= targetdistance)));
}

// Called once after isFinished returns true
void DriveStraight::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	End();
}
