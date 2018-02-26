
#include "Commands/ReadGyro.h"

ReadGyro::ReadGyro() {
	Requires (Robot::drivetrain.get());
}

void ReadGyro::Initialize() {
	//Robot::drivetrain->gyro->Reset();
	//SmartDashboard::PutNumber("Gyro Angle", Robot::drivetrain->gyro->GetAngle());
}

void ReadGyro::Execute() {
	//SmartDashboard::PutNumber("Gyro Angle", Robot::drivetrain->gyro->GetAngle());
}

bool ReadGyro::IsFinished(){
	return false;
}

void ReadGyro::End(){

}

void ReadGyro::Interrupted(){

}
