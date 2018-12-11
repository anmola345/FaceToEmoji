//
//  Face.hpp
//  EmotionDetection
//
//  Created by Anmol Agrawal on 12/3/18.
//

#ifndef Face_hpp
#define Face_hpp

#include <stdio.h>
#include "ofxOpenCv.h"

class Face {
public:
    ofImage picFrame; // i think that I should only take into account the ofImage of the Picframe. that way i can easily keep track of what what
    ofxCvHaarFinder face;
    ofVideoGrabber cam;
    ofRectangle findFace(); // this will look through the blobs and find the largest one
    void updateFaceBlobs(ofImage screenshot); // this is where I will update the camera and implement haarfinder for face
    void setCameraFrame();  // this is where I take the picture and use it to find the face
    void setupClassifier(std::string xmlFile);
};


#endif /* Face_hpp */
