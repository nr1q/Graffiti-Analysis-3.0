#ifndef GRAF_DRAWER_H
#define GRAF_DRAWER_H

#include "ofMain.h"
#include "grafLineDrawer.h"
#include "grafTagMulti.h"

class grafDrawer
{
    public:
        grafDrawer();
        virtual ~grafDrawer();

        void setup (grafTagMulti * myTag, float maxLen);
        void draw (int lastStroke, int lastPoint);
        void drawTimeLine (ofVec3f center, float currentTime, float startTime, float z_const, ofTrueTypeFont * font, float scale);
        void drawBoundingBox (ofVec3f pmin, ofVec3f pmax, ofVec3f pcenter);

        void transition (float dt, float pct);
        void transitionDeform (float dt, float pct, float * amps, int numAmps);
        void transitionLineWidth (float dt, float avg);
        void transitionBounce (float dt, float avg);
        void transitionFlatten (float zDepth, float timeToDoIt);
        void resetTransitions();
        void flattenInstantly (float zDepth);

        void average (float pct);
        void setAlpha (float a);
        void setLineScale (float val);

        void alterZDepth (grafTagMulti* myTag);

        vector<grafLineDrawer*> lines;

        float alpha;
        float minLen;
        float lineWidth;
        float lineAlpha;
        float lineScale;

        bool bSetupDrawer;

        float pctTransLine;    // pct to make transition with deformed line
        float prelimTransTime; // time to play first transition (deform, amp etc.)
        float flatTime;

        //float prelimTransWait;

    protected:
    private:
};

#endif // GRAF_DRAWER_H
