#include "LowPassFilter.h"

void LowPassFilter::setup() {
    synth = ofxAudioUnit(kAudioUnitType_Effect,
                          kAudioUnitSubType_LowPassFilter);
    AudioUnitSetParameter(synth.getUnit(), kLowPassParam_Resonance,
                          kAudioUnitScope_Global, 0, 20, 0);
}

void LowPassFilter::showUI() {
    synth.showUI();
}

void LowPassFilter::setParameter(int param, float value) {
    AudioUnitSetParameter(synth.getUnit(), param, kAudioUnitScope_Global, 0, value, 0);
}

void LowPassFilter::setParameters(int param1, int param2, ofVec2f value) {
    setParameter(param1, value.x);
    setParameter(param2, value.y);
}

ofxAudioUnit* LowPassFilter::getSynth() {
    return &synth;
}