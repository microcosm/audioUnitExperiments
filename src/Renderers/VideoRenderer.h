#pragma once
#include "ofMain.h"

class VideoRenderer {
public:
    void setup();
    void update();
    void draw();
    void play();
    void stop();
    
protected:
    ofVideoPlayer video;
};