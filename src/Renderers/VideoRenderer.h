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
    void resetOpacity();
    ofVideoPlayer video;
    ofTexture texture;
    ofPlanePrimitive plane;
    float tx0, ty0, tx1, ty1;
    int opacity, wait;
};

