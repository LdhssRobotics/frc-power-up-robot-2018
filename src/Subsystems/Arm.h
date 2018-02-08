#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Arm : public frc::Subsystem {
private:
	std::shared_ptr<Encoder> armEncoder;
	std::shared_ptr<Encoder> spineEncoder1;
	std::shared_ptr<Encoder> spineEncoder2;
	std::shared_ptr<DigitalInput> bottomSpineSwitch1;
	std::shared_ptr<DigitalInput> topSpineSwitch1;
	std::shared_ptr<DigitalInput> bottomSpineSwitch2;
	std::shared_ptr<DigitalInput> topSpineSwitch2;
	std::shared_ptr<DigitalInput> bottomShoulderSwitch;
	std::shared_ptr<DigitalInput> topShoulderSwitch;
	std::shared_ptr<DigitalInput> frontClawSwitch;
	std::shared_ptr<DigitalInput> rearClawSwitch;

	std::shared_ptr<SpeedController> armMotor1;
	std::shared_ptr<SpeedController> armMotor2;
	std::shared_ptr<SpeedController> clawMotor;
	std::shared_ptr<SpeedController> spineMotor1;
	std::shared_ptr<SpeedController> spineMotor2;

public:
	Arm();
	void InitDefaultCommand();
	void SetMotorSpeedArm(float speed);
	void SetMotorSpeedSpine(float speed);
	void SetMotorSpeedClaw(float speed);
	bool InSpineMaxPosition();
	bool InSpineMinPosition();
	float GetArmPosition();
	float GetSpinePosition();
	float SetMaxPositionArm();
	float SetMinPositionArm();
	float SetMaxPositionSpine();
	float SetMinPositionSpine();
	float SetMaxPositionClaw();
	float SetMinPositionClaw();
	float SafetyPositionSpine();

	void Reset();
	void ResetEncoder();
	void Log();
};

#endif  // Arm_H
