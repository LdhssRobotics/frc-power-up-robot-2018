/*
 * ClimbGroup.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#include <Commands/ClimbGroup.h>
#include "Spine.h"
#include "ArmSwing.h"


ClimbGroup::ClimbGroup() {
	AddSequential(new ArmSwing(0));


}


