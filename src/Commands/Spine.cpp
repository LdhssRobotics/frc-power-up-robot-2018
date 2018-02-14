#include <Commands/Spine.h>

SpineUp::SpineUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void SpineUp::Initialize() {
	SmartDashboard::PutString("Spine", "Start");
	Robot::arm->DifferentialSpine(0, 0);
	Robot::arm->DifferentialSpine(0,0);

}

// Called repeatedly when this Command is scheduled to run
void SpineUp::Execute() {
	int direction = Robot::oi->driveStick->GetPOV(0);

	if (/*Robot::arm->CanMoveSpine() &&*/ direction == 0){
		double speed = (0.4);
		SmartDashboard::PutString("Spine", "Moving");
		Robot::arm->DifferentialSpine(speed, speed);
		SmartDashboard::PutNumber("Spine Encoder 1", Robot::arm->GetSpinePos1());
		SmartDashboard::PutNumber("Spine Encoder 2", Robot::arm->GetSpinePos2());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SpineUp::IsFinished() {


}

// Called once after isFinished returns true
void SpineUp::End() {
	Robot::arm->DifferentialSpine(0,0);
	SmartDashboard::PutString("Spine", "Finished");


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpineUp::Interrupted() {
	End();

}
