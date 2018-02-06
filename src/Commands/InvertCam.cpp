/*
 * InvertCam.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: shrish
 */

#include "InvertCam.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "OI.h"

namespace grip {

InvertCam::InvertCam() {
	armEncoder = RobotMap::armEncoder;
}
/**
* Runs an iteration of the pipeline and updates outputs.
*/
void InvertCam::Process(cv::Mat& source0){
	//Step CV_flip0:
	//input

	if (InvertCam::GetDegrees() >= 70){

		cv::Mat cvFlipSrc = source0;
		FlipCode cvFlipFlipcode = FlipCode::BOTH_AXES;
		cvFlip(cvFlipSrc, cvFlipFlipcode, this->cvFlipOutput);
	}
}

double InvertCam::GetDegrees() {
	int count = armEncoder->Get();
	int degrees = (count * 8) % 360;
	return degrees;
}

/**
 * This method is a generated getter for the output of a CV_flip.
 * @return Mat output from CV_flip.
 */
cv::Mat* InvertCam::GetCvFlipOutput(){
	return &(this->cvFlipOutput);
}
	/**
	 * Flips an image along X, Y or both axes.
	 * @param src Image to flip.
	 * @param flipcode FlipCode of which direction to flip.
	 * @param dst flipped version of the Image.
	 */
	void InvertCam::cvFlip(cv::Mat &src, FlipCode &flipcode, cv::Mat &dst) {
		cv::flip(src, dst, flipcode);
	}



} // end grip namespace

