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

	bool IsClawClosed;

public:
	Arm();
	void InitDefaultCommand();
	void Arm::OpenClaw();
	void Arm::CloseClaw();
	bool Arm::LimitSwitchState();
	double Arm::CurrentDraw();
	void Reset();

};

#endif  // Arm_H
