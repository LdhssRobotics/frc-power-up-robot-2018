/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Arm> Robot::arm;
std::unique_ptr<OI> Robot::oi;

cs::UsbCamera gearCamera;
cs::UsbCamera climberCamera;
cs::VideoSink server;
cs::CvSink gearCvSink;
cs::CvSink climberCvSink;

void Robot::VisionThread() {
	climberCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	climberCamera.SetResolution(160, 120);

	gearCamera = CameraServer::GetInstance()->StartAutomaticCapture(1);
	gearCamera.SetResolution(160, 120);

	server = CameraServer::GetInstance()->GetServer();

	// cscore disconnects any cameras not in use so dummy
	// cvSinks are created to keep the camera connected
	gearCvSink.SetSource(gearCamera);
	gearCvSink.SetEnabled(true);

	climberCvSink.SetSource(climberCamera);
	climberCvSink.SetEnabled(true);

}

void Robot::RobotInit() {
	// We need to run our vision program in a separate Thread.
	// If not, our robot program will not run
	std::thread visionThread(VisionThread);
	visionThread.detach();

	RobotMap::init();

	drivetrain.reset(new Drivetrain());
	arm.reset(new Arm());

	oi.reset(new OI());
}

void Robot::DisabledInit() {
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	//Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	//autonomousCommand.reset(());


	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	//Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	//Scheduler::GetInstance()->Run();


	// Checks which side is at the front to determine which camera stream to display
	/*if(Robot::drivetrain->isGearFront) {
		server.SetSource(gearCamera);
	} else {
		server.SetSource(climberCamera);
	}*/
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
