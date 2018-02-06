#ifndef DriveDistance_H
#define DriveDistance_H

#include "../Robot.h"
#include <WPILib.h>

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

#endif  // DriveDistance_H
