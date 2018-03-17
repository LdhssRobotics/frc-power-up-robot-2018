/*
 * Spine.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#include <Commands/Spine.h>

Spine::Spine(float P, bool isGoingUp) {
	Requires(Robot::spine.get());
	Position = P;
	GoingUp = isGoingUp;

}

void Spine::Initialize(){
	Robot::spine->SetMotorSpeed(0,0);
}

void Spine::Execute(){
	if (Robot::spine->GetSpinePos1() < Position) {
		Robot::spine->SetMotorSpeed(0.8,0.8 + Robot::spine->AdjustSpine(GoingUp));
	}else if (Robot::spine->GetSpinePos1() > Position){
		Robot::spine->SetMotorSpeed(-0.8,-0.8 + Robot::spine->AdjustSpine(GoingUp));
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
