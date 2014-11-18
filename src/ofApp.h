#pragma once

#include "ofMain.h"
#include "ofxBpm.h"
#include "Controls.h"
#include "ofxAudioUnit.h"
#include "ofxKinectV2OSC.h"
#include "Renderer1.h"
#include "Compressor.h"
#include "AlchemyChain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void play();
    void togglePlaying();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    bool playing;
    float val;
    
    AlchemyChain leftChain, rightChain;
    ofxBpm bpm;
    Compressor compressor;
    ofxAudioUnitMixer mixer;
    ofxAudioUnitOutput output;
    Controls controls;
    
    ofxKinectV2OSC kinect;
    Skeleton* skeleton;
    vector<Skeleton>* skeletons;
    Renderer1 renderer;
    ofTrueTypeFont smallFont, largeFont;
};
