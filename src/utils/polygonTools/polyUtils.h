/*
 *  polyUtils.h
 *  ensanche_2.0
 *
 *  Created by Chris on 1/17/10.
 *  Copyright 2010 csugrue. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"


bool pointInPolygon (float x, float y, vector<ofVec3f>pts);

static bool isInsideRect (float x, float y, ofRectangle rect);

bool intersectionTwoLines (ofVec3f pt1, ofVec3f pt2, ofVec3f pt3, ofVec3f pt4, ofVec3f * iPt);
bool intersectionTwoLines2 (ofVec3f pt1, ofVec3f pt2, ofVec3f pt3, ofVec3f pt4, ofVec3f * iPt);

bool findClosestIntersectionLineAndPoly (ofVec3f a, ofVec3f b, vector<ofVec3f> pts, ofVec3f & closestPoint, int & sideId);

bool minLineBetweenLineSegments (ofVec3f pt1, ofVec3f pt2, ofVec3f pt3, ofVec3f pt4, ofVec3f * pA, ofVec3f * pB);

ofVec3f distanceToSegment (ofVec3f p1, ofVec3f p2, ofVec3f p3);

bool isIntersectionPoly (ofVec3f pt1, ofVec3f pt2, vector<ofVec3f> pts);
bool isIntersectionPoly (ofVec3f pt1, ofVec3f pt2, vector<ofVec3f> pts, ofVec3f & iPt);
