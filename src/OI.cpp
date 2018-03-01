/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>
#include "Commands/Turn90Degrees.h"
#include "Commands/Turn180Degrees.h"
#include "Commands/CrabWalkGroup.h"
#include "Commands/CrabWalk.h"
#include "Commands/CrabWalk2.h"
#include "Commands/OpenClaw.h"
#include "Commands/CloseClaw.h"
#include "Commands/SwitchCamera.h"

OI::Controller_t OI::m_controllerType;
int OI::LEFT_X_AXIS;
int OI::LEFT_Y_AXIS;
int OI::LEFT_TRIGGER_AXIS;
int OI::RIGHT_TRIGGER_AXIS;
int OI::RIGHT_X_AXIS;
int OI::RIGHT_Y_AXIS;

OI::OI() {
	//defining a controller to change between ps4 and xbox360 controller
	driveStick.reset(new Joystick(0));
	m_controllerType = XBOX;

	if (m_controllerType == PLAYSTATION) {
		// Drive Stick Buttons
			xButtonD = new JoystickButton(driveStick.get(), 1);
			aButtonD = new JoystickButton(driveStick.get(), 2);
			bButtonD = new JoystickButton(driveStick.get(), 3);
			yButtonD = new JoystickButton(driveStick.get(), 4);
			leftBumperButtonD = new JoystickButton(driveStick.get(), 5);
			rightBumperButtonD = new JoystickButton(driveStick.get(), 6);
			leftTriggerButtonD = new JoystickButton(driveStick.get(), 7);
			rightTriggerButtonD = new JoystickButton(driveStick.get(), 8);
			selectButtonD = new JoystickButton(driveStick.get(), 9);
			startButtonD = new JoystickButton(driveStick.get(), 10);
			leftStickButtonD = new JoystickButton(driveStick.get(), 11);
			rightStickButtonD = new JoystickButton(driveStick.get(), 12);
			homeButtonD = new JoystickButton(driveStick.get(), 13);
			touchpadButtonD = new JoystickButton(driveStick.get(), 14);

			OI::LEFT_X_AXIS = 0;
			OI::LEFT_Y_AXIS = 1;
			OI::RIGHT_X_AXIS = 2;
			OI::LEFT_TRIGGER_AXIS = 3;
			OI::RIGHT_TRIGGER_AXIS = 4;
			OI::RIGHT_Y_AXIS = 5;
	} else if (m_controllerType == XBOX) {
		// Drive Stick Buttons
			aButtonD = new JoystickButton(driveStick.get(), 1);
			bButtonD = new JoystickButton(driveStick.get(), 2);
			xButtonD = new JoystickButton(driveStick.get(), 3);
			yButtonD = new JoystickButton(driveStick.get(), 4);
			leftBumperButtonD = new JoystickButton(driveStick.get(), 5);
			rightBumperButtonD = new JoystickButton(driveStick.get(), 6);
			selectButtonD = new JoystickButton(driveStick.get(), 7);
			startButtonD = new JoystickButton(driveStick.get(), 8);
			leftStickButtonD = new JoystickButton(driveStick.get(), 9);
			rightStickButtonD = new JoystickButton(driveStick.get(), 10);

			OI::LEFT_X_AXIS = 0;
			OI::LEFT_Y_AXIS = 1;
			OI::LEFT_TRIGGER_AXIS = 2;
			OI::RIGHT_TRIGGER_AXIS = 3;
			OI::RIGHT_X_AXIS = 4;
			OI::RIGHT_Y_AXIS = 5;
	}

	driveStick.reset(new Joystick(0));
	// Assigning Commands to Buttons

	// Drive Stick Controls

	xButtonD->ToggleWhenPressed(new Turn90Degrees(true));
	yButtonD->WhenPressed(new Turn180Degrees(true));
	bButtonD->ToggleWhenPressed(new Turn90Degrees(false));
	aButtonD->WhenPressed(new Turn180Degrees(false));
	leftStickButtonD->WhenPressed(new CrabWalkGroup(true));
	rightStickButtonD->WhenPressed(new CrabWalkGroup(false));
	startButtonD->ToggleWhenPressed(new SwitchCamera());

	//Claw Controls

	leftBumperButtonD->WhileHeld(new OpenClaw());
	leftBumperButtonD->WhenReleased(new CloseClaw());

}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

