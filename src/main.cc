#include "ofMain.h"
#include "gaApp.h"
#include "ofAppGLFWWindow.h"

ofAppGLFWWindow* window;

//--------------------------------------------------------------
int main()
{
    window = new ofAppGLFWWindow();
    ofSetupOpenGL(window, 1024, 768, OF_WINDOW); // <-------- setup the GL context

    // this kicks off the running of my app
    ofRunApp(new gaApp());
}
