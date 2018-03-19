/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Inboard.h"
#include "ArmSwing.h"
#include "Spine.h"

Inboard::Inboard() {
	AddSequential(new ArmSwing(367.5));
	AddSequential(new Spine(Robot::spine->Converter(false, 10), false));
}
