#include "ofApp.h"

using namespace cv;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(280, 480);
    eyes.setup("haarcascade_eye.xml");
    face.setup("haarcascade_frontalface_default.xml");
    // need to make sure that several classifiers are built to keep track of different expressions
    currentFrame.setFromPixels(cam.getPixels());
    eyes.findHaarObjects(currentFrame);
    face.findHaarObjects(currentFrame);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        currentFrame.setFromPixels(cam.getPixels());
    }
    eyes.findHaarObjects(picFrame);
    face.findHaarObjects(picFrame); // how can i change the color of this to make sure that I can tell what
    // blob is under which haarclassifier
}

//--------------------------------------------------------------
void ofApp::draw() {
    //ofBackground(255, 255, 255);
    //cam.draw(0,0);
    currentFrame.draw(480, 0);
    picFrame.draw(0, 0);
    for(unsigned int i = 0; i < eyes.blobs.size(); i++) {
        ofRectangle cur = eyes.blobs[i].boundingRect;
        ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
    }
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
