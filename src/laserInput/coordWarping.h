#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

//we use openCV to calculate our transform matrix
#include "ofxCvConstants.h"
#include "ofxCvContourFinder.h"

class coordWarping{


	public:

		//---------------------------
		coordWarping();

		//first calculate the matrix
		//do this only when it changes - saves cpu!
		void calculateMatrix(ofVec3f src[4], ofVec3f dst[4]);

		//then when ever you need to warp the coords call this
		ofVec3f transform(float xIn, float yIn);

	protected:

		CvPoint2D32f cvsrc[4];
		CvPoint2D32f cvdst[4];
		CvMat *translate;

};
