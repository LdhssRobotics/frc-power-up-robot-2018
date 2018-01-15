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
	// Climber subsystem
	static std::shared_ptr<SpeedController> winchMotor;
	static std::shared_ptr<Servo> rachetServo;
	static std::shared_ptr<Servo> flapServo;

	// Drivetrain subsystem
	static std::shared_ptr<AnalogGyro> gyro;
	static std::shared_ptr<Encoder> driveEncoder;


	static std::shared_ptr<SpeedController> frontLeftDrive;
	static std::shared_ptr<SpeedController> backLeftDrive;
	static std::shared_ptr<SpeedController> frontRightDrive;
	static std::shared_ptr<SpeedController> backRightDrive;
	static std::shared_ptr<DifferentialDrive> differentialDrive;

	// Gear subsystem
	static std::shared_ptr<Encoder> gearEncoder;
	static std::shared_ptr<SpeedController> gearMotor;
	static std::shared_ptr<DigitalInput> gearLimitSwitch;

	// Ultrasonic subsystem
	static std::shared_ptr<Ultrasonic> ultrasonic;

	static void init();
	static void reset();
};

#endif
