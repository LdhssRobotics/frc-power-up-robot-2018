#ifndef SpineUp_H
#define SpineUp_H

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class Spine : public Command {
public:
	Spine();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpineUp_H
