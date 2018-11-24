/*
 * GYRO.h
 *
 *  Created on: Nov 12, 2018
 *      Author: raven10
 */

#ifndef GYRO_H_
#define GYRO_H_

#include "Robot.h"
#include "WPILib.h"

class GYRO:public Command {
private:
	double goalAngle;
public:
	GYRO();
	GYRO(float heading);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* GYRO_H_ */
