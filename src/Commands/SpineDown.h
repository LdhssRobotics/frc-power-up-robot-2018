#ifndef SpineDown_H
#define SpineDown_H

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class SpineDown : public Command {
public:
	SpineDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpineDown_H
