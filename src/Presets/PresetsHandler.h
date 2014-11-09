#pragma once
#include "ofMain.h"
#include "ofxAudioUnit.h"

class PresetsHandler{
    
public:
    void setup(string synthName, ofxAudioUnit* synth);
    void load(int index);
    void save();
    void increment();
    void decrement();
    void readFromDisk();
    int size();
    ofFile at(int i);
    int currentIndex();
    
protected:
    
    ofxAudioUnit* synth;
    string synthName;
    vector<ofFile> presets;
    int currentPreset;
    string updateMsg;
};
