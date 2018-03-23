/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/AutoModes/AutoStraight.h>
#include "../DriveDistance.h"

AutoStraight::AutoStraight() {
    AddSequential(new DriveDistance(120));//Wall to Auto line in inches, drives straight
}


