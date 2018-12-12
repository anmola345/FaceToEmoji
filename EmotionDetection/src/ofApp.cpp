#include "ofApp.h"

using namespace cv;


//--------------------------------------------------------------
void ofApp::setup(){
    enableFaceTracker.addListener(this, &ofApp::toggleFaceTracker);
    takeScreenshot.addListener(this, &ofApp::saveScreen);
    
    drawStartScreen = true;
    gui.setup();
    gui.add(enableFaceTracker.setup("Toggle Face Tracker"));
    gui.add(takeScreenshot.setup("Take Screenshot"));
    
    buttonPressed = true;
    ofSetBackgroundColor(255, 255, 255);
    ofSetWindowShape(1200, 1000);
    cam.setup(260, 480);
    
    emoji.setEmoji("Neutral_Face_Emoji.png");
    
    face.setup("haarcascade_frontalface_default.xml");
    currentFrame.setFromPixels(cam.getPixels());
    face.findHaarObjects(currentFrame);
    smileChecker = 0;
    smileMagnitude = 0.0;
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
        currentFrame.resize(600, 475);
    }
    face.findHaarObjects(picFrame);
    smileMagnitude = 0.0;
    ofxSmile::getSmile(picFrame, smileMagnitude);
    if(smileMagnitude < 3 && smileMagnitude > 1) {
        smileChecker = 1;
        emoji.setEmoji("super_happy.png");
    } else if (smileMagnitude <= 1 && smileMagnitude != 0) {
        smileChecker = 2;
        emoji.setEmoji("mildly_happy.png");
    } else {
        smileChecker = 0;
        emoji.setEmoji("Neutral_Face_Emoji.png");
    }
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
        emoji.emojiImage.draw(50, 250);
        
        currentFrame.draw(600, 500);
        picFrame.draw(600, 0);
        
        if(buttonPressed) {
            ofRectangle largestBlob;
            for(unsigned int i = 0; i < face.blobs.size(); i++) {
                ofRectangle cur = face.blobs[i].boundingRect;
                if(cur.height > largestBlob.height || cur.width > largestBlob.height)
                    largestBlob = cur;
            }
            
            ofDrawRectangle(largestBlob.x + 600, largestBlob.y, largestBlob.width, largestBlob.height);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    if(upper_key == 'T') {
        picFrame.setFromPixels(cam.getPixels());
        picFrame.resize(600, 475);
        picFrame.setImageType(OF_IMAGE_GRAYSCALE);
    } else if(upper_key == 'S') {
        drawStartScreen = !drawStartScreen;
    }
    
}
