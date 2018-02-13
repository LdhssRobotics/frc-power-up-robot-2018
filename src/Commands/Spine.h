#ifndef SpineUp_H
#define SpineUp_H

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class SpineUp : public Command {
public:
	SpineUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpineUp_H
