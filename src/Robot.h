/*
 * Robot.h
 *
 *  Created on: Jan 13, 2018
 *      Author: Madeline
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPIlib.h"
#include "Commands/Command.h"
#include "LiveWindow/LiveWindow.h"
#include "RobotMap.h"

// Vision includes
#include <CameraServer.h>

// Autonomous mode includes
#include <Commands/AutoModes/CentreAutoMode.h>
#include <Commands/AutoModes/LeftAutoMode.h>
#include <Commands/AutoModes/RightAutoMode.h>

// Subsystem includes
#include "Subsystems/Arm.h"
#include "Subsystems/Drivetrain.h"

#include "OI.h"

class Robot : public frc::TimedRobot {
	public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;
	static std::shared_ptr<Arm> arm;
	static std::shared_ptr<Drivetrain> drivetrain;
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};
#endif
