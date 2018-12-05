//#pragma once
//
//#include "ofMain.h"
//#include "ofxOpenCv2.h"
//
//class ofApp : public ofBaseApp{
//
//    public:
//        void setup();
//        void update();
//        void draw();
//
//        void keyPressed(int key);
//        void keyReleased(int key);
//        void mouseMoved(int x, int y );
//        void mouseDragged(int x, int y, int button);
//        void mousePressed(int x, int y, int button);
//        void mouseReleased(int x, int y, int button);
//        void mouseEntered(int x, int y);
//        void mouseExited(int x, int y);
//        void windowResized(int w, int h);
//        void dragEvent(ofDragInfo dragInfo);
//        void gotMessage(ofMessage msg);
//
//};


#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxSmile.h"
#include "Face.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    ofVideoGrabber cam;
    ofImage currentFrame, picFrame;
    ofxCvHaarFinder eyes;
    ofxCvHaarFinder face;
    ofxCvHaarFinder smile;
    ofImage emoji;
    Face faceLocation;
    
//    ofxCIDetector detector;
    
};

#endif

