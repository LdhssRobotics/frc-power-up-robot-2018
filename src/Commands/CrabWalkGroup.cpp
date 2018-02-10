#include "CrabWalkGroup.h"
#include "CrabWalk.h"
#include "CrabWalk2.h"
#include "DriveDistance.h"
CrabWalkGroup::CrabWalkGroup(bool isLeft):
	isLeftWalk(isLeft)
{
	AddSequential(new CrabWalk(isLeftWalk));
	AddSequential(new CrabWalk2(isLeftWalk));
	AddSequential(new DriveDistance(2.45));
}
