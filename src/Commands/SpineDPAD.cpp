#include <Commands/SpineDPAD.h>

SpineDPAD::SpineDPAD() {
	Requires(Robot::spine.get());
}

// Called just before this Command runs the first time
void SpineDPAD::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	SmartDashboard::PutNumber("Spine 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine 2", Robot::spine->GetSpinePos2());
}

// Called repeatedly when this Command is scheduled to run
void SpineDPAD::Execute() {
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());
	if (Robot::oi->driveStick->GetPOV(0) == 0 && Robot::spine->CanMoveSpine()){
		double speed = (0.60);
		SmartDashboard::PutString("Spine", "Moving Up");
		Robot::spine->SetMotorSpeed(speed, speed);
	}
	else if(Robot::oi->driveStick->GetPOV(0) == -1){
		double speed = (0);
		SmartDashboard::PutString("Spine", "Stopped");
		Robot::spine->SetMotorSpeed(speed, speed);
	}
	else if(Robot::oi->driveStick->GetPOV(0) == 180 && Robot::spine->CanMoveSpine()){
		double speed = (-0.60);
		SmartDashboard::PutString("Spine", "Moving Down");
		Robot::spine->SetMotorSpeed(speed, speed);
	}
	Robot::spine->CheckReset();
	//SmartDashboard::PutNumber("Difference", Robot::spine->AdjustSpine());
}

// Make this return true when this Command no longer needs to run execute()
bool SpineDPAD::IsFinished() {
	return false;

}

// Called once after isFinished returns true
void SpineDPAD::End() {
	Robot::spine->SetMotorSpeed(0,0);
	SmartDashboard::PutString("Spine", "Finished");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpineDPAD::Interrupted() {
	End();

}
