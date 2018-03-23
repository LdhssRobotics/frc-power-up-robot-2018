/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/AutoModes/AutoStraightSwitch.h>
#include "../DriveDistance.h"
#include "../Switch.h"
#include "../OpenClaw.h"
#include "../CloseClaw.h"
#include "../Exchange.h"

/*Auto: drive forward and drop box in switch
 * then put arm and spine in original position
 */

AutoStraightSwitch::AutoStraightSwitch() {
	if (RobotMap::m_robotType == RobotMap::POWERUP || RobotMap::m_robotType == RobotMap::POWERUP_PROTO) {
		AddSequential(new DriveDistance(130));//Ph
		AddSequential(new Switch());
		AddSequential(new OpenClaw());
		Wait(4);
		AddSequential(new CloseClaw());
		AddSequential(new Exchange());
	}
	else if (RobotMap::m_robotType == RobotMap::STEAMWORKS) {
		AddSequential(new DriveDistance(130));
	}
}


