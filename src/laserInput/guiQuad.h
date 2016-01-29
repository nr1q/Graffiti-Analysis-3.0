#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxOpenCv.h"

/////////////////////////
//	REQUIRES ofxPoint2f to
//	be defined as so:
/*
	typedef struct {
		float x;
		float y;
	} ofxPoint2f;
*/
/////////////////////////


class guiQuad{

	public:
		guiQuad();

		void setup(string _quadName);
		void readFromFile(string filePath);
		void loadSettings();

		void releaseAllPoints();
		//these should be in the range x(0-maxX) y(0-maxH)
		//with 	width  = maxW
		//		height = maxH
		void setQuadPoints( ofVec3f * inPts );

		bool selectPoint(float x, float y, float offsetX, float offsetY, float width, float height, float hitArea);
		bool updatePoint(float x, float y, float offsetX, float offsetY, float width, float height);

		//returns pts to width by height range
		ofVec3f * getScaledQuadPoints(float width, float height);
		//returns pts in 0-1 scale
		ofVec3f * getQuadPoints();
		void saveToFile(string filePath, string newQuadName);
		void saveToFile(string filePath);
		void draw(float x, float y, float width, float height, int red, int green, int blue, int thickness);
		void draw(float x, float y, float width, float height);


	protected:
		ofxXmlSettings	xml;
		ofVec3f srcZeroToOne[4];
		ofVec3f srcScaled[4];
		string quadName;
		int selected;
};



