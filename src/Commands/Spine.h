#ifndef Spine_H
#define Spine_H

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

#endif  // Spine_H
