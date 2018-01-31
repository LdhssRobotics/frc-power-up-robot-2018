#include "Robot.h"

std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

	arm.reset(new Arm());
	drivetrain.reset(new Drivetrain());

	oi.reset(new OI());

	// Select autonomous mode
	chooser.AddDefault("Centre Auto Mode", new CentreAutoMode()); // Default autonomous mode
	frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

void Robot::DisabledInit() {
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();

}

void Robot::AutonomousInit() {
	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit() {
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();


	// Checks which side is at the front to determine which camera stream to display
	/*if(Robot::drivetrain->isSpineFront) {
		server.SetSource(cam1);
	} else {
		server.SetSource(cam2);
	}*/
}

START_ROBOT_CLASS(Robot);
