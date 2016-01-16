/*
 *  gaManagerApp.h
 *  GA_Interactive
 *
 *  Created by Chris on 8/22/10.
 *  Copyright 2010 csugrue. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "polyEditable.h"
#include "grafTagMulti.h"
#include "grafIO.h"
#include "grafPlayer.h"
#include "grafCurveSmoother.h"
#include "grafDrawer.h"
#include "grafVParticleField.h"

#define GA_MODE_RECORDER  0
#define GA_MODE_PLAYER    1
#define GA_MODE_LASER     2
#define GA_MODE_HELP      3
#define GA_MODE_START     4

class GaManagerApp
{
    public:
        GaManagerApp();
        ~GaManagerApp();

        void setup();
        void update();
        void draw();

        void setMode(int);
        int getMode();
        int hitTest(int x, int y);

        int mode;

    protected:
        ofImage              titleImage;
        ofTrueTypeFont       fontS;
        ofTrueTypeFont       fontSS;

        vector<polyEditable> polyButtons;
        int                  xp, yp;

        grafTagMulti         tag;
        grafIO               gIO;            // gml loader/saver
        grafPlayer           myTagPlayer;    // manages playback of tag in time
        grafCurveSmoother    smoother;       // adds points to smooth tag
        grafDrawer           drawer;         // draws thick time stroked line
        grafVParticleField   particleDrawer; // draws and animates particles
        float                rotationY;      // y rotation for current tag
        int                  screenW, screenH;
        int                  tModes;
        bool                 bSetSplashTag;
};
