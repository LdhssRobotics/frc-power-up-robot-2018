#include "Robot.h"


std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;
cs::UsbCamera invertCamera;
cs::UsbCamera backCamera;
cs::VideoSink server;
cs::CvSink invertSink;
cs::CvSink backSink;

void Robot::VisionThread() {

}

void Robot::RobotInit() {
	//std::thread visionThread (VisionThread);
	//visionThread.detach();

	invertCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	invertCamera.SetResolution (160, 120);

	backCamera = CameraServer::GetInstance()->StartAutomaticCapture(1);
	backCamera.SetResolution (160, 120);

	server = CameraServer::GetInstance()->GetServer();

	invertSink.SetSource(invertCamera);
	invertSink.SetEnabled(true);

	backSink.SetSource(backCamera);
	backSink.SetEnabled(true);

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
	Scheduler::GetInstance()->Run();

	if(Robot::drivetrain->CubeFront) {
		server.SetSource(invertCamera);
		SmartDashboard::PutString("cam", "invert");
	}
	else
	{
		server.SetSource(backCamera);
		SmartDashboard::PutString("cam", "back");
	}
}


	// Checks which side is at the front to determine which camera stream to display
	/*if(Robot::drivetrain->isSpineFront) {
		server.SetSource(cam1);
	} else {
		server.SetSource(cam2);
	}*/






START_ROBOT_CLASS(Robot);
