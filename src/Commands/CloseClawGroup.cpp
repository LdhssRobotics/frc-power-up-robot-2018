/*
 * CloseClawGroup.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Sayfu
 */

#include <Commands/CloseClawGroup.h>
#include "StartClaw.h"
#include "CloseClaw.h"

CloseClawGroup::CloseClawGroup() {
	AddSequential(new StartClaw(false));
	AddSequential(new CloseClaw());
}

