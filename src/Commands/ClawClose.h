#ifndef ClawClose_H
#define ClawClose_H

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class ClawClose : public Command {
public:
	ClawClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawClose_H
