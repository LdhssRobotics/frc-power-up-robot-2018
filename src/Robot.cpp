#include "Robot.h"

std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<SpineSubSystem> Robot::spine;

cs::UsbCamera invertableCubeCamera;
cs::UsbCamera backCamera;
cs::VideoSink server;
cs::CvSink invertableCubeCvSink;
cs::CvSink backCvSink;

void Robot::VisionThread(){
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

    oi.reset(new OI());

    // Select autonomous mode
    chooser.AddDefault("BasicAuto", DEFAULT);
    chooser.AddObject("Left", LEFT);
    chooser.AddObject("Centre", CENTRE); // Default autonomous mode
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
    if(gameData[GE_SWITCH_1] == 'L'){
        if(gameData[GE_SCALE] == 'R'){
            fieldPosition = SWITCH;
            autonomousCommand = new Auto90Switch(false);
        } else if(gameData[GE_SCALE] == 'L'){
            if(matchData == "kElimination"){
                fieldPosition = SCALE;
                autonomousCommand = new AutoScale(false);
            } else if(matchData == "kQualification"){
                fieldPosition = SWITCH;
                autonomousCommand = new Auto90Switch(false);
            }
        }
    }
}

void Robot::handleRight(void) {
    if(gameData[GE_SWITCH_1] == 'R'){
        if(gameData[GE_SCALE] == 'L'){
            fieldPosition = SWITCH;
            autonomousCommand = new Auto90Switch(true);
        } else if(gameData[GE_SCALE] == 'R'){
            if(matchData == "kElimination"){
                fieldPosition = SCALE;
                autonomousCommand = new AutoScale(true);
            } else if(matchData == "kQualification"){
                fieldPosition = SWITCH;
                autonomousCommand = new Auto90Switch(true);
            }
        }
    }
    //autonomousCommand = ???;
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
        if (autonomousCommand != nullptr) {
            autonomousCommand->Start();
        }
    }




    /*if(autonomousPos == LEFT){
        if(gameData.length() > 0){
            if(gameData[0] == 'L' && gameData[1] == 'R'){
                autonomousPos->Start();
            }else if(gameData[0] == 'R' && gameData[1] == 'L'){
                autonomousPos = new AutoScale(false);
                autonomousPos->Start();
            }else if(gameData[0] == 'L' && gameData[1] == 'L'){
                if(matchData == "kElimination"){
                    autonomousPos = new AutoScale(false);
                    autonomousPos->Start();
                }else if(matchData == "kQualification"){
                    autonomousPos->Start();
                }
            }else{
                autonomousPos = new AutoStraight();
                autonomousPos->Start();
            }
        }
    }else if(autonomousPos == new Auto90Switch(true)){
        if(gameData.length() > 0){
            if(gameData[0] == 'R' && gameData[1] == 'L'){
                autonomousPos->Start();
            }else if(gameData[0] == 'L' && gameData[1] == 'R'){
                autonomousPos = new AutoScale(true);
                autonomousPos->Start();
            }else if(gameData[0] == 'R' && gameData[1] == 'R'){
                if(matchData == "kElimination"){
                    autonomousPos = new AutoScale(true);
                    autonomousCommand->Start();
                }else if(matchData == "kQualification"){
                    autonomousCommand->Start();
                }
            }else{
                autonomousCommand = new AutoStraight();
                autonomousCommand->Start();
            }
        }
    }else if(autonomousCommand == new AutoStraightSwitch()){
        if(gameData.length() > 0){
            if(gameData[0] == 'R'){
                autonomousCommand->Start();
            }else{
                autonomousCommand = new AutoStraight();
                autonomousCommand->Start();
            }
        }
    }else{
        autonomousCommand->Start();
    }*/
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
    if(Robot::drivetrain->IsSpine){
        server.SetSource(invertableCubeCamera);
    } else {
        server.SetSource(backCamera);
    }

}

START_ROBOT_CLASS(Robot);


