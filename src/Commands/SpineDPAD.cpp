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

	if (Robot::oi->driveStick->GetPOV(0) == 0 && Robot::spine->CanMoveSpine()){
		//Move Spine upwards when DPAD up is pressed
		double speed = (0.60);
		SmartDashboard::PutString("Spine", "Moving Up");
		Robot::spine->SetMotorSpeed(speed, speed + Robot::spine->AdjustSpine(true));
		SmartDashboard::PutNumber("Adjust Spine Increment", Robot::spine->AdjustSpine(true));
	} else if(Robot::oi->driveStick->GetPOV(0) == -1){
		//Stops spine when no DPAD button is pressed
		SmartDashboard::PutString("Spine", "Stopped");
		Robot::spine->SetMotor(0,0);
	} else if(Robot::oi->driveStick->GetPOV(0) == 180 && Robot::spine->CanMoveSpine()){
		//Move Spine downwards when DPAD down is pressed
		double speed = (-0.60);
		SmartDashboard::PutString("Spine", "Moving Down");
		Robot::spine->SetMotorSpeed(speed, speed + Robot::spine->AdjustSpine(false));
		SmartDashboard::PutNumber("Adjust Spine Increment", Robot::spine->AdjustSpine(false));
	} else if (Robot::oi->driveStick->GetPOV(90)){
		// Turns the robot 90 degrees to the right when DPAD right is pressed
		bool finished = false;
		float currentReading;
		float target = 305;
		while (!finished){
			currentReading = Robot::drivetrain->GetRightCount();
			if (currentReading != target){
				Robot::drivetrain->TankDrive(1,-1);
			} else { finished = true; }
		}

	} else if (Robot::oi->driveStick->GetPOV(270)){
		// Turns the robot 90 degrees to the left when DPAD left is pressed
		bool finished = false;
		float currentReading;
		float target = 305;
		while (!finished){
			currentReading = Robot::drivetrain->GetLeftCount();
			if (currentReading != target){
				Robot::drivetrain->TankDrive(-1,1);
			} else { finished = true; }
		}
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
