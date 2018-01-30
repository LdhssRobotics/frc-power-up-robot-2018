#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() : Subsystem("Arm") {
	armEncoder1 = RobotMap::armEncoder1;
	armEncoder2 = RobotMap::armEncoder2;
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	spineSwitch = RobotMap::spineSwitch;

	armMotor1 = RobotMap::armMotor1;
	armMotor2 = RobotMap::armMotor2;
	clawMotor = RobotMap::clawMotor;
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::Reset(){
	armEncoder1->Reset();
	armEncoder2->Reset();
	spineEncoder1->Reset();
	spineEncoder2->Reset();

	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	spineMotor1->Set(0);
	spineMotor2->Set(0);
}
