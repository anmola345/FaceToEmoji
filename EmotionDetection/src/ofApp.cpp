#include "ofApp.h"

#include "Face.hpp"

using namespace cv;


//--------------------------------------------------------------
void ofApp::setup(){
    enableFaceTracker.addListener(this, &ofApp::toggleFaceTracker);
    takeScreenshot.addListener(this, &ofApp::saveScreen);
//    enableStartScreen.addListener(this, &ofApp::toggleStartScreen);
    
    drawStartScreen = true;
    gui.setup();
    gui.add(enableFaceTracker.setup("Toggle Face Tracker"));
    gui.add(takeScreenshot.setup("Take Screenshot"));
//    gui.add(enableStartScreen.setup("Toggle Start Screen"));
    
    buttonPressed = true;
    ofSetBackgroundColor(255, 255, 255);
    ofSetWindowShape(1000, 1000);
    cam.setup(260, 480);
    
    emoji.load("Neutral_Face_Emoji.png");
    emoji.resize(300, 300);
    
    face.setup("haarcascade_frontalface_default.xml");
    currentFrame.setFromPixels(cam.getPixels());
    face.findHaarObjects(currentFrame);
    smileChecker = 0;
    previousTime = ofGetElapsedTimef() - 10.0;
    smileMagnitude = 0.0;
    
    verdana14.load("verdana.ttf", 14, true, true);
    verdana14.setLineHeight(18.0f);
    verdana14.setLetterSpacing(1.037);
}

//--------------------------------------------------------------
void ofApp::toggleFaceTracker()
{
    buttonPressed = !buttonPressed;
}

//--------------------------------------------------------------
void ofApp::saveScreen()
{
    screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    screenshot.save("screenshot.png");
}

//--------------------------------------------------------------
void ofApp::toggleStartScreen()
{
    drawStartScreen = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    if(cam.isFrameNew()) {
        currentFrame.setFromPixels(cam.getPixels());
        currentFrame.resize(600, 400);
    }
    face.findHaarObjects(picFrame);
    smileMagnitude = 0.0;
    ofxSmile::getSmile(picFrame, smileMagnitude);
    if(smileMagnitude < 3 && smileMagnitude > 1) {
        smileChecker = 1;
        //previousTime = ofGetElapsedTimef();
        emoji.load("super_happy.png");
    } else if (smileMagnitude <= 1 && smileMagnitude != 0) {
        smileChecker = 2;
        emoji.load("mildly_happy.png");
    } else {
        smileChecker = 0;
        emoji.load("Neutral_Face_Emoji.png");
    }
    
    emoji.resize(300,300);
}

//--------------------------------------------------------------
void ofApp::draw() {
    if(drawStartScreen) {
        ofSetBackgroundColor(0, 0, 0);
        
        ofDrawBitmapString("Emotion Detection", 350, 300);
        ofDrawBitmapString("Press 'S' to exit the start screen", 350, 350);
        ofDrawBitmapString("Press 'T' to take a picture", 350, 400);
    } else {
        ofSetBackgroundColor(255, 255, 255);
        gui.draw();
        emoji.draw(600,400);
        
        currentFrame.draw(0, 600);
        picFrame.draw(0, 0);
        
        if(buttonPressed) {
            ofRectangle largestBlob;
            for(unsigned int i = 0; i < face.blobs.size(); i++) {
                ofRectangle cur = face.blobs[i].boundingRect;
                if(cur.height > largestBlob.height || cur.width > largestBlob.height)
                    largestBlob = cur;
            }
            
            ofDrawRectangle(largestBlob.x, largestBlob.y, largestBlob.width, largestBlob.height);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    if(upper_key == 'T') {
        picFrame.setFromPixels(cam.getPixels());
        picFrame.resize(600, 400);
        picFrame.setImageType(OF_IMAGE_GRAYSCALE);
        //faceLocation.setCameraFrame();
    } else if(upper_key == 'S') {
        drawStartScreen = !drawStartScreen;
        //faceLocation.setCameraFrame();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
//void ofApp::mouseEntered(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseExited(int x, int y){
//
//}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){
//
//}
