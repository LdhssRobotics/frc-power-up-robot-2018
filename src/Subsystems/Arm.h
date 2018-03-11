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
	std::shared_ptr<SpeedController> clawMotor;



public:
	Arm();
	void InitDefaultCommand();
	void Log();
	void Reset();
	/* Do we need this? */
	bool LimitSwitchState();
	// Arm/Shoulder Functions
	void SetArmSpeed(float speed);
	float GetArmPosition();
	float GetCurrentArmPosition();
	void ResetArm();
	void ResetArmEncoder();
	// Claw Functions
	void SetClawSpeed(float speed);
	void OpenClawMotor();
	void CloseClawMotor();
	void StopClaw();
	double CurrentDraw();
	// Claw Variables
	bool IsClawClosed;

};

#endif  // Arm_H
