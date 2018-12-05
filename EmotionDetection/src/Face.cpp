//
//  Face.cpp
//  EmotionDetection
//
//  Created by Anmol Agrawal on 12/3/18.
//

#include "Face.hpp"

ofRectangle Face::findFace()
{
    ofRectangle largestBlob; // this will be the face
    for(unsigned int i = 0; i < face.blobs.size(); i++) {
        ofRectangle cur = face.blobs[i].boundingRect;
        if(cur.height > largestBlob.height || cur.width > largestBlob.height)
            largestBlob = cur;
        //ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
    }
    return largestBlob;
}

void Face::updateFaceBlobs()
{
    cam.update();
    if(cam.isFrameNew()){
        currentFrame.setFromPixels(cam.getPixels());
    }
    face.findHaarObjects(picFrame);
}

void Face::setCameraFrame()
{
    picFrame.setFromPixels(cam.getPixels()); // this is where i take the picture for the face
}

