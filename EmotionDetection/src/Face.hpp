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
    ofVideoGrabber cam; // the frame that this face will be looking at
    ofImage currentFrame, picFrame;
    ofxCvHaarFinder face;
    int x; // location of the face
    int y;
    
    ofRectangle findFace(); // this will look through the blobs and find the largest one
    void updateFaceBlobs(); // this is where I will update the camera and implement haarfinder for face
    void setCameraFrame();  // this is where I take the picture and use it to find the face
    
};


#endif /* Face_hpp */
