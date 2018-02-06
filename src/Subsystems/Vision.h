/*
 * Vision.h
 *
 *  Created on: Feb 1, 2018
 *      Author: raven8
 */

#ifndef SRC_SUBSYSTEMS_VISION_H_
#define SRC_SUBSYSTEMS_VISION_H_

#include <Commands/Subsystem.h>
#include <WPILib.h>

class Vision : public Subsystem {
private:
	bool isCamInverted;
	bool isCam0Enabled;

public:
	Vision();
	void InitDefaultCommand();
	void Reset();
};


#endif /* SRC_SUBSYSTEMS_VISION_H_ */
