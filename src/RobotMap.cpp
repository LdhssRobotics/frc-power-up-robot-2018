/*
 * RobotMap.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: Madeline
 */

#ifndef SRC_ROBOTMAP_CPP_
#define SRC_ROBOTMAP_CPP_

//For Pi Const
#include <math.h>

#include "RobotMap.h"
#include "Robot.h"
#include "SmartDashboard/Sendable.h"
#include "Encoder.h"

// PORT MAPPINGS
	// PWM Ports
		// Arm subsystem
#define CLAW_MOTOR_PORT 8
#define ARM_MOTOR_1_PORT 6 // in wiring, 1 = left; 2 = right
#define ARM_MOTOR_2_PORT 7
#define SPINE_MOTOR_1_PORT 4
#define SPINE_MOTOR_2_PORT 5

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 2
#define BACK_LEFT_DRIVE_PORT 3
#define FRONT_RIGHT_DRIVE_PORT 0
#define BACK_RIGHT_DRIVE_PORT 1

	// Digital Ports
		// Arm subsystem
#define SPINE_ENCODER_1_A_PORT 14
#define SPINE_ENCODER_1_B_PORT 15
#define SPINE_ENCODER_2_A_PORT 16
#define SPINE_ENCODER_2_B_PORT 17
#define ARM_ENCODER_A_PORT 18
#define ARM_ENCODER_B_PORT 19
#define BOTTOM_SPINE_SWITCH_1_PORT 20 // PH
#define TOP_SPINE_SWITCH_1_PORT 21 // PH
#define BOTTOM_SPINE_SWITCH_2_PORT 22 // PH
#define TOP_SPINE_SWITCH_2_PORT 23 // PH
#define BOTTOM_SHOULDER_SWITCH_PORT 24 // PH
#define TOP_SHOULDER_SWITCH_PORT 25 // PH
#define FRONT_CLAW_SWITCH_PORT 26 // PH
#define REAR_CLAW_SWITCH_PORT 27 // PH

		// Drivetrain subsystem
#define LEFT_DRIVE_ENCODER_A_PORT 10
#define LEFT_DRIVE_ENCODER_B_PORT 11
#define RIGHT_DRIVE_ENCODER_A_PORT 12
#define RIGHT_DRIVE_ENCODER_B_PORT 13

	//Analog Ports
#define GYRO_PORT 0
#define LEFT_LIGHT_REFLECTOR_PORT 1
#define RIGHT_LIGHT_REFLECTOR_PORT 2

// POINTERS
	// Arm subsystem
std::shared_ptr<Encoder> RobotMap::armEncoder;
std::shared_ptr<Encoder> RobotMap::spineEncoder1;
std::shared_ptr<Encoder> RobotMap::spineEncoder2;
std::shared_ptr<DigitalInput> RobotMap::bottomSpineSwitch1;
std::shared_ptr<DigitalInput> RobotMap::topSpineSwitch1;
std::shared_ptr<DigitalInput> RobotMap::bottomSpineSwitch2;
std::shared_ptr<DigitalInput> RobotMap::topSpineSwitch2;
std::shared_ptr<DigitalInput> RobotMap::bottomShoulderSwitch;
std::shared_ptr<DigitalInput> RobotMap::topShoulderSwitch;
std::shared_ptr<DigitalInput> RobotMap::frontClawSwitch;
std::shared_ptr<DigitalInput> RobotMap::rearClawSwitch;

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
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

	// Arm subsystem
	armEncoder.reset(new Encoder(ARM_ENCODER_A_PORT, ARM_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
		armEncoder->Sendable::SetName("Arm", "encoder");
		armEncoder->SetMaxPeriod(0.1);
		armEncoder->SetMinRate(1);
		armEncoder->SetSamplesToAverage(15);
		armEncoder->SetReverseDirection(true);
		armEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	spineEncoder1.reset(new Encoder(SPINE_ENCODER_1_A_PORT, SPINE_ENCODER_1_B_PORT, false, Encoder::EncodingType::k4X));
		spineEncoder1->Sendable::SetName("Spine", "encoder 1");
		spineEncoder1->SetMaxPeriod(0.1);
		spineEncoder1->SetMinRate(1);
		spineEncoder1->SetSamplesToAverage(15);
		spineEncoder1->SetReverseDirection(true);
		spineEncoder1->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	spineEncoder2.reset(new Encoder(SPINE_ENCODER_2_A_PORT, SPINE_ENCODER_2_B_PORT, false, Encoder::EncodingType::k4X));
		spineEncoder2->Sendable::SetName("Spine", "encoder 2");
		spineEncoder2->SetMaxPeriod(0.1);
		spineEncoder2->SetMinRate(1);
		spineEncoder2->SetSamplesToAverage(15);
		spineEncoder2->SetReverseDirection(true);
		spineEncoder2->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	bottomSpineSwitch1.reset(new DigitalInput(BOTTOM_SPINE_SWITCH_1_PORT));
		bottomSpineSwitch1->Sendable::SetName("Spine", "bottom switch 1");
	topSpineSwitch1.reset(new DigitalInput(TOP_SPINE_SWITCH_1_PORT));
		topSpineSwitch1->Sendable::SetName("Spine", "top switch 1");
	bottomSpineSwitch2.reset(new DigitalInput(BOTTOM_SPINE_SWITCH_2_PORT));
		bottomSpineSwitch2->Sendable::SetName("Spine", "bottom switch 2");
	topSpineSwitch2.reset(new DigitalInput(TOP_SPINE_SWITCH_2_PORT));
		topSpineSwitch2->Sendable::SetName("Spine", "top switch 2");
	bottomShoulderSwitch.reset(new DigitalInput(BOTTOM_SHOULDER_SWITCH_PORT));
		bottomShoulderSwitch->Sendable::SetName("Shoulder", "bottom switch");
	topShoulderSwitch.reset(new DigitalInput(TOP_SHOULDER_SWITCH_PORT));
		topShoulderSwitch->Sendable::SetName("Shoulder", "top switch");
	frontClawSwitch.reset(new DigitalInput(FRONT_CLAW_SWITCH_PORT));
		frontClawSwitch->Sendable::SetName("Claw", "front switch");
	rearClawSwitch.reset(new DigitalInput(REAR_CLAW_SWITCH_PORT));
		rearClawSwitch->Sendable::SetName("Claw", "rear switch");

	armMotor1.reset(new VictorSP(ARM_MOTOR_1_PORT));
		lw->AddActuator("Arm", "motor 1", std::static_pointer_cast<frc::VictorSP>(armMotor1));
	armMotor2.reset(new VictorSP(ARM_MOTOR_2_PORT));
		lw->AddActuator("Arm", "motor 2", std::static_pointer_cast<frc::VictorSP>(armMotor2));
	clawMotor.reset(new VictorSP(CLAW_MOTOR_PORT));
		lw->AddActuator("Claw", "motor", std::static_pointer_cast<frc::VictorSP>(clawMotor));
	spineMotor1.reset(new VictorSP(SPINE_MOTOR_1_PORT));
		lw->AddActuator("Spine", "motor 1", std::static_pointer_cast<frc::VictorSP>(spineMotor1));
	spineMotor2.reset(new VictorSP(SPINE_MOTOR_2_PORT));
		lw->AddActuator("Spine", "motor 2", std::static_pointer_cast<frc::VictorSP>(spineMotor2));

	// Drivetrain subsystem


	leftDriveEncoder.reset(new Encoder(LEFT_DRIVE_ENCODER_A_PORT, LEFT_DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
		leftDriveEncoder->Sendable::SetName("Drivetrain", "left encoder");
		leftDriveEncoder->SetMaxPeriod(0.1);
		leftDriveEncoder->SetMinRate(1);
		leftDriveEncoder->SetSamplesToAverage(5);
		leftDriveEncoder->SetReverseDirection(true);
		leftDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	rightDriveEncoder.reset(new Encoder(RIGHT_DRIVE_ENCODER_A_PORT, RIGHT_DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
		rightDriveEncoder->Sendable::SetName("Drivetrain", "right encoder");
		rightDriveEncoder->SetMaxPeriod(0.1);
		rightDriveEncoder->SetMinRate(1);
		rightDriveEncoder->SetSamplesToAverage(5);
		rightDriveEncoder->SetReverseDirection(true);
		rightDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	backLeftDrive.reset(new VictorSP(BACK_LEFT_DRIVE_PORT));
		lw->AddActuator("Drivetrain", "back left drive", std::static_pointer_cast<frc::VictorSP>(backLeftDrive));
	backRightDrive.reset(new VictorSP(BACK_RIGHT_DRIVE_PORT));
		lw->AddActuator("Drivetrain", "back right drive", std::static_pointer_cast<frc::VictorSP>(backRightDrive));
	frontLeftDrive.reset(new VictorSP(FRONT_LEFT_DRIVE_PORT));
		lw->AddActuator("Drivetrain", "front left drive", std::static_pointer_cast<frc::VictorSP>(frontLeftDrive));
	frontRightDrive.reset(new VictorSP(FRONT_RIGHT_DRIVE_PORT));
		lw->AddActuator("Drivetrain", "front right drive", std::static_pointer_cast<frc::VictorSP>(frontRightDrive));

	backLeftDrive->SetInverted(true);
	backRightDrive->SetInverted(true);
	frontLeftDrive->SetInverted(true);
	frontRightDrive->SetInverted(true);

	leftDrive = std::make_shared <SpeedControllerGroup>(*backLeftDrive, *frontLeftDrive);
	rightDrive = std::make_shared <SpeedControllerGroup>(*backRightDrive, *frontRightDrive);

	differentialDrive.reset(new DifferentialDrive(*leftDrive, *rightDrive));
		differentialDrive->SetSafetyEnabled(false);
		differentialDrive->SetExpiration(0.1);
		differentialDrive->SetMaxOutput(1.0);

	gyro.reset(new AnalogGyro(GYRO_PORT));
		gyro->Sendable::SetName("Drivetrain", "gyro");
		gyro->SetSensitivity(0.00666);
		gyro->Calibrate();
}

void RobotMap::reset() {
	Robot::arm->Reset();
	Robot::drivetrain->Reset();
	}

#endif /* SRC_ROBOTMAP_CPP_ */
