#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "ofxAudioUnitMidi.h"
#include "ofxMidi.h"
#include "ofxBpm.h"
#include "PresetsHandler.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void play();
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
    
    void incrementNote();
    void decrementNote();
    void toggleNote();
    
    
    bool playing;
    
    ofxAudioUnit alchemySynth;
    ofxAudioUnitTap tap;
    ofxAudioUnitOutput output;
    ofxAudioUnitMidiReceiver midiReceiver;
    ofPolyline waveform;
    ofxMidiOut midiOut;
    ofxBpm bpm;
    
    PresetsHandler presets;
    
    string midiPortId;
    unsigned int currentPgm;
    int note, channel, velocity;
};
