#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "OI.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

	    gyro = RobotMap::gyro;
		driveEncoder = RobotMap::driveEncoder;
		differentialDrive = RobotMap::differentialDrive;
		leftDrive = RobotMap::leftDrive;
		rightDrive = RobotMap::rightDrive;
		backLeftDrive = RobotMap::backLeftDrive;
		frontLeftDrive = RobotMap::frontLeftDrive;
		backRightDrive = RobotMap::backRightDrive;
		frontRightDrive = RobotMap::frontRightDrive;
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::Reset(){

}

void Drivetrain::ArcadeDrive(double speed, double turn){
	differentialDrive->ArcadeDrive(speed, turn);
}
