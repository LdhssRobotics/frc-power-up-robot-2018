/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/AutoModes/Auto90Switch.h>
#include "../DriveDistance.h"
#include "../Switch.h"
#include "../Turn90Degrees.h"
#include "../CloseClaw.h"
#include "../OpenClaw.h"
#include "../Exchange.h"

/*Auto: drive forward, turn 90 degrees then drive forward a bit,
 * do the switch and arm back to original position
 */

Auto90Switch::Auto90Switch(bool isLeft) {
	if (RobotMap::m_robotType == RobotMap::POWERUP || RobotMap::m_robotType == RobotMap::POWERUP_PROTO) {
		AddSequential(new DriveDistance(125));		//Cross auto line a bit to turn in place for switch
		AddSequential(new Turn90Degrees(isLeft));
		AddSequential(new DriveDistance(12));//Ph
		AddSequential(new Switch());
		AddSequential(new OpenClaw());
		Wait(4);
		AddSequential(new CloseClaw());
		AddSequential(new Exchange());
	}else if(RobotMap::m_robotType == RobotMap::STEAMWORKS){
		AddSequential(new DriveDistance(125));//Cross auto line a bit to turn in place for switch
		AddSequential(new Turn90Degrees(isLeft));
		AddSequential(new DriveDistance(12));//Ph
	}
}


