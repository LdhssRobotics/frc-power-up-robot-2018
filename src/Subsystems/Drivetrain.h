#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"


class Drivetrain : public Subsystem {
private:
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Encoder> driveEncoder;
	std::shared_ptr<DifferentialDrive> differentialDrive;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:

	std::shared_ptr<SpeedControllerGroup> leftDrive;
	std::shared_ptr<SpeedControllerGroup> rightDrive;
	std::shared_ptr<SpeedController> frontLeftDrive;
	std::shared_ptr<SpeedController> backLeftDrive;
	std::shared_ptr<SpeedController> frontRightDrive;
	std::shared_ptr<SpeedController> backRightDrive;


	Drivetrain();
	void InitDefaultCommand();
	void Reset();
	void ArcadeDrive(double, double);
	void Stop();
	float GetDistance();
};

#endif  // Drivetrain_H
