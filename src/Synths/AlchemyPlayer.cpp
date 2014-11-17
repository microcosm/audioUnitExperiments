#include "AlchemyPlayer.h"

void AlchemyPlayer::setup() {
    synth = ofxAudioUnit('aumu', 'CaC2', 'CamA');
}

void AlchemyPlayer::showUI() {
    synth.showUI();
}

void AlchemyPlayer::setParameter(int param, float value) {
    AudioUnitSetParameter(synth.getUnit(), param, kAudioUnitScope_Global, 0, value, 0);
}

void AlchemyPlayer::setParameters(int param1, int param2, ofVec2f value) {
    setParameter(param1, value.x);
    setParameter(param2, value.y);
}

ofxAudioUnit* AlchemyPlayer::getSynth() {
    return &synth;
}