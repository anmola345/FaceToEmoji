//
//  Emoji.cpp
//  EmotionDetection
//
//  Created by Anmol Agrawal on 12/12/18.
//
#include "Emoji.hpp"

void Emoji::setEmoji(std::string file)
{
    emojiImage.load(file);
    emojiImage.resize(500, 500);
}
