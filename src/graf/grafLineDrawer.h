#ifndef GRAF_LINE_DRAWER_H
#define GRAF_LINE_DRAWER_H

#include "ofMain.h"
#include "grafTypes.h"

class grafLineDrawer
{
    public:
        grafLineDrawer();
        virtual ~grafLineDrawer();

        void setup (vector<timePt> pts, float minDist, float maxDist, float blendPct, int start=-1, int end=-1, bool bFadeIn = false, bool bFadeOut = false);
        void setupUniform (vector<timePt> pts, float lineDist, int start=-1, int end=-1);
        void average (float pct);

        void draw (int lastPt, float alpha = .75f, int startPt = -1, float lineWidth = 1);
        void drawOutline (int lastPt, float alpha = .75f, float lineW = 1,int startPt = -1);

        float blendPct;
        float strokeVal;

        vector<ofVec3f> pts_l;    // end points of line
        vector<ofVec3f> pts_r;

        vector<ofVec3f> pts_lo;   // origins so can deform after
        vector<ofVec3f> pts_ro;

        vector<ofVec2f> vecs;     // vectors of one end point to other

        vector<ofVec3f> pts_lout; // endpoints outline
        vector<ofVec3f> pts_rout;

        vector<float>   alphas;   // alpha value at each point


        ofVec3f end_pt_l;
        ofVec3f end_pt_r;

        float globalAlpha;
        float lineScale;
        bool  bUseFadeInOut;

        float outlineDist; // distance outline is drawn from line (should be very low )

    protected:
        //void calculateStroke();
        void calculatePoint (timePt pt, float time_num, float dist, float angle, vector<ofVec3f>&left, vector<ofVec3f>&right);
        float getAlphaForLinePosition (int pos, int total);

        void drawSegment (ofVec3f* ptR, ofVec3f* ptL);

    private:
};

#endif // GRAF_LINE_DRAWER_H
