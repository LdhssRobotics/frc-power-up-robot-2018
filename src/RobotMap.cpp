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
#define GEAR_ENCODER_A_PORT 6
#define GEAR_ENCODER_B_PORT 7

#define GEAR_LIMIT_SWITCH_PORT 8


	//Analog Ports
#define GYRO_PORT 0

// POINTERS
	// Climber subsystem
std::shared_ptr<SpeedController> RobotMap::winchMotor;
std::shared_ptr<Servo> RobotMap::rachetServo;
std::shared_ptr<Servo> RobotMap::flapServo;

	// Drivetrain subsystem
std::shared_ptr<AnalogGyro> RobotMap::gyro;
std::shared_ptr<Encoder> RobotMap::driveEncoder;

frc::SpeedControllerGroup leftDrive (RobotMap::frontLeftDrive, RobotMap::backLeftDrive);
frc::SpeedControllerGroup rightDrive (RobotMap::frontRightDrive, RobotMap::backRightDrive);

frc::DifferentialDrive RobotMap::differentialDrive (leftDrive, rightDrive);
std::shared_ptr<DifferentialDrive> RobotMap::differentialDrive;

	// Gear subsystem
std::shared_ptr<Encoder> RobotMap::gearEncoder;
std::shared_ptr<SpeedController> RobotMap::gearMotor;
std::shared_ptr<DigitalInput> RobotMap::gearLimitSwitch;

	// Ultrasonic subsystem
std::shared_ptr<Ultrasonic> RobotMap::ultrasonic;

void RobotMap::init() {
	//LiveWindow *lw = LiveWindow::GetInstance();
	Sendable *s;

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

	backLeftDrive.reset(new Victor(BACK_LEFT_DRIVE_PORT));
	backRightDrive.reset(new Victor(BACK_RIGHT_DRIVE_PORT));
	frontLeftDrive.reset(new Victor(FRONT_LEFT_DRIVE_PORT));
	frontRightDrive.reset(new Victor(FRONT_RIGHT_DRIVE_PORT));

	backRightDrive->SetInverted(false);
	frontRightDrive->SetInverted(false);

	differentialDrive.reset(new DifferentialDrive);


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
