#ifndef DrivrDistance_H
#define DrivrDistance_H

#include "../Robot.h"
#include "WPILib.h"

class DriveDistance : public Command {
private:
	float targetDistance;
public:
	DriveDistance(float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivrDistance_H
