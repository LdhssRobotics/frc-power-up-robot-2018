/*
 * LeftAutoMode.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: Noodles
 */


#include "LeftAutoMode.h"
#include "../DriveTime.h"

LeftAutoMode::LeftAutoMode() {

	AddSequential(new DriveTime(3.3)); //20

}

