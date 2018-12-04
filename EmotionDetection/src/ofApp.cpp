#include "ofApp.h"
#include "Face.hpp"

using namespace cv;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(280, 480);
    emoji.load("Neutral_Face_Emoji.png");
    eyes.setup("haarcascade_eye.xml");
    face.setup("haarcascade_frontalface_default.xml");
    smile.setup("haarcascade_smile.xml");
    // need to make sure that several classifiers are built to keep track of different expressions
    currentFrame.setFromPixels(cam.getPixels());
    face.findHaarObjects(currentFrame);
    //face.findHaarObjects(currentFrame);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        currentFrame.setFromPixels(cam.getPixels());
    }
    face.findHaarObjects(picFrame);
    //face.findHaarObjects(picFrame); // how can i change the color of this to make sure that I can tell what
    // blob is under which haarclassifier
    // i think this is where i have to check which emoji to print out. i think that this should work for now only if a face is
    // actually in the frame
}

//--------------------------------------------------------------
void ofApp::draw() {
    currentFrame.draw(480, 0);
    picFrame.draw(0, 0);
    emoji.draw(480,480);
    ofRectangle largestBlob; // this will be the face
    for(unsigned int i = 0; i < face.blobs.size(); i++) {
        ofRectangle cur = face.blobs[i].boundingRect;
        if(cur.height > largestBlob.height || cur.width > largestBlob.height)
            largestBlob = cur;
        //ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
    }
    ofDrawRectangle(largestBlob.x, largestBlob.y, largestBlob.width, largestBlob.height); // this is tracking the face
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    if(upper_key == 'T') {
        picFrame.setFromPixels(cam.getPixels());
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
