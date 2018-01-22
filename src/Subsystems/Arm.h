#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Arm : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<Encoder> armEncoder;

public:
	Arm();
	void InitDefaultCommand();
	void Reset();
	void ResetEncoder();
	void Log();
	float GetPosition();
};


#endif  // Arm_H
