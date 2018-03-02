/*
 * Spine.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#include <Commands/Spine.h>

Spine::Spine(float position):
Position(position)
{
	// TODO Auto-generated constructor stub
	Requires(Robot::spine.get());

}

void Spine::Initialize(){
	Robot::spine->SetMotorSpeed(0,0);
}

void Spine::Execute(){
	if (Robot::spine->GetSpinePos1() < Position) {
		//Robot::spine->SetMotorSpeed(0.85,0.85 * Robot::spine->AdjustSpine());
	}else if (Robot::spine->GetSpinePos1() > Position){
		//Robot::spine->SetMotorSpeed(-0.85,-0.85 * Robot::spine->AdjustSpine());
	}else {
		End();
	}
}

void Spine::End(){
	Robot::spine->SetMotorSpeed(0,0);
}

bool Spine::IsFinished(){
	return false;
}

void Spine::Interrupted(){
	End();
}
