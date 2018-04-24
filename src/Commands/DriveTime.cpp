/*
 * DriveTime.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: Noodles
 */

#include "DriveTime.h"
#include "../Robot.h"

DriveTime::DriveTime(double time)
{
	targetDistance = 0;
	timeDistance = time;
	Requires(Robot::drivetrain.get());
}

void DriveTime::Initialize() {
	Robot::drivetrain->Reset();
	SetTimeout(timeDistance);
}

void DriveTime::Execute() {
	//SmartDashboard::PutNumber("Left Distance travelled", Robot::drivetrain->GetLeftDistance());
	//SmartDashboard::PutNumber("Right Distance travelled", Robot::drivetrain->GetRightDistance());
	//SmartDashboard::PutNumber("target distance", targetDistance);
	Robot::drivetrain->ArcadeDrive(-0.65, 0.05);
}

bool DriveTime::IsFinished() {
	return  IsTimedOut();
}

void DriveTime::End() {
	Robot::drivetrain->Stop();
}


void DriveTime::Interrupted() {
	End();
}


