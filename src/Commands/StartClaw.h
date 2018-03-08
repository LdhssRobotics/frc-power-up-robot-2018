/*
 * StartClaw.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Sayfu
 */

#ifndef SRC_COMMANDS_STARTCLAW_H_
#define SRC_COMMANDS_STARTCLAW_H_

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class StartClaw : public Command {
private:
	bool direct;
public:
	StartClaw(bool direction); //true = open , false = close
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_STARTCLAW_H_ */
