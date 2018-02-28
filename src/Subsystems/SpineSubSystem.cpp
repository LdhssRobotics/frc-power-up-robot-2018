/*
 * Spine.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Sayfullah
 */

#include <Commands/ArmSwingDPAD.h>
#include <Commands/SpineDPAD.h>
#include "Subsystems/SpineSubSystem.h"
#include "../RobotMap.h"
#include "Robot.h"

#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"
#include "ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h"
#include "ctre/phoenix/MotorControl/SensorCollection.h"
#include "ctre/phoenix/MotorControl/FeedbackDevice.h"

#include <algorithm>


SpineSubSystem::SpineSubSystem() : Subsystem("SpineSubSystem")  {
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;

	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);

}

void SpineSubSystem::InitDefaultCommand(){
	SetDefaultCommand(new SpineDPAD());
}

/*double SpineSubSystem::AdjustSpine() {
	double difference = (GetSpinePos2() - GetSpinePos1()) / GetSpinePos1();
	return (1-difference);
}*/

void SpineSubSystem::SetMotorSpeed(double lspeed, double rspeed){
	Robot::spine->spineMotor2->Set(rspeed);
	Robot::spine->spineMotor1->Set(lspeed);
}

int SpineSubSystem::GetSpinePos1(){
	int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->GetSelectedSensorPosition(0);
	return pos;
}

int SpineSubSystem::GetSpinePos2(){
	int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->GetSelectedSensorPosition(0);
	return pos;
}

void SpineSubSystem::ResetSpineEncoder1(){
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->SetSelectedSensorPosition(0,0,1);
}

void SpineSubSystem::ResetSpineEncoder2(){
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->SetSelectedSensorPosition(0,0,1);
}

bool SpineSubSystem::CanMoveSpine(){
	if (Robot::arm->GetArmPosition() < 10 || Robot::arm->GetArmPosition() > -5) {
		return true;
	}else if (Robot::arm->GetArmPosition() < 190 || Robot::arm->GetArmPosition() > 170){
		return true;
	}else{
		return false;
	}
}

void SpineSubSystem::Reset(){
	SetMotorSpeed(0,0);
	ResetSpineEncoder1();
	ResetSpineEncoder2();
}

void SpineSubSystem::CheckReset(){
	ctre::phoenix::motorcontrol::SensorCollection limit1 = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->GetSensorCollection();
	int limit = limit1.IsFwdLimitSwitchClosed();
	if (limit == 1){
		ResetSpineEncoder1();
	}
	ctre::phoenix::motorcontrol::SensorCollection limit2 = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->GetSensorCollection();
	int Limit = limit2.IsFwdLimitSwitchClosed();
	if (Limit == 1){
		ResetSpineEncoder2();
	}
	SmartDashboard::PutNumber("Limit 1", limit);
	SmartDashboard::PutNumber("Limit 2", Limit);
}
