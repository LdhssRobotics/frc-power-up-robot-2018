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
	std::shared_ptr<frc::Joystick> driveStick; //DriveTrain Controller (PS4 Port 0)
	std::shared_ptr<frc::Joystick> driveStick2; //Emergency Controller (XBOX Port 1)

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

	JoystickButton *aButtonE;
	JoystickButton *bButtonE;
	JoystickButton *xButtonE;
	JoystickButton *yButtonE;
	JoystickButton *leftBumperButtonE;
	JoystickButton *rightBumperButtonE;
	JoystickButton *selectButtonE;
	JoystickButton *startButtonE;
	JoystickButton *leftStickButtonE;
	JoystickButton *rightStickButtonE;

	// Axes
	static const int LEFT_X_AXIS = 0;
	static const int LEFT_Y_AXIS = 1;
	static const int LEFT_TRIGGER_AXIS = 3;
	static const int RIGHT_TRIGGER_AXIS = 4;
	static const int RIGHT_X_AXIS = 2;
	static const int RIGHT_Y_AXIS = 5;

	static const int LEFT_X_AXIS_E = 0;
	static const int LEFT_Y_AXIS_E = 1;
	static const int LEFT_TRIGGER_AXIS_E = 2;
	static const int RIGHT_TRIGGER_AXIS_E = 3;
	static const int RIGHT_X_AXIS_E = 4;
	static const int RIGHT_Y_AXIS_E = 5;

	typedef enum controllerType {
		PLAYSTATION,
		XBOX
	} ControllerType_t;

	static ControllerType_t m_controllerType;

	OI();
	std::shared_ptr<frc::Joystick> getDriveStick();
	std::shared_ptr<frc::Joystick> getDriveStick2();
};

#endif
