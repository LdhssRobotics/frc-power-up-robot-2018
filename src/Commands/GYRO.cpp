/*
 * GYRO.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author:
 */

#include "GYRO.h"
#include "WPILib.h"
#include "Robot.h"
#include "Subsystems/Drivetrain.h"


const float kp = 0.025; //variable to make sure the turning increments are to extreme

GYRO::GYRO(float heading)	:
			goalAngle(heading) //getting the angle you want to have
{
	Requires(Robot::drivetrain.get());

}
void GYRO::Initialize(){
	Robot::drivetrain->Reset(); //if 3 seconds pass the program will end
	SetTimeout(3);
}

void GYRO::Execute() {	 /*goal=what we want the and to be*/ /*get heading=what the angle is*/
	double turnIncrement = (goalAngle - Robot::drivetrain->GetHeading())*kp;
	if (turnIncrement < -0.5) {
		turnIncrement = -0.5;	//it will turn by increments of 0.5
		}
	if (turnIncrement > 0.5) {
		turnIncrement = 0.5;	//it will turn by increments of 0.5
		}
//Turn Robot, trying to figure out proper ratios
Robot::drivetrain->frontLeftDrive->Set(turnIncrement);
Robot::drivetrain->backLeftDrive->Set(turnIncrement);		//turning
Robot::drivetrain->frontRightDrive->Set(turnIncrement);
Robot::drivetrain->backRightDrive->Set(turnIncrement);
SmartDashboard::PutNumber("Goal Angle: ", goalAngle);	//displaying on the smartdashboard what the variables are
SmartDashboard::PutNumber("Real Heading: ", Robot::drivetrain->GetHeading());
SmartDashboard::PutNumber("Turn Increment: ", turnIncrement);

}
// Make this return true when this Command no longer needs to run execute()
bool GYRO::IsFinished()
{
	//Determine if robot has attained target within 2 degrees on each side
	return IsTimedOut() || ((goalAngle + 2) >= Robot::drivetrain->GetHeading() && ((goalAngle - 2) <= Robot::drivetrain->GetHeading()));
}
// Called once after isFinished returns true
void GYRO::End()
{
	Robot::drivetrain->Stop();
}

void GYRO::Interrupted()
{
	End();
}

