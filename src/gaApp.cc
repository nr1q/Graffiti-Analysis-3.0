#include "gaApp.h"

extern ofAppGLFWWindow* window;

//--------------------------------------------------------------
void gaApp::setup()
{
    ofSetFrameRate(30);
    ofBackground(0, 0, 0);
    bMouseVisible = true;

    //ofSoundStreamSetup(0, 1, this, 44100, NUM_BANDS, 4);

    manager.setup();
}

//--------------------------------------------------------------
void gaApp::update()
{
    switch (manager.mode) {
        case GA_MODE_START:
            manager.update();
            break;
        case GA_MODE_RECORDER: break;
        case GA_MODE_PLAYER:
            if (! gaInteractiveApp.bSetup)
                gaInteractiveApp.setup();
            else
                gaInteractiveApp.update();
            break;
        case GA_MODE_LASER:
            if (! gaLaserApp.bSetup)
                gaLaserApp.setup();
            else
                gaLaserApp.update();
            break;
    }

    //ofSoundUpdate();
}

//--------------------------------------------------------------
void gaApp::draw()
{
    switch (manager.mode) {
        case GA_MODE_START:
            manager.draw();
            break;
        case GA_MODE_RECORDER:
            glPushMatrix();
                glTranslatef(ofGetWidth()/2, ofGetHeight()/2, 0);
                ofDrawBitmapString("Recorder: Not ready yet.", 0, 0);
            glPopMatrix();
            break;
        case GA_MODE_PLAYER:
            if (gaInteractiveApp.bSetup)
                gaInteractiveApp.draw();
            break;
        case GA_MODE_LASER:
            if (gaLaserApp.bSetup)
                gaLaserApp.draw();
                //glPushMatrix();
                    //glTranslatef(ofGetWidth()/2,ofGetHeight()/2,0);
                    //ofDrawBitmapString("Laser Tag: Not ready yet.", 0, 0);
                //glPopMatrix();
            break;
    }
}

//--------------------------------------------------------------
void gaApp::keyPressed(int key)
{
    switch (key) {
        case OF_KEY_F1:
            manager.setMode( GA_MODE_START );
            break;
        case OF_KEY_F2:
            manager.setMode( GA_MODE_RECORDER );
            break;
        case OF_KEY_F3:
            manager.setMode( GA_MODE_PLAYER );
            break;
        case OF_KEY_F4:
            manager.setMode( GA_MODE_LASER );
            break;
    }

    if (! gaInteractiveApp.panel.isAnyTextBoxActive() ||
        manager.mode != GA_MODE_PLAYER
    ) {
        if (key == 'f' || key == 'F')
            ofToggleFullscreen();

        if (key == 'm' || key == 'M') {
            bMouseVisible = !bMouseVisible;
            if (bMouseVisible)
                ofShowCursor();
            else
                ofHideCursor();
        }
    }
}

//--------------------------------------------------------------
void gaApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void gaApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void gaApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void gaApp::mousePressed(int x, int y, int button)
{
    auto glfwWindow = window->getGLFWWindow();
    bool bShiftPressed = glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) ||
                         glfwGetKey(glfwWindow, GLFW_KEY_RIGHT_SHIFT);

    if (bShiftPressed)
        gaInteractiveApp.bShiftOn = true;
    else
        gaInteractiveApp.bShiftOn = false;

    if (manager.mode == GA_MODE_START) {
        int hi = manager.hitTest(x, y);
        if (hi >= 0) manager.setMode(hi);
    }
}

//--------------------------------------------------------------
void gaApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void gaApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void gaApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void gaApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void gaApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void gaApp::dragEvent(ofDragInfo dragInfo)
{

}
