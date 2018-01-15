#include "Drivetrain.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

	gyro = RobotMap::gyro;
		driveEncoder = RobotMap::driveEncoder;
		differentialDrive = RobotMap::differentialDrive;

		frontLeftDrive = RobotMap::frontLeftDrive;
		backLeftDrive = RobotMap::backLeftDrive;
		frontRightDrive = RobotMap::frontRightDrive;
		backRightDrive = RobotMap::backRightDrive;
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::Reset(){

}
