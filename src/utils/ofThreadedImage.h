#ifndef _THREADED_IMAGE
#define _THREADED_IMAGE


#include "ofMain.h"
//#include "ofxThread.h"

class ofxThreadedImageSaver : public ofThread, public ofImage
{
    public:
        string fileName;
        int imgcount;

        void threadedFunction()
        {
            if( lock() )
            {
                imgcount++;
                save(fileName);
                unlock();
            } else {
                printf("ofxThreadedImageSaver - cannot save %s cos I'm locked", fileName.c_str());
            }
            stopThread();
        }

        void saveThreaded(string fileName)
        {
            this->fileName = fileName;
            startThread(false);   // blocking
        }
};

#endif
