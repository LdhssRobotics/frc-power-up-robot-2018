/*
 * OpenClawGroup.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Sayfu
 */

#include <Commands/OpenClawGroup.h>
#include "StartClaw.h"
#include "OpenClaw.h"

OpenClawGroup::OpenClawGroup() {
	AddSequential(new StartClaw(true));
	AddSequential(new OpenClaw());

}

