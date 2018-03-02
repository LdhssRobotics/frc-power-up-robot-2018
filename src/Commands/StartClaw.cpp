/*
 * StartClaw.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Sayfu
 */

#include <Commands/StartClaw.h>
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

StartClaw::StartClaw(bool direction) { //true = open , false = close
	direct = direction;
}

void StartClaw::Initialize(){
	Robot::arm->SetClawSpeed(0);
	if (direct) {
		Robot::arm->OpenClawMotor();
		SetTimeout(5);
	}else {
		Robot::arm->CloseClawMotor();
		SetTimeout(5);
	}
}

void StartClaw::Execute(){

}

void StartClaw::End(){

}

void StartClaw::Interrupted(){

}

bool StartClaw::IsFinished(){
	return IsTimedOut();
}
