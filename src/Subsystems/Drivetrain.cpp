#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "OI.h"
#include "Commands/DriveWithJoystick.h"

Drivetrain::Drivetrain() : Subsystem("DriveTrain") {
	    CubeFront = true;
		gyro = RobotMap::gyro;

	    leftDriveEncoder = RobotMap::leftDriveEncoder;
		rightDriveEncoder = RobotMap::rightDriveEncoder;

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
	SetDefaultCommand(new DriveWithJoystick());
	// SetDefaultCommand(new MySpecialCommand());
}

void Drivetrain::Reset(){
	ArcadeDrive(0,0);
}

void Drivetrain::ArcadeDrive(double speed, double turn){
	differentialDrive->ArcadeDrive(speed, turn);
}
float Drivetrain::GetDistance() {
	return leftDriveEncoder->GetDistance();
	return rightDriveEncoder->GetDistance();
}
void Drivetrain::Stop(){
	ArcadeDrive(0, 0);
}


