#ifndef ClawOpen_H
#define ClawOpen_H

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class ClawOpen : public Command {
public:
	ClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawOpen_H
