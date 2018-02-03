#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "OI.h"

#define SPEED_MULTIPLIER 0.95

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
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
	// SetDefaultCommand(new MySpecialCommand());
}

void Drivetrain::Reset(){
	rightDriveEncoder->Reset();
	leftDriveEncoder->Reset();
	Stop();
}

void Drivetrain::ArcadeDrive(double speed, double turn){
	differentialDrive->ArcadeDrive(speed, turn);
}

void Drivetrain::Stop(){
	ArcadeDrive(0,0);
}

float Drivetrain::GetLeftDistance(){
	return leftDriveEncoder->GetDistance();
}

float Drivetrain::GetRightDistance(){
	return rightDriveEncoder->GetDistance();
}

void Drivetrain::CheckEncoders(){
	if (rightDriveEncoder == leftDriveEncoder){

	}
	else {
		AdjustEncoder();
	}
}

void Drivetrain::AdjustEncoder() {
	if (rightDriveEncoder > leftDriveEncoder) {
		//decrease right motor speed by speedchange
		frontRightDrive->Set(SPEED_MULTIPLIER * frontRightDrive->Get());
	}
	else if (leftDriveEncoder > rightDriveEncoder) {
		//decrease left motor speed by speedchange
		frontLeftDrive->Set(SPEED_MULTIPLIER * frontLeftDrive->Get());
	}
}


