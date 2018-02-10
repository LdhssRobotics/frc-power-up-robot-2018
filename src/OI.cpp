/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

OI::OI() {

	driveStick.reset(new Joystick(0));

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
	rightStickButtonD = new JoystickButton(driveStick.get(), 1);

	driveStick2.reset(new Joystick(1));

	// Drive Stick Buttons
	aButtonA = new JoystickButton(driveStick2.get(), 1);
	bButtonA = new JoystickButton(driveStick2.get(), 2);
	xButtonA = new JoystickButton(driveStick2.get(), 3);
	yButtonA = new JoystickButton(driveStick2.get(), 4);
	leftBumperButtonA = new JoystickButton(driveStick2.get(), 5);
	rightBumperButtonA = new JoystickButton(driveStick2.get(), 6);
	selectButtonA = new JoystickButton(driveStick2.get(), 7);
	startButtonA = new JoystickButton(driveStick2.get(), 8);
	leftStickButtonA = new JoystickButton(driveStick2.get(), 9);
	rightStickButtonA = new JoystickButton(driveStick2.get(), 1);

	// Assigning Commands to Buttons

	// Drive Stick Controls

	//Arm Controller Controls

}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<Joystick> OI::getDriveStick2(){
	return driveStick2;
}
