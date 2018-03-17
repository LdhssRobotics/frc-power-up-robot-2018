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
	finished = false;
}

void Spine::Initialize(){
	Robot::spine->SetMotorSpeed(0,0);
}

void Spine::Execute(){
	finished = false;
	if ((Robot::spine->GetSpinePos1() < Position) and GoingUp) {
		Robot::spine->SetMotorSpeed(0.8,0.8 + Robot::spine->AdjustSpine(GoingUp));
	}else if ((Robot::spine->GetSpinePos1() > Position) and !GoingUp){
		Robot::spine->SetMotorSpeed(-0.8,-0.8 + Robot::spine->AdjustSpine(GoingUp));
	}else {
		finished = true;
	}
	SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());

}

void Spine::End(){
	Robot::spine->SetMotorSpeed(0,0);
}

bool Spine::IsFinished(){
	return finished;
}

void Spine::Interrupted(){
	End();
}
