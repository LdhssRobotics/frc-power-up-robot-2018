/*
 * ArmSwing.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Sayfullah
 */

#include <Commands/ArmSwingDPAD.h>


ArmSwingDPAD::ArmSwingDPAD() {
	Requires(Robot::arm.get());
	currentSpeed = 0;
}

void ArmSwingDPAD::Initialize(){
	SmartDashboard::PutString("Arm", "Start");
	Robot::arm->SetArmSpeed(0);
	currentSpeed = 0.1;
}

void ArmSwingDPAD::Execute(){
	SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
	if (Robot::oi->driveStick->GetPOV(0) == 90){//ArmSwing up
		float maxspeed = 0.6;
		if (currentSpeed > maxspeed ){
			currentSpeed = maxspeed;
		}
		Robot::arm->SetArmSpeed(currentSpeed * 1.05);
		SmartDashboard::PutString("Arm", "Moving");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == -1){
		float speed = 0.0;
		Robot::arm->SetArmSpeed(speed);
		SmartDashboard::PutString("Arm", "Stopped");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == 270){//ArmSwing Down
		float maxspeed = -0.3;
		if (currentSpeed > maxspeed ){
			currentSpeed = maxspeed;
		}
		Robot::arm->SetArmSpeed(abs (currentSpeed * 1.05));
		SmartDashboard::PutString("Arm", "Moving");
	}
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
