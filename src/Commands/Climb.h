/*
 * Climb.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Sayfullah
 */

#ifndef SRC_COMMANDS_CLIMB_H_
#define SRC_COMMANDS_CLIMB_H_

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class Climb : public Command {
public:
	Climb();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_CLIMB_H_ */
