#include "ofApp.h"

using namespace cv;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(280, 480);
    finder.setup("haarcascade_eye.xml");
    currentFrame.setFromPixels(cam.getPixels());
    finder.findHaarObjects(currentFrame);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        currentFrame.setFromPixels(cam.getPixels());
    }
    finder.findHaarObjects(currentFrame);
}

//--------------------------------------------------------------
void ofApp::draw() {
    //ofBackground(255, 255, 255);
    //cam.draw(0,0);
    currentFrame.draw(0, 0);
    for(unsigned int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle cur = finder.blobs[i].boundingRect;
        ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
