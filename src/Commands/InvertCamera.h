/*
 * InvertCamera.h
 *
 *  Created on: Feb 7, 2018
 *      Author: turtl
 */

#ifndef SRC_COMMANDS_INVERTCAMERA_H_
#define SRC_COMMANDS_INVERTCAMERA_H_
//OpenCV Includes
#include "vision/VisionPipeline.h"

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

//General Includes
#include "../Robot.h"
#include "../RobotMap.h"
#include "WPILIb.h"

namespace grip {


enum FlipCode {
	X_AXIS = 0,
	Y_AXIS = 1,
	BOTH_AXES = -1,
};
}
class InvertCamera : public Command {
private:
	cv::Mat cvFlipOutput;
	cv::Mat meh;
	void cvFlip(cv::Mat &, grip::FlipCode &, cv::Mat &);
public:
	InvertCamera(cv::Mat& source0);
	cv::Mat* GetCvFlipOutput();
	cv::Mat GetMeh();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};




#endif /* SRC_COMMANDS_INVERTCAMERA_H_ */
