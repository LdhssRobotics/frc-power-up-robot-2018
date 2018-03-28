#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Arm : public frc::Subsystem {
private:
	std::shared_ptr<Encoder> armEncoder;
	std::shared_ptr<Encoder> spineEncoder1;
	std::shared_ptr<Encoder> spineEncoder2;
	std::shared_ptr<DigitalInput> bottomShoulderSwitch;

	std::shared_ptr<SpeedController> armMotor1;
	std::shared_ptr<SpeedController> armMotor2;

public:
	Arm();
	void InitDefaultCommand();
	void SetArmSpeed(float speed);
	float GetArmPosition();
	void Reset();
	void ResetArm();
	void ResetArmEncoder();
	void Log();

};

#endif  // Arm_H
