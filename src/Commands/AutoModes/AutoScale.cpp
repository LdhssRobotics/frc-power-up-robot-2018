/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/AutoModes/AutoScale.h>
#include "../DriveDistance.h"
#include "../Switch.h"
#include "../Turn45Degrees.h"
#include "../CloseClaw.h"
#include "../OpenClaw.h"
#include "../Exchange.h"
#include "../Scale.h"

/*Auto: drive forward and while doing that start the scale motion
 * turn 45 degrees, drive forward and drop box in scale,
 * back up and put arm and spine in original position
 */
AutoScale::AutoScale(bool isLeft) {
	if (RobotMap::m_robotType == RobotMap::POWERUP || RobotMap::m_robotType == RobotMap::POWERUP_PROTO) {
		AddSequential(new DriveDistance(10));//Ph
		AddParallel(new Scale());
		AddSequential(new Turn45Degrees(isLeft));
		AddSequential(new DriveDistance(10));//Ph
		AddSequential(new OpenClaw());
		Wait(4);
		AddSequential(new CloseClaw());
		AddSequential(new DriveDistance(-10));//Ph
		AddSequential(new Exchange());
	} else if(RobotMap::m_robotType == RobotMap::STEAMWORKS){
		AddSequential(new DriveDistance(10));//Ph
		AddParallel(new Scale());
		AddSequential(new Turn45Degrees(isLeft));
		AddSequential(new DriveDistance(10));//Ph
		Wait(4);
		AddSequential(new DriveDistance(-10));
	}

}


