#include <Commands/SpineDPAD.h>

SpineDPAD::SpineDPAD() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::spine.get());
}

// Called just before this Command runs the first time
void SpineDPAD::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());
}

// Called repeatedly when this Command is scheduled to run
void SpineDPAD::Execute() {
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());
	Robot::spine->DisplaySpineCurrents();
	int limitFlag = Robot::spine->CheckReset();
	if (Robot::oi->driveStick->GetPOV(0) == 0 && Robot::spine->CanMoveSpine()){
		//Move Spine upwards when DPAD up is pressed
		Robot::spine->AdjustSimple(false, limitFlag);
	} else if(Robot::oi->driveStick->GetPOV(0) == -1){
		//Stops spine when no DPAD button is pressed
		SmartDashboard::PutString("Spine", "Stopped");
		Robot::spine->SetMotor(0,0);
	} else if(Robot::oi->driveStick->GetPOV(0) == 180 && Robot::spine->CanMoveSpine()){
		//Move Spine downwards when DPAD down is pressed
		Robot::spine->AdjustSimple(true, limitFlag);
	}


	//SmartDashboard::PutNumber("Difference", Robot::spine->AdjustSpine());
}

bool SpineDPAD::IsFinished() {
	return false;

}

// Called once after isFinished returns true
void SpineDPAD::End() {
	Robot::spine->SetMotor(0,0);
	SmartDashboard::PutString("Spine", "Finished");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpineDPAD::Interrupted() {
	End();

}
