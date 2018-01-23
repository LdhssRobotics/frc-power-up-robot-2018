/*
 * RobotMap.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: Madeline
 */

#ifndef SRC_ROBOTMAP_CPP_
#define SRC_ROBOTMAP_CPP_

#include "RobotMap.h"
#include "Robot.h"
#include "SmartDashboard/Sendable.h"
#include "Encoder.h"

// PORT MAPPINGS
	// PWM Ports
		// Climber subsystem
#define WINCH_MOTOR_PORT 1
#define RATCHET_SERVO_PORT 2
#define FLAP_SERVO_PORT 0

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 3
#define BACK_LEFT_DRIVE_PORT 4
#define FRONT_RIGHT_DRIVE_PORT 6
#define BACK_RIGHT_DRIVE_PORT 7

		// Gear subsystem
#define GEAR_MOTOR_PORT 5

	// Digital Ports
		// Drivetrain subsystem
#define DRIVE_ENCODER_A_PORT 0
#define DRIVE_ENCODER_B_PORT 1

		// Arm subsystem
#define ARM_ENCODER_A_PORT 6
#define ARM_ENCODER_B_PORT 7

#define GEAR_LIMIT_SWITCH_PORT 8


	//Analog Ports
#define GYRO_PORT 0

// POINTERS

// Arm subsytem
std::shared_ptr<Encoder> RobotMap::armEncoder;

// Climber subsystem
std::shared_ptr<SpeedController> RobotMap::winchMotor;
std::shared_ptr<Servo> RobotMap::rachetServo;
std::shared_ptr<Servo> RobotMap::flapServo;

	// Drivetrain subsystem
std::shared_ptr<AnalogGyro> RobotMap::gyro;
std::shared_ptr<Encoder> RobotMap::driveEncoder;

std::shared_ptr<SpeedController> RobotMap::backLeftDrive;
std::shared_ptr<SpeedController> RobotMap::backRightDrive;
std::shared_ptr<SpeedController> RobotMap::frontLeftDrive;
std::shared_ptr<SpeedController> RobotMap::frontRightDrive;
std::shared_ptr <SpeedControllerGroup> RobotMap::leftDrive;
std::shared_ptr<SpeedControllerGroup> RobotMap::rightDrive;

//DifferentialDrive differentialDrive (RobotMap::leftDrive, RobotMap::rightDrive);
std::shared_ptr<DifferentialDrive> RobotMap::differentialDrive;



void RobotMap::init() {
	//LiveWindow *lw = LiveWindow::GetInstance();
	Sendable *s;

	// Arm subsystem
	armEncoder.reset(new Encoder(ARM_ENCODER_A_PORT,
				ARM_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	armEncoder->SetMaxPeriod(0.1);
		armEncoder->SetMinRate(1);
		armEncoder->SetSamplesToAverage(7);
		armEncoder->SetReverseDirection(false);
		armEncoder->SetDistancePerPulse(1); // Not accurate measurement, ratio instead


	// Climber subsystem
	winchMotor.reset(new Victor(WINCH_MOTOR_PORT));
	rachetServo.reset(new Servo(RATCHET_SERVO_PORT));

	flapServo.reset(new Servo(FLAP_SERVO_PORT));

	s->SetName("Climb", "Flap");


	// Drivetrain subsystem
	driveEncoder.reset(new Encoder(DRIVE_ENCODER_A_PORT, DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Drive", "Encoder");

	driveEncoder->SetMaxPeriod(0.1);
	driveEncoder->SetMinRate(1);
	driveEncoder->SetSamplesToAverage(15);
	driveEncoder->SetReverseDirection(true);
	driveEncoder->SetDistancePerPulse(3.14159265358979323*6.0/360.0);

	frontLeftDrive.reset(new Victor(FRONT_LEFT_DRIVE_PORT));

	backLeftDrive.reset(new Victor(BACK_LEFT_DRIVE_PORT));
	backRightDrive.reset(new Victor(BACK_RIGHT_DRIVE_PORT));
	frontLeftDrive.reset(new Victor(FRONT_LEFT_DRIVE_PORT));
	frontRightDrive.reset(new Victor(FRONT_RIGHT_DRIVE_PORT));

	backRightDrive->SetInverted(false);
	frontRightDrive->SetInverted(false);

	leftDrive = std::make_shared <SpeedControllerGroup>(*backLeftDrive, *frontLeftDrive);
	rightDrive = std::make_shared <SpeedControllerGroup>(*backRightDrive, *frontRightDrive);
	differentialDrive.reset(new DifferentialDrive(*leftDrive, *rightDrive));


	differentialDrive->SetSafetyEnabled(false);
	differentialDrive->SetExpiration(0.1);
	//differentialDrive->SetSensitivity(0.65);
	differentialDrive->SetMaxOutput(1.0);

	gyro.reset(new AnalogGyro(GYRO_PORT));
	s->SetName("Drive", "Gyro");

	gyro->SetSensitivity(0.00666);
	gyro->Calibrate();

	// Arm subsystem

}

void RobotMap::reset() {
	Robot::drivetrain->Reset();
	Robot::arm->Reset();
	}




#endif /* SRC_ROBOTMAP_CPP_ */
