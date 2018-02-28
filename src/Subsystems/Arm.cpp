#include "Arm.h"
#include "../RobotMap.h"
#include "Drivetrain.h"
#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"
#include "SmartDashboard/Sendable.h"
#include "WPILib.h"
#include "Commands/CloseClaw.h"

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

	IsClawClosed = false;
}

void Arm::InitDefaultCommand() {

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new CloseClaw());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::Reset(){
	armEncoder.reset();
	spineEncoder1.reset();
	spineEncoder2.reset();

	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	spineMotor1->Set(0);
	spineMotor2->Set(0);
}

void Arm::OpenClawMotor(){
	clawMotor->Set(0.8);
}
void Arm::CloseClawMotor(){
	clawMotor->Set(-0.8);
}
void Arm::StopClaw(){
	clawMotor->Set(0);
}
bool Arm::LimitSwitchState(){
	SmartDashboard::PutBoolean("Claw Limit Switch State: ", rearClawSwitch.get());
	return(rearClawSwitch.get());
}
double Arm::CurrentDraw(){
	double current = 0.0;
	if (RobotMap::m_robotType != RobotMap::STEAMWORKS) {
		current = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(clawMotor)->GetOutputCurrent();
		SmartDashboard::PutNumber("Talon SRX - current: ", current);
	}
	else {
		current = 20.0;  // value large enough to stop the claw
	}
	return (current);
}
