#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;

}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::Reset(){
	ResetEncoder();
}

void Arm::ResetEncoder(){
	armEncoder->Reset();
	Log();
}

void Arm::Log() {
	SmartDashboard::PutNumber("Arm encoder:", GetPosition());
}

//checks the current position of the encoder
float Arm::GetPosition() {
	return armEncoder->GetDistance();
}
