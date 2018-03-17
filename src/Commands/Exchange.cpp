/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Exchange.h"
#include "ArmSwing.h"
#include "Spine.h"

Exchange::Exchange() {
	SmartDashboard::PutString("Command", "Exchange");
	AddSequential(new ArmSwing(0));
	AddSequential(new Spine(0, false));

}
