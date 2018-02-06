/*
 * InvertCam.h
 *
 *  Created on: Jan 27, 2018
 *      Author: shrish
 */

#pragma once
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

#include "Commands/Subsystem.h"
#include "WPILib.h"

namespace grip {

/**
 * Code used for CV_flip.
 * Per OpenCV spec 0 -> flip on X axis.
 * >0 -> flip on Y axis.
 * <0 -> flip on both axes.
 */
enum FlipCode {
	X_AXIS = 0,
	Y_AXIS = 1,
	BOTH_AXES = -1,
};
/**
* InvertCam class.
*
* An OpenCV pipeline generated by GRIP.
*/
class InvertCam {
	private:
		cv::Mat cvFlipOutput;
		void cvFlip(cv::Mat &, FlipCode &, cv::Mat &);

		std::shared_ptr<Encoder> armEncoder;

	public:
		InvertCam();
		void Process(cv::Mat& source0);
		double GetDegrees();
		cv::Mat* GetCvFlipOutput();
};


} // end namespace grip
