/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	// Arm subsystem
	static std::shared_ptr<Encoder> spineEncoder1;
	static std::shared_ptr<Encoder> spineEncoder2;
	static std::shared_ptr<Encoder> armEncoder;
	static std::shared_ptr<DigitalInput> bottomSpineSwitch1;
	static std::shared_ptr<DigitalInput> topSpineSwitch1;
	static std::shared_ptr<DigitalInput> bottomSpineSwitch2;
	static std::shared_ptr<DigitalInput> topSpineSwitch2;
	static std::shared_ptr<DigitalInput> bottomShoulderSwitch;
	static std::shared_ptr<DigitalInput> topShoulderSwitch;
	static std::shared_ptr<DigitalInput> frontClawSwitch;
	static std::shared_ptr<DigitalInput> rearClawSwitch;

	static std::shared_ptr<SpeedController> clawMotor;
	static std::shared_ptr<SpeedController> spineMotor1;
	static std::shared_ptr<SpeedController> spineMotor2;
	static std::shared_ptr<SpeedController> armMotor1;
	static std::shared_ptr<SpeedController> armMotor2;

	// Drivetrain subsystem
	static std::shared_ptr<AnalogGyro> gyro;
	static std::shared_ptr<Encoder> leftDriveEncoder;
	static std::shared_ptr<Encoder> rightDriveEncoder;

	static std::shared_ptr<SpeedController> frontLeftDrive;
	static std::shared_ptr<SpeedController> backLeftDrive;
	static std::shared_ptr<SpeedController> frontRightDrive;
	static std::shared_ptr<SpeedController> backRightDrive;
	static std::shared_ptr<DifferentialDrive> differentialDrive;
	static std::shared_ptr<SpeedControllerGroup>leftDrive;
	static std::shared_ptr<SpeedControllerGroup> rightDrive;

	// Vision
	static std::shared_ptr<AnalogInput> leftLightReflector;
	static std::shared_ptr<AnalogInput> rightLightReflector;

	static void init();
	static void reset();
};

#endif
