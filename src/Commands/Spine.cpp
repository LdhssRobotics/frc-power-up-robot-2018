#include <Commands/Spine.h>

SpineUp::SpineUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::spine.get());
}

// Called just before this Command runs the first time
void SpineUp::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick2->GetPOV(0));
	SmartDashboard::PutNumber("Spine 1", Robot::arm->GetSpinePos1());
	SmartDashboard::PutNumber("Spine 2", Robot::arm->GetSpinePos2());
	Robot::spine->DifferentialSpine(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void SpineUp::Execute() {
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick2->GetPOV(0));
	SmartDashboard::PutNumber("Spine Encoder 1", Robot::arm->GetSpinePos1());
	SmartDashboard::PutNumber("Spine Encoder 2", Robot::arm->GetSpinePos2());
	if (Robot::oi->driveStick2->GetPOV(0) == 0){
		double speed = (0.2);
		SmartDashboard::PutString("Spine", "Moving");
		Robot::spine->DifferentialSpine(speed, speed * Robot::spine->AdjustSpine());
	}
	else if(Robot::oi->driveStick2->GetPOV(0) == -1){
		double speed = (0);
		SmartDashboard::PutString("Arm", "Moving");
		Robot::spine->DifferentialSpine(speed, speed);
	}
	else if(Robot::oi->driveStick2->GetPOV(0) == 180){
		double speed = (-0.2);
		SmartDashboard::PutString("Arm", "Moving");
		Robot::spine->DifferentialSpine(speed, speed * Robot::spine->AdjustSpine());
	}

}

// Make this return true when this Command no longer needs to run execute()
bool SpineUp::IsFinished() {
	return false;

}

// Called once after isFinished returns true
void SpineUp::End() {
	Robot::spine->DifferentialSpine(0,0);
	SmartDashboard::PutString("Spine", "Finished");


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpineUp::Interrupted() {
	End();

}
