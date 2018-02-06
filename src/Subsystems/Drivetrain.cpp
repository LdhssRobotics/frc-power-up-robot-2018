#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "OI.h"
#include "Commands/DriveWithJoystick.h"

#define SPEED_MULTIPLIER 0.95
Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	    gyro = RobotMap::gyro;
	    CubeFront = true;
	    SmartDashboard::PutString("Front of robot:", "cube");

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
	SetDefaultCommand(new DriveWithJoystick());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}


void Drivetrain::ArcadeDrive(double speed, double turn){
	differentialDrive->ArcadeDrive(speed, turn);
}

void Drivetrain::Stop(){
	ArcadeDrive(0, 0);
}

void Drivetrain::Reset() {
	leftDriveEncoder->Reset();
	rightDriveEncoder->Reset();
	Stop();
}

float Drivetrain::GetDistance(){
	return leftDriveEncoder->GetDistance() && rightDriveEncoder->GetDistance();
}

void Drivetrain::CheckEncoders(){
	if (leftDriveEncoder == rightDriveEncoder){

	}
	else {
		AdjustEncoder();
	}
}

void Drivetrain::AdjustEncoder(){
	if (leftDriveEncoder > rightDriveEncoder){
		frontRightDrive->Set(SPEED_MULTIPLIER * frontRightDrive->Get());
	}
	else if (rightDriveEncoder > leftDriveEncoder){
		frontLeftDrive->Set(SPEED_MULTIPLIER * frontRightDrive->Get());
	}
}
