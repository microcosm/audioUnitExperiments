#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "ofxBpm.h"
#include "PresetsHandler.h"
#include "MidiHandler.h"

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
    
    ofxAudioUnit alchemySynth;
    ofxAudioUnitTap tap;
    ofxAudioUnitOutput output;
    ofPolyline waveform;
    ofxBpm bpm;
    
    PresetsHandler presets;
    MidiHandler midi;
};
