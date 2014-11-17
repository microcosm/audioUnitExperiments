#include "BaseAU.h"

void BaseAU::setup() {}

void BaseAU::showUI() {
    synth.showUI();
}

void BaseAU::setParameter(int param, float value) {
    AudioUnitSetParameter(synth.getUnit(), param, kAudioUnitScope_Global, 0, value, 0);
}

void BaseAU::setParameters(int param1, int param2, ofVec2f value) {
    setParameter(param1, value.x);
    setParameter(param2, value.y);
}

ofxAudioUnit* BaseAU::getSynth() {
    return &synth;
}