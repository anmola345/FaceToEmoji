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
    ofxCvHaarFinder face;
    int x; // location of the face
    int y;
    
    vector<int> findFace();
};


#endif /* Face_hpp */
