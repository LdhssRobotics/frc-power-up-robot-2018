/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>

#include "Commands/OpenClawGroup.h"
#include "Commands/CloseClawGroup.h"
#include "Commands/LoosenClaw.h"
#include "Commands/Turn90Degrees.h"

#include "Commands/SwitchCamera.h"


//OI::ControllerType_t OI::m_controllerType;

OI::OI() {

	driveStick.reset(new Joystick(0));
	driveStick2.reset(new Joystick(1));

	// Drive Stick 1 Buttons
	aButtonD = new JoystickButton(driveStick.get(), 2); //'X' on PS
	bButtonD = new JoystickButton(driveStick.get(), 3); //'O' on PS
	xButtonD = new JoystickButton(driveStick.get(), 1); //'[]' on PS
	yButtonD = new JoystickButton(driveStick.get(), 4); //'/\' on PS
	leftBumperButtonD = new JoystickButton(driveStick.get(), 5); //'L1' on PS
	rightBumperButtonD = new JoystickButton(driveStick.get(), 6); //'R1' on PS
	leftTriggerButtonD = new JoystickButton(driveStick.get(), 7); //'L2' on PS
	rightTriggerButtonD = new JoystickButton(driveStick.get(), 8); //'R2' on PS
	selectButtonD = new JoystickButton(driveStick.get(), 9); //'Share/Back' on PS
	startButtonD = new JoystickButton(driveStick.get(), 10); //'Start' on PS
	leftStickButtonD = new JoystickButton(driveStick.get(), 11); //'L3' on PS
	rightStickButtonD = new JoystickButton(driveStick.get(), 12); //'R3' on PS
	homeButtonD = new JoystickButton(driveStick.get(), 13); //'PS' on PS
	touchpadButtonD = new JoystickButton(driveStick.get(), 14); //'Touchpad' on PS

	// Drive Stick 2 Buttons
	aButtonE = new JoystickButton(driveStick.get(), 1);
	bButtonE = new JoystickButton(driveStick.get(), 2);
	xButtonE = new JoystickButton(driveStick.get(), 3);
	yButtonE = new JoystickButton(driveStick.get(), 4);
	leftBumperButtonE = new JoystickButton(driveStick.get(), 5);
	rightBumperButtonE = new JoystickButton(driveStick.get(), 6);
	selectButtonE = new JoystickButton(driveStick.get(), 7);
	startButtonE = new JoystickButton(driveStick.get(), 8);
	leftStickButtonE = new JoystickButton(driveStick.get(), 9);
	rightStickButtonE = new JoystickButton(driveStick.get(), 10);

	// Assigning Commands to Buttons

	//Drive Stick Controls
	//Camera Switch Controls
	selectButtonD->ToggleWhenPressed(new SwitchCamera());

	//Claw Controls
	aButtonD->ToggleWhenPressed(new LoosenClaw());
	rightBumperButtonD->WhileHeld(new OpenClawGroup());
	rightBumperButtonD->WhenReleased(new CloseClawGroup());
}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<Joystick> OI::getDriveStick2() {
	return driveStick2;
}
