#include <Commands/InvertCamera.h>

InvertCamera::InvertCamera(cv::Mat& source0){
	cv::Mat meh  = source0;

}
cv::Mat InvertCamera::GetMeh(){
	return meh;
}
void InvertCamera::Initialize(){
	cv::Mat cvFlipSrc = GetMeh();
	grip::FlipCode cvFlipFlipcode = grip::FlipCode::BOTH_AXES;
cvFlip(cvFlipSrc, cvFlipFlipcode, this->cvFlipOutput);
}
cv::Mat* InvertCamera::GetCvFlipOutput(){
		return &(this->cvFlipOutput);
}
void InvertCamera::Execute(){

}

bool InvertCamera::IsFinished(){
	return false;
}

void InvertCamera::End(){

}

void InvertCamera::Interrupted(){
	End();
}

void InvertCamera::cvFlip(cv::Mat &src, grip::FlipCode &flipcode, cv::Mat &dst) {
		cv::flip(src, dst, flipcode);
	}
