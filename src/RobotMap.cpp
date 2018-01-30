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
		// Arm subsystem
#define CLAW_MOTOR_PORT 4
#define ARM_MOTOR_1_PORT 5
#define ARM_MOTOR_2_PORT 6
#define SPINE_MOTOR_1_PORT 7
#define SPINE_MOTOR_2_PORT 8

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 0
#define BACK_LEFT_DRIVE_PORT 1
#define FRONT_RIGHT_DRIVE_PORT 2
#define BACK_RIGHT_DRIVE_PORT 3

	// Digital Ports
		// Arm subsystem
#define SPINE_ENCODER_1_A_PORT 4
#define SPINE_ENCODER_1_B_PORT 5
#define SPINE_ENCODER_2_A_PORT 6
#define SPINE_ENCODER_2_B_PORT 7
#define ARM_ENCODER_1_A_PORT 8
#define ARM_ENCODER_1_B_PORT 9
#define ARM_ENCODER_2_A_PORT 10
#define ARM_ENCODER_2_B_PORT 11
#define SPINE_SWITCH_PORT 12

		// Drivetrain subsystem
#define LEFT_DRIVE_ENCODER_A_PORT 0
#define LEFT_DRIVE_ENCODER_B_PORT 1
#define RIGHT_DRIVE_ENCODER_A_PORT 2
#define RIGHT_DRIVE_ENCODER_B_PORT 3

	//Analog Ports
#define GYRO_PORT 0

// POINTERS
	// Arm subsystem
std::shared_ptr<Encoder> RobotMap::armEncoder1;
std::shared_ptr<Encoder> RobotMap::armEncoder2;
std::shared_ptr<Encoder> RobotMap::spineEncoder1;
std::shared_ptr<Encoder> RobotMap::spineEncoder2;
std::shared_ptr<DigitalInput> RobotMap::spineSwitch;

std::shared_ptr<SpeedController> RobotMap::armMotor1;
std::shared_ptr<SpeedController> RobotMap::armMotor2;
std::shared_ptr<SpeedController> RobotMap::clawMotor;
std::shared_ptr<SpeedController> RobotMap::spineMotor1;
std::shared_ptr<SpeedController> RobotMap::spineMotor2;

	// Drivetrain subsystem
std::shared_ptr<AnalogGyro> RobotMap::gyro;
std::shared_ptr<Encoder> RobotMap::leftDriveEncoder;
std::shared_ptr<Encoder> RobotMap::rightDriveEncoder;

std::shared_ptr<SpeedController> RobotMap::backLeftDrive;
std::shared_ptr<SpeedController> RobotMap::backRightDrive;
std::shared_ptr<SpeedController> RobotMap::frontLeftDrive;
std::shared_ptr<SpeedController> RobotMap::frontRightDrive;
std::shared_ptr <SpeedControllerGroup> RobotMap::leftDrive;
std::shared_ptr<SpeedControllerGroup> RobotMap::rightDrive;

std::shared_ptr<DifferentialDrive> RobotMap::differentialDrive;

void RobotMap::init() {
	LiveWindow *lw = LiveWindow::GetInstance();
	Sendable *s;

	// Arm subsystem
	armEncoder1.reset(new Encoder(ARM_ENCODER_1_A_PORT, ARM_ENCODER_1_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Arm", "Encoder 1");
	armEncoder1->SetMaxPeriod(0.1);
	armEncoder1->SetMinRate(1);
	armEncoder1->SetSamplesToAverage(15);
	armEncoder1->SetReverseDirection(true);
	armEncoder1->SetDistancePerPulse(3.14159265358979323*6.0/360.0); //PLACEHOLDER

	armEncoder2.reset(new Encoder(ARM_ENCODER_2_A_PORT, ARM_ENCODER_2_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Arm", "Encoder 2");
	armEncoder2->SetMaxPeriod(0.1);
	armEncoder2->SetMinRate(1);
	armEncoder2->SetSamplesToAverage(15);
	armEncoder2->SetReverseDirection(true);
	armEncoder2->SetDistancePerPulse(3.14159265358979323*6.0/360.0); //PLACEHOLDER

	spineEncoder1.reset(new Encoder(SPINE_ENCODER_1_A_PORT, SPINE_ENCODER_1_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Spine", "Encoder 1");
	spineEncoder1->SetMaxPeriod(0.1);
	spineEncoder1->SetMinRate(1);
	spineEncoder1->SetSamplesToAverage(15);
	spineEncoder1->SetReverseDirection(true);
	spineEncoder1->SetDistancePerPulse(3.14159265358979323*6.0/360.0); //PLACEHOLDER

	spineEncoder2.reset(new Encoder(SPINE_ENCODER_2_A_PORT, SPINE_ENCODER_2_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Spine", "Encoder 2");
	spineEncoder2->SetMaxPeriod(0.1);
	spineEncoder2->SetMinRate(1);
	spineEncoder2->SetSamplesToAverage(15);
	spineEncoder2->SetReverseDirection(true);
	spineEncoder2->SetDistancePerPulse(3.14159265358979323*6.0/360.0); //PLACEHOLDER

	spineSwitch.reset(new DigitalInput(SPINE_SWITCH_PORT));

	armMotor1.reset(new PWMTalonSRX(ARM_MOTOR_1_PORT));
	armMotor2.reset(new PWMTalonSRX(ARM_MOTOR_2_PORT));
	clawMotor.reset(new PWMTalonSRX(CLAW_MOTOR_PORT));
	spineMotor1.reset(new PWMTalonSRX(SPINE_MOTOR_1_PORT));
	spineMotor2.reset(new PWMTalonSRX(SPINE_MOTOR_2_PORT));

	// Drivetrain subsystem
	leftDriveEncoder.reset(new Encoder(LEFT_DRIVE_ENCODER_A_PORT, LEFT_DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Drive", "Left encoder");
	leftDriveEncoder->SetMaxPeriod(0.1);
	leftDriveEncoder->SetMinRate(1);
	leftDriveEncoder->SetSamplesToAverage(15);
	leftDriveEncoder->SetReverseDirection(true);
	leftDriveEncoder->SetDistancePerPulse(3.14159265358979323*6.0/360.0); //PLACEHOLDER

	rightDriveEncoder.reset(new Encoder(RIGHT_DRIVE_ENCODER_A_PORT, RIGHT_DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	s->SetName("Drive", "Right encoder");
	rightDriveEncoder->SetMaxPeriod(0.1);
	rightDriveEncoder->SetMinRate(1);
	rightDriveEncoder->SetSamplesToAverage(15);
	rightDriveEncoder->SetReverseDirection(true);
	rightDriveEncoder->SetDistancePerPulse(3.14159265358979323*6.0/360.0); //PLACEHOLDER

	backLeftDrive.reset(new PWMTalonSRX(BACK_LEFT_DRIVE_PORT));
	backRightDrive.reset(new PWMTalonSRX(BACK_RIGHT_DRIVE_PORT));
	frontLeftDrive.reset(new PWMTalonSRX(FRONT_LEFT_DRIVE_PORT));
	frontRightDrive.reset(new PWMTalonSRX(FRONT_RIGHT_DRIVE_PORT));

	backLeftDrive->SetInverted(true);
	backRightDrive->SetInverted(false);
	frontLeftDrive->SetInverted(true);
	frontRightDrive->SetInverted(false);

	leftDrive = std::make_shared <SpeedControllerGroup>(*backLeftDrive, *frontLeftDrive);
	rightDrive = std::make_shared <SpeedControllerGroup>(*backRightDrive, *frontRightDrive);
	differentialDrive.reset(new DifferentialDrive(*leftDrive, *rightDrive));

	differentialDrive->SetSafetyEnabled(false);
	differentialDrive->SetExpiration(0.1);
	differentialDrive->SetMaxOutput(1.0);

	gyro.reset(new AnalogGyro(GYRO_PORT));
	s->SetName("Drive", "Gyro");
	gyro->SetSensitivity(0.00666);
	gyro->Calibrate();
}

void RobotMap::reset() {
	Robot::arm->Reset();
	Robot::drivetrain->Reset();
	}

#endif /* SRC_ROBOTMAP_CPP_ */
