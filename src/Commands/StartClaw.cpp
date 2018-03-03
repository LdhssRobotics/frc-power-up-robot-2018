/*
 * StartClaw.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Owen
 */

#include <Commands/StartClaw.h>
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

StartClaw::StartClaw(bool direction) {
	direct = direction;
}

void StartClaw::Initialize(){
	Robot::arm->SetClawSpeed(0);
	if (direct) {
		Robot::arm->OpenClawMotor();
		SetTimeout(5);
	} else {
		Robot::arm->CloseClawMotor();
		SetTimeout(5);
	}
}

void StartClaw::Execute(){

}

void StartClaw::End(){

}

void StartClaw::Interupted(){

}

bool StartClaw::IsFinished(){
	return IsTimedOut();
}
