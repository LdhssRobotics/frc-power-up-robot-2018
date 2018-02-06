
#ifndef DriveStraight_H
#define DriveStraight_H

#include "../RobotMap.h"
#include "WPILib.h"

class DriveStraight: public Command
{
private:

	float heading;
	float speed;
	float duration;

public:

	DriveStraight(float speed, float duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
