#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxSmile.h"
#include "ofxGui.h"
#include "Emoji.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    
    bool drawStartScreen;
    
    void toggleFaceTracker();
    void toggleStartScreen();
    void saveScreen();
    bool buttonPressed; // need to change this name
    
    ofxPanel gui;
    ofxButton enableFaceTracker;
    ofxButton takeScreenshot;
    ofxButton enableStartScreen;
    
    ofImage screenshot;
    ofVideoGrabber cam;
    ofImage currentFrame, picFrame;
    ofxCvHaarFinder face;
    Emoji emoji;
    
    float smileMagnitude;
    int smileChecker
};

#endif

