#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"


class Drivetrain : public Subsystem {
private:
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Encoder> driveEncoder;
	std::shared_ptr<DifferentialDrive> differentialDrive;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:

	std::shared_ptr<SpeedController> frontLeftDrive;
	std::shared_ptr<SpeedController> backLeftDrive;
	std::shared_ptr<SpeedController> frontRightDrive;
	std::shared_ptr<SpeedController> backRightDrive;

	Drivetrain();
	void InitDefaultCommand();
	void Reset();
};

#endif  // Drivetrain_H
