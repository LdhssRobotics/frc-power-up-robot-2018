#include "CrabWalkGroup.h"
#include "CrabWalk.h"
#include "CrabWalk2.h"
#include "DriveStraight.h"
CrabWalkGroup::CrabWalkGroup(bool isLeft):
	isLeftWalk(isLeft)
{
	AddSequential(new CrabWalk(isLeftWalk));
	AddSequential(new CrabWalk2(isLeftWalk));
	AddSequential(new DriveStraight(2.45));
}
