/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>

#include "Commands/Switch.h"
#include "Commands/Exchange.h"
#include "Commands/Inboard.h"
#include "Commands/Scale.h"

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
	bButtonD->ToggleWhenPressed(new Inboard());
	xButtonD->ToggleWhenPressed(new Switch());
	aButtonD->ToggleWhenPressed(new Exchange());
	yButtonD->ToggleWhenPressed(new Scale());

	//Camera Switch Controls
	selectButtonD->ToggleWhenPressed(new SwitchCamera());

	//Climb Controls
	touchpadButtonD->ToggleWhenPressed(new ClimbGroup()); //Switch to startButtonD if using XBOX

	//Claw Controls
	rightBumperButtonD->WhileHeld(new OpenClawGroup());
	rightBumperButtonD->WhenReleased(new CloseClawGroup());


}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}
