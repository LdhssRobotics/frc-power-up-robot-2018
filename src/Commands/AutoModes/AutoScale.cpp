/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/AutoModes/AutoScale.h>
#include "../DriveDistance.h"
#include "../Switch.h"
#include "../Turn45Degrees.h"
#include "../CloseClaw.h"
#include "../OpenClaw.h"
#include "../Exchange.h"

AutoScale::AutoScale(bool isLeft) {
    AddSequential(new DriveDistance(262.5));//Cross auto line, move towards scale, to turn in place for scale
//    AddParallel(new Scale()); Command for scale position for arm and spine
    AddSequential(new Turn45Degrees(isLeft));
    AddSequential(new DriveDistance(10));//calculated estimation on a 45 degree angle
    AddSequential(new OpenClaw());
    Wait(4);
    AddSequential(new CloseClaw());
    AddSequential(new DriveDistance(-20));//calculated estimation to back away from scale
    AddSequential(new Exchange());

    // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
}


