/*
 * SwitchCommand.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: raven8
 */


#include "Commands/SwitchCommand.h"

SwitchCommand::SwitchCommand() {
}

void SwitchCommand::Initalize() {
	Robot::drivetrain->CubeFront = false;
	SmartDashboard::PutString("Front of Robot:", "scale");
}

bool SwitchCommand::IsFinished() {
	return false;
}

void SwitchCommand::End(){
	Robot::drivetrain->CubeFront = true;
	SmartDashboard::PutString("Front of robot:","cube");
}

void SwitchCommand::Interrupted(){
	SmartDashboard::PutString("Front of robot:","interrupted");
	End();
}


