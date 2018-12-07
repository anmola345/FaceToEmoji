#include "ofApp.h"

#include "Face.hpp"

using namespace cv;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);
    ofSetWindowShape(1000, 1000);
    cam.setup(280, 480);
    //faceLocation.cam.setup(280, 480);
    //faceLocation.face.setup("haarcascade_frontalface_default.xml");
    
    emoji.load("Neutral_Face_Emoji.png"); // need to make this emoji smaller
    emoji.resize(300, 300);
    
    //smileEmoji.load("Neutral_Face_Emoji.png");
    //smileEmoji.resize(300, 300);

    //laughingEmoji.load("super_happy.png");
    //laughingEmoji.resize(300,300);
    
    face.setup("haarcascade_frontalface_default.xml");
    currentFrame.setFromPixels(cam.getPixels());
    face.findHaarObjects(currentFrame);
    smileChecker = 0;
    previousTime = ofGetElapsedTimef() - 10.0; // I could use this to check for the time and then get 
    smileMagnitude = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        currentFrame.setFromPixels(cam.getPixels());
        currentFrame.resize(600, 400);
    }
    
    face.findHaarObjects(picFrame);
    //faceLocation.updateFaceBlobs();
    smileMagnitude = 0.0;
    ofxSmile::getSmile(picFrame, smileMagnitude);
    cout << smileMagnitude << endl;
    if(smileMagnitude < 3 && smileMagnitude > 1) {
        smileChecker = 1;
        //previousTime = ofGetElapsedTimef();
        emoji.load("super_happy.png");
    } else if (smileMagnitude <= 1) {
        smileChecker = 2;
        emoji.load("mildly_happy.png");
    }
    else{
        smileChecker = 0;
        emoji.load("Neutral_Face_Emoji.png");
    }
    
    emoji.resize(300,300);
}

//--------------------------------------------------------------
void ofApp::draw() {
//    if(smileChecker == 0)
//        emoji.draw(600,400);
//    else if(smileChecker == 1)
//        smileEmoji.draw(600, 400);
//    else if(smileChecker == 2)
//        laughingEmoji.draw(600, 400);
    emoji.draw(600,400);
    
    currentFrame.draw(0, 600);
    picFrame.draw(0, 0);
    
    //smileEmoji.draw(600,400);
    ofRectangle largestBlob; // this will be the face
    for(unsigned int i = 0; i < face.blobs.size(); i++) {
        ofRectangle cur = face.blobs[i].boundingRect;
        if(cur.height > largestBlob.height || cur.width > largestBlob.height)
            largestBlob = cur;
    }
    //ofDrawRectangle(largestBlob.x, largestBlob.y, largestBlob.width, largestBlob.height); // this is tracking the face
    //ofRectangle finalFace = faceLocation.findFace();
    //ofDrawRectangle(finalFace.x, finalFace.y, finalFace.width, finalFace.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    if(upper_key == 'T') {
        picFrame.setFromPixels(cam.getPixels());
        picFrame.resize(600, 400);
        picFrame.setImageType(OF_IMAGE_GRAYSCALE);
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
