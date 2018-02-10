#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "OI.h"
#include "Commands/DriveWithJoystick.h"

#define SPEED_MULTIPLIER 0.95

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
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::Reset(){
	Stop();
	ResetEncoder();
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

float Drivetrain::GetLeftCount(){
	return leftDriveEncoder->Get();
}

float Drivetrain::GetRightCount(){
	return rightDriveEncoder->Get();
}
void Drivetrain::TankDrive(double leftSpeed, double rightSpeed){
	differentialDrive->TankDrive(leftSpeed, rightSpeed);
}

void Drivetrain::ResetEncoder(){
	rightDriveEncoder->Reset();
	leftDriveEncoder->Reset();
}

void Drivetrain::Debug() {
	SmartDashboard::PutNumber("Encoder Right Distance", rightDriveEncoder->GetDistance());
	SmartDashboard::PutNumber("Encoder Left Distance", leftDriveEncoder->GetDistance());

	SmartDashboard::PutNumber("Left Current Count", leftDriveEncoder->Get());
	SmartDashboard::PutNumber("Right Current Count", rightDriveEncoder->Get());

	SmartDashboard::PutNumber("Left Period", leftDriveEncoder->GetPeriod());
	SmartDashboard::PutNumber("Right Period", rightDriveEncoder->GetPeriod());

	SmartDashboard::PutNumber("Left Rate", leftDriveEncoder->GetRate());
	SmartDashboard::PutNumber("Right Rate", rightDriveEncoder->GetRate());

	SmartDashboard::PutNumber("Left Raw", leftDriveEncoder->GetRaw());
	SmartDashboard::PutNumber("Right Raw", rightDriveEncoder->GetRaw());
}
