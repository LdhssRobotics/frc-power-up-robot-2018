/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	std::shared_ptr<frc::Joystick> driveStick;

	// Drive Stick Buttons
	JoystickButton *aButtonD;
	JoystickButton *bButtonD;
	JoystickButton *xButtonD;
	JoystickButton *yButtonD;
	JoystickButton *leftBumperButtonD;
	JoystickButton *rightBumperButtonD;
	JoystickButton *selectButtonD;
	JoystickButton *startButtonD;
	JoystickButton *leftStickButtonD;
	JoystickButton *rightStickButtonD;
	JoystickButton *leftTriggerButtonD;
	JoystickButton *rightTriggerButtonD;
	JoystickButton *homeButtonD;
	JoystickButton *touchpadButtonD;

	// Axes
	static int LEFT_X_AXIS;
	static int LEFT_Y_AXIS;
	static int LEFT_TRIGGER_AXIS;
	static int RIGHT_TRIGGER_AXIS;
	static int RIGHT_X_AXIS;
	static int RIGHT_Y_AXIS;

	typedef enum controllerType {
			PLAYSTATION,
			XBOX,
		} Controller_t;

		static Controller_t m_controllerType;

	OI();

	std::shared_ptr<frc::Joystick> getDriveStick();
};

#endif
