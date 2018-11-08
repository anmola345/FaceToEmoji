# Project Proposal
# Anmol Agrawal
# CS126 - Emotion Detection Using OpenCV


My project idea stems from the OpenFrameworks addon [facetracker] 
    (https://github.com/kylemcdonald/ofxFaceTracker). I want to build off 
    this idea and use it to track facial expressions, and then print out 
    emojis based off these understood expressions. For example, a smile 
    will output the corresponding emoji, and so on. I want this project to 
    mainly be able to track the movements of the mouth and accutately 
    print out emojis onto the GUI for the user to see. 
    
My target goal for this project is to be able to understand, 
    recognize, and respond to 3-4 facial expressions. This would be the 
    simple expressions such as laughing, frowning, and crying. My initial plan is to have an algorothim that can check if a person is smiling or frowning. To do this, I also want to be able to distinguish if the person's mouth is open or closed. If I finish 
    this early, I want to work on building on this idea and expand to more 
    emojis. I also want to be able to track the movements of other parts 
    of the face and body. This would definitely be a reach goal, but by 
    incorporating the other aspects of the face and body, I could 
    encompass a larger number of emojis. 
    
In terms of how this project will look, I want this project to have an 
    integrated interface that will have the live stream of the face on one 
    side, and on the other side, the emoji that the face is mapping to. This emoji should change in real time as the expressions change. I am considering two different approaches to this project. One concept is to print out the emojis in a text file everytime the emotions change. Another concept is to just change the emoji that is portrayed on the GUI whenever the emotion changes. 
    plan to have a simple graphic user interface, but the bulk of the 
    complexity of this project comes from the facial recognition behind 
    the scenes. 
    
As for the library that I plan to use, the most logical option would 
    be to use [**OpenCV**] (https://opencv.org/about.html) for this 
    project because it relates to the computer having to recognize real 
    life objects and expressions. I also want to use openCV because they 
    provide many algorithms that can accelerate the production of this 
    project. From my research, I want to use the many projects online coupled with the information that OpenCV provides, to make this project. There are many sources and videos online that have created emotion detection programs, such as:
    
https://medium.freecodecamp.org/facial-recognition-as-aux-driver-8a49dfd477ca - article one the concept

https://ieeexplore.ieee.org/document/7926765 - scholarly article on the implementation
    
Overall, I am using an OpenFrameworks addon as an inspiration for this project.
I want to expand on the projects that have been made, as well as incorporate creative ideas of my own. Being able to recognize basic facial expressions is a simplified version of popular projects that many major companies are currently working on. In conclusion, I will be using OpenFrameworks and OpenCV to detect facial expressions and output emojis based off the understood emotions. 


    
    
