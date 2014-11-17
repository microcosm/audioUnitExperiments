#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "ofxBpm.h"
#include "PresetsHandler.h"
#include "MidiHandler.h"
#include "Controls.h"
#include "ofxKinectV2OSC.h"
#include "Renderer1.h"
#include "AlchemyPlayer.h"
#include "LowPassFilter.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void play();
    void togglePlaying();
    void update();
    void draw();
    void exit();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    bool playing;
    
    AlchemyPlayer alchemy;
    LowPassFilter filter;
    ofxAudioUnitTap tap;
    ofxAudioUnitOutput output;
    ofPolyline waveform;
    ofxBpm bpm;
    
    PresetsHandler presets;
    MidiHandler midi;
    Controls controls;
    
    ofxKinectV2OSC kinect;
    Skeleton* skeleton;
    vector<Skeleton>* skeletons;
    Renderer1 renderer;
    ofTrueTypeFont smallFont, largeFont;
};
