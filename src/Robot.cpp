#include "Robot.h"

std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<SpineSubSystem> Robot::spine;
std::shared_ptr<Claw> Robot::claw;

cs::UsbCamera invertableCubeCamera;
cs::UsbCamera backCamera;
cs::VideoSink server;
cs::CvSink invertableCubeCvSink;
cs::CvSink backCvSink;

void Robot::VisionThread() {
    invertableCubeCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
    invertableCubeCamera.SetResolution(160, 120);

    backCamera = CameraServer::GetInstance()->StartAutomaticCapture(1);
    backCamera.SetResolution(160, 120);

    server = CameraServer::GetInstance()->GetServer();

    // Holds both feeds open to prevent lag when switching camera feeds
    invertableCubeCvSink.SetSource(invertableCubeCamera);
    invertableCubeCvSink.SetEnabled(true);

    backCvSink.SetSource(backCamera);
    backCvSink.SetEnabled(true);
}

void Robot::RobotInit() {
    //running Vision Thread separately
    std::thread visionThread(VisionThread);
    visionThread.detach();

    RobotMap::init();

    arm.reset(new Arm());
    drivetrain.reset(new Drivetrain());
    spine.reset(new SpineSubSystem());
    claw.reset(new Claw());

    oi.reset(new OI());

    // Select autonomous mode
    chooser.AddDefault("Cross Line", DEFAULT);
    chooser.AddObject("Left", LEFT);
    chooser.AddObject("Centre", CENTRE);
    chooser.AddObject("Right", RIGHT);

    frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

void Robot::DisabledInit() {
    RobotMap::reset();
}

void Robot::DisabledPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

void Robot::handleLeft(void) {
	/* Never tested
	 * if driver selected the robot in position 1 (left side)
	 * this function is run receiving data from the FMS
	 */
    if(gameData[GE_SWITCH_1] == 'L'){
        if(gameData[GE_SCALE] == 'R'){
        //if FMS receives switch1 on left and scale on right, it does the left switch
            fieldPosition = SWITCH;
            autonomousCommand = new Auto90Switch(false);
        } else if(gameData[GE_SCALE] == 'L'){
        //if FMS receives switch on left and scale on left, depending on the the match type,
        //elimination it does the left scale, qualification it does the left switch
            if(matchData == "kElimination"){
                fieldPosition = SCALE;
                autonomousCommand = new AutoScale(false);
            } else if(matchData == "kQualification"){
                fieldPosition = SWITCH;
                autonomousCommand = new Auto90Switch(false);
            }
        }
    }
    //If the Switch is on the right, we exit and run nothing...
}

void Robot::handleRight(void) {
	/* Never tested
	 * if driver selected the robot in position 4 (right side)
	 * this function is run receiving data from the FMS
	 */
    if(gameData[GE_SWITCH_1] == 'R'){
        if(gameData[GE_SCALE] == 'L'){
        //if FMS receives switch1 on right and scale on left, it does the right switch
            fieldPosition = SWITCH;
            autonomousCommand = new Auto90Switch(true);
        } else if(gameData[GE_SCALE] == 'R'){
        //if FMS receives switch on right and scale on right, depending on the the match type,
        //elimination it does the right scale, qualification it does the right switch
            if(matchData == "kElimination"){
                fieldPosition = SCALE;
                autonomousCommand = new AutoScale(true);
            } else if(matchData == "kQualification"){
                fieldPosition = SWITCH;
                autonomousCommand = new Auto90Switch(true);
            }
        }
    }
    //If the Switch is on the left, we exit and run nothing...
}


void Robot::AutonomousInit() {
    fieldPosition = NONE;
    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    matchData = frc::DriverStation::MatchType();//Not sure about this one, determines match type
    autonomousPos = chooser.GetSelected();

    if(gameData.length() > 0) {
        switch (autonomousPos) {
            case LEFT:
            {
                handleLeft();
                break;
            }
            case CENTRE:
            {
                autonomousCommand = new AutoStraightSwitch();
                break;
            }
            case RIGHT:
            {
                handleRight();
                break;
            }
            default:
                autonomousCommand = new AutoStraight();
                break;
        }
        autonomousCommand = new LeftAutoMode(); //overriding cross auto line, only auto that we did at the comps
        if (autonomousCommand != nullptr) {
            autonomousCommand->Start();
        }
    }
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
    if(Robot::drivetrain->IsSpine){     //ASA are we running this continuously or once?
        server.SetSource(invertableCubeCamera);
    } else {
        server.SetSource(backCamera);
    }

}

START_ROBOT_CLASS(Robot);
