#include <Commands/Spine.h>

SpineUp::SpineUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void SpineUp::Initialize() {
	//double checkencoderspine = Robot::arm->CheckEncoders();
	SmartDashboard::PutString("Spine", "Start");
	Robot::arm->DifferentialSpine(0, 0);

}

// Called repeatedly when this Command is scheduled to run
void SpineUp::Execute() {
	SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
		if (Robot::oi->driveStick->GetPOV(0) == 0){
			double speed = (0.2);
			SmartDashboard::PutString("Arm", "Moving");
			Robot::arm->DifferentialSpine(speed, speed * Robot::arm->AdjustSpine());
			SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
		}
		else if(Robot::oi->driveStick->GetPOV(0) == -1){
			double speed = (0);
			SmartDashboard::PutString("Arm", "Moving");
			Robot::arm->DifferentialSpine(speed, speed);
			SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
		}
		else if(Robot::oi->driveStick->GetPOV(0) == 180){
			double speed = (-0.4);
			SmartDashboard::PutString("Arm", "Moving");
			Robot::arm->DifferentialSpine(speed, speed * Robot::arm->AdjustSpine());
			SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
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
