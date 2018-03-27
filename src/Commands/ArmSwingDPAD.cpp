/*
 * ArmSwing.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Sayfullah
 */

#include <Commands/ArmSwingDPAD.h>


ArmSwingDPAD::ArmSwingDPAD() {
	Requires(Robot::arm.get());
	armTargetPOS = 0;
}

void ArmSwingDPAD::Initialize(){
	SmartDashboard::PutString("Arm", "Start");


	Robot::arm->SetArmSpeed(0);
	armTargetPOS = 0.0;
}

void ArmSwingDPAD::Execute(){
	SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());

	if (Robot::oi->driveStick->GetPOV(0) == 90){//ArmSwing up
		Robot::arm->SetArmSpeed(0.6);
		armTargetPOS = Robot::arm->GetArmPosition();
		//if (armTargetPOS < 0){
		//	armTargetPOS = 0;
		//}
		SmartDashboard::PutString("Arm", "Moving");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == -1){

		// ASA assuming that -1 means not pressed.
		// ASA following block of code needs change.
		// ASA Need  to have the "set position" being the position when we released the up or down.
		// ASA Read current compare to the "set position"
		// ASA adjust accordingly.
		// ASA Put 2degree of error.... 147*10 = 1470 for 180 degree  so a count of 16.
		float speed = 0.0;
		Robot::arm->SetArmSpeed(speed); //ASA remove
		if (armTargetPOS > (1.01 * Robot::arm->GetArmPosition())){ //ASA would use a >= Set Position +8
			Robot::arm->SetArmSpeed(0.3); //ASA may not be enough power.... 0.3 is my bet.
		}
		else { // ASA would use <= Set Position -8
			Robot::arm->SetArmSpeed(0);
		}
		SmartDashboard::PutString("Arm", "Stopped");
		// ASA up to here
	}
	else if(Robot::oi->driveStick->GetPOV(0) == 270){//ArmSwing Down
		Robot::arm->SetArmSpeed(-0.25);   //ASA not powerful enough to bring the arm back, try -0.25
		armTargetPOS = Robot::arm->GetArmPosition();
		//if (armTargetPOS < 0){
		//	armTargetPOS = 0;
		//}
		SmartDashboard::PutString("Arm", "Moving");
	}
	//Robot::arm->ResetArm();
}

bool ArmSwingDPAD::IsFinished(){
	return false;
}

void ArmSwingDPAD::End(){
	Robot::arm->SetArmSpeed(0);
	SmartDashboard::PutString("Arm","Finished");
}

void ArmSwingDPAD::Interrupted(){
	End();
}
