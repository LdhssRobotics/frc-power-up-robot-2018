/*
 * ClimbGroup.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Sayfullah
 */

#include <Commands/ClimbGroup.h>
#include "Spine.h"
#include "ArmSwing.h"
#include "Spine.h"


ClimbGroup::ClimbGroup() {
	AddSequential(new ArmSwing(0));
	AddSequential(new Spine(737280, false));
	AddSequential(new ArmSwing(180));
	AddSequential(new Spine(6826, false));
}


