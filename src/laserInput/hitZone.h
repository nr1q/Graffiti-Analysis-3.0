#pragma once

#include "ofMain.h"

class hitZone
{
    public:
        hitZone();

        void setActive(bool active);
        bool getActive();
        bool isHit(float x, float y);
        void setPosition(int which, float x, float y);
        void updatePoints();

        ofVec2f zoneDimensions[2];
        vector<ofVec2f> points;

        bool bActive;
        bool bState;
};
