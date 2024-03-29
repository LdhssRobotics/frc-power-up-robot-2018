/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Switch.h"
#include "Spine.h"
#include "ArmSwing.h"

Switch::Switch() {
	SmartDashboard::PutString("Command", "Switch");
	AddSequential(new Spine(1250000, true));
	AddSequential(new ArmSwing(735, true));

}
