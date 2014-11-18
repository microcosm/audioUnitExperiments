#pragma once
#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "PresetsHandler.h"
#include "AlchemyPlayer.h"
#include "LowPassFilter.h"
#include "MidiHandler.h"
#include "Reverb.h"

class AlchemyChain {
    
public:
    void setup(string name);
    void update();
    void draw();
    void exit();
    void reverbDryWet(float val);
    void filterCutoff(float val);
    void alchemyRemixX(float val);
    void alchemyRemixY(float val);
    void showAlchemyUI();
    void showFilterUI();
    void showReverbUI();
    void savePresets();
    void incrementPreset();
    void decrementPreset();
    void incrementMidiNote();
    void decrementMidiNote();
    void midiNoteOn();
    void midiNoteOff();
    
protected:
    AlchemyPlayer alchemy;
    LowPassFilter filter;
    Reverb reverb;
    ofxAudioUnitTap tap;
    ofxAudioUnitOutput output;
    ofPolyline waveform;
    
    PresetsHandler presets;
    MidiHandler midi;
};