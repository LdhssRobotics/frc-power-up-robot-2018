#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	bottomSpineSwitch1 = RobotMap::bottomSpineSwitch1;
	topSpineSwitch1 = RobotMap::topSpineSwitch1;
	bottomSpineSwitch2 = RobotMap::bottomSpineSwitch2;
	topSpineSwitch2 = RobotMap::topSpineSwitch2;
	bottomShoulderSwitch = RobotMap::bottomShoulderSwitch;
	topShoulderSwitch = RobotMap::topShoulderSwitch;
	frontClawSwitch = RobotMap::frontClawSwitch;
	rearClawSwitch = RobotMap::rearClawSwitch;

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
	armEncoder->Reset();
	spineEncoder1->Reset();
	spineEncoder2->Reset();

	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	spineMotor1->Set(0);
	spineMotor2->Set(0);
}
