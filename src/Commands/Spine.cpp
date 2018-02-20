#include <Commands/Spine.h>

Spine::Spine() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::spine.get());
}

// Called just before this Command runs the first time
void Spine::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	SmartDashboard::PutNumber("Spine 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine 2", Robot::spine->GetSpinePos2());
	Robot::spine->DifferentialSpine(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void Spine::Execute() {
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());
	if (Robot::oi->driveStick->GetPOV(0) == 0){
		double speed = (0.5);
		SmartDashboard::PutString("Spine", "Moving Up");
		Robot::spine->SetMotorSpeed(speed, speed * Robot::spine->AdjustSpine());
	}
	else if(Robot::oi->driveStick->GetPOV(0) == -1){
		double speed = (0);
		SmartDashboard::PutString("Spine", "Stopped");
		Robot::spine->DifferentialSpine(speed, speed);
	}
	else if(Robot::oi->driveStick->GetPOV(0) == 180){
		double speed = (-0.5);
		SmartDashboard::PutString("Spine", "Moving Down");
		Robot::spine->SetMotorSpeed(speed, speed * Robot::spine->AdjustSpine());
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Spine::IsFinished() {
	return false;

}

// Called once after isFinished returns true
void Spine::End() {
	Robot::spine->DifferentialSpine(0,0);
	SmartDashboard::PutString("Spine", "Finished");


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Spine::Interrupted() {
	End();

}
