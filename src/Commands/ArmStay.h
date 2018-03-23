/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "WPILib.h"
#include "RobotMap.h"
#include "Robot.h"

class ArmStay : public Command {
private:
	float armTargetPOS;
public:
	ArmStay();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
