/*
 * OpenClawGroup.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Owen
 */

#include <Commands/OpenClawGroup.h>
#include "StartClaw.h"
#include "OpenClaw.h"

OpenClawGroup::OpenClawGroup() {
	AddSequential(new StartClaw(true));
	AddSequential(new OpenClaw());

}

