/*
 * SwitchCommand.h
 *
 *  Created on: Feb 1, 2018
 *      Author: raven8
 */

#ifndef SRC_COMMANDS_SWITCHCOMMAND_H_
#define SRC_COMMANDS_SWITCHCOMMAND_H_

#include "../Robot.h"
#include "RobotMap.h"
#include <WPILib.h>


class SwitchCommand : public Command{
public:
	SwitchCommand();
	void Initalize();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif /* SRC_COMMANDS_SWITCHCOMMAND_H_ */
