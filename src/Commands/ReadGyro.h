#pragma once

#include <Commands/CommandGroup.h>
#include "RobotMap.h"
#include "Robot.h"
#include "WPILib.h"

class ReadGyro : public Command {
public:
	ReadGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
