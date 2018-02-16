/*
 * Spine.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Sayfullah
 */

#include "Subsystems/SpineSubSystem.h"
#include "../RobotMap.h"
#include "Robot.h"

#include <algorithm>

#include "Commands/Spine.h"
#include "Commands/ArmSwing.h"

SpineSubSystem::SpineSubSystem() : Subsystem("SpineSubSystem")  {
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;

	differentialSpine = RobotMap::differentialSpine;

}

void SpineSubSystem::InitDefaultCommand(){
	SetDefaultCommand(new Spine());
}

double SpineSubSystem::AdjustSpine() {
	double difference = (GetSpinePos2() - GetSpinePos1()) / GetSpinePos1();
	return (1-difference);
}

void SpineSubSystem::DifferentialSpine(double leftSpeed, double rightSpeed) {
	differentialSpine->TankDrive(leftSpeed, rightSpeed);
}

float SpineSubSystem::GetSpinePos1(){
	return Robot::spine->spineEncoder1->Get();
}

float SpineSubSystem::GetSpinePos2(){
	return Robot::spine->spineEncoder2->Get();
}

void SpineSubSystem::ResetSpineEncoder1(){
	Robot::spine->spineEncoder1->Reset();
}

void SpineSubSystem::ResetSpineEncoder2(){
	Robot::spine->spineEncoder2->Reset();
}

void SpineSubSystem::Reset(){
	DifferentialSpine(0,0);
	ResetSpineEncoder1();
	ResetSpineEncoder2();
}
