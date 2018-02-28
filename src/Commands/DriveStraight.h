#ifndef DriveStraight_H
#define DriveStraight_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"
#include "SmartDashboard/Sendable.h"

class DriveStraight : public Command {
private:
	double straight;
	float targetdistance;
public:
	DriveStraight(float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveStraight_H
