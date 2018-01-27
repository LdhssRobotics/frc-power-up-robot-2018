/*
 * Robot.h
 *
 *  Created on: Jan 13, 2018
 *      Author: Madeline
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"
#include "LiveWindow/LiveWindow.h"
#include "RobotMap.h"

// Vision includes
#include <thread>
#include <CameraServer.h>

// Autonomous mode includes
#include <Commands/AutoModes/CentreAutoMode.h>
#include <Commands/AutoModes/LeftAutoMode.h>
#include <Commands/AutoModes/RightAutoMode.h>


#include "Subsystems/Drivetrain.h"
#include "Subsystems/Arm.h"

#include "OI.h"


class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<Arm> arm;
	static void VisionThread();
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

#endif /* SRC_ROBOT_H_ */




