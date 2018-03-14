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

#include "Commands/ClimbGroup.h"

#include "Commands/OpenClawGroup.h"
#include "Commands/CloseClawGroup.h"

#include "Commands/SwitchCamera.h"

//OI::ControllerType_t OI::m_controllerType;

OI::OI() {



	driveStick.reset(new Joystick(0));

//	m_controllerType = XBOX;
/*
	if(m_controllerType == XBOX){

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

	LEFT_X_AXIS = 0;
	LEFT_Y_AXIS = 1;
	LEFT_TRIGGER_AXIS = 2;
	RIGHT_TRIGGER_AXIS = 3;
	RIGHT_X_AXIS = 4;
	RIGHT_Y_AXIS = 5;

	} else if(m_controllerType == PLAYSTATION){
*/
	// Drive Stick Buttons
	aButtonD = new JoystickButton(driveStick.get(), 2);
	bButtonD = new JoystickButton(driveStick.get(), 3);
	xButtonD = new JoystickButton(driveStick.get(), 1);
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
/*
	LEFT_X_AXIS = 0;
	LEFT_Y_AXIS = 1;
	LEFT_TRIGGER_AXIS = 3;
	RIGHT_TRIGGER_AXIS = 4;
	RIGHT_X_AXIS = 2;
	RIGHT_Y_AXIS = 5;
*/
//	}
	// Assigning Commands to Buttons

	//Drive Stick Controls
	bButtonD->ToggleWhenPressed(new Turn90Degrees(true));
	yButtonD->WhenPressed(new Turn180Degrees(true));
	xButtonD->ToggleWhenPressed(new Turn90Degrees(false));
	aButtonD->WhenPressed(new Turn180Degrees(false));
	leftStickButtonD->WhenPressed(new CrabWalkGroup(true));
	rightStickButtonD->WhenPressed(new CrabWalkGroup(false));

	//Camera Switch Controls
	selectButtonD->ToggleWhenPressed(new SwitchCamera());

	//Climb Controls
	startButtonD->WhenPressed(new ClimbGroup());

	//Claw Controls
	leftBumperButtonD->WhileHeld(new OpenClawGroup());
	leftBumperButtonD->WhenReleased(new CloseClawGroup());


}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}
