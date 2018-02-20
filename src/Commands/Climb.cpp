/*
 * Climb.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Sayfullah
 */

#include <Commands/Climb.h>

Climb::Climb() {
	Requires(Robot::arm.get());
	Requires(Robot::spine.get());

}

void Climb::Initialize(){

}

void Climb::Execute(){

}

bool Climb::IsFinished(){
	return false;
}

void Climb::Interrupted(){
	End;
}

void Climb::End(){

}
