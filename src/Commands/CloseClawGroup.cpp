/*
 * CloseClawGroup.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Owen
 */

#include <Commands/CloseClawGroup.h>
#include "StartClaw.h"
#include "CloseClaw.h"

CloseClawGroup::CloseClawGroup() {
	AddSequential(new StartClaw(false));
	AddSequential(new CloseClaw());
}

