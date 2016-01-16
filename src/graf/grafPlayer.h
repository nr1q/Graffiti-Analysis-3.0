#ifndef GRAFPLAYER_H
#define GRAFPLAYER_H

#include "ofMain.h"
#include "grafTypes.h"
#include "grafTagMulti.h"


class grafPlayer
{
    public:
        grafPlayer();
        virtual ~grafPlayer();

        void update (grafTagMulti* myTag);
        void reset();
        void calcPointForTime (float time, grafTagMulti* myTag);
        ofVec3f getVelocityForTime (grafTagMulti* myTag);

        void drawNowPoint (float scale=1);

        ofVec3f getCurrentPoint();
        float   getDuration (grafTagMulti* myTag);
        float   getCurrentZDepth (float z_const);
        float   getCurrentTime() {   return timeInRange; }
        float   getCurrentAngle() {  return nowAngle;    }
        float   getCurrentDist() {   return nowDist;     }
        float   getTimeCounter() {   return timeCounter; }
        int     getCurrentId() {     return nowIndex;    }
        int     getCurrentStroke() { return nowStroke;   }

        bool    bPaused;
        bool    bDonePlaying;
        bool    bReset;

    protected:
        float   timeCounter;     // time change for playback
        float   timeOfLastFrame; // records last time to calc time change
        float   timeInRange;     // current time in the drawing

        int     nowIndex;        // last point recorder or last point to be drawn
        int     nowStroke;
        float   nowDist;         // time interpolated distance
        float   nowAngle;        // time interpolated angle
        ofVec3f nowPointForTime; // time interpolated point

    private:
};

#endif // GRAFPLAYER_H
