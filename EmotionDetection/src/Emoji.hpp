//
//  Emoji.hpp
//  EmotionDetection
//
//  Created by Anmol Agrawal on 12/12/18.
//

#ifndef Emoji_hpp
#define Emoji_hpp

#include "ofMain.h"
#include <stdio.h>
#include "Emoji.hpp"
#include "iostream"

class Emoji {
public:
    std::string fileName;
    ofImage emojiImage;
    void setEmoji(std::string file);
};

#endif
