#include "LowPassFilter.h"

void LowPassFilter::setup() {
    synth = ofxAudioUnit(kAudioUnitType_Effect,
                          kAudioUnitSubType_LowPassFilter);
    AudioUnitSetParameter(synth.getUnit(), kLowPassParam_Resonance,
                          kAudioUnitScope_Global, 0, 20, 0);
    BaseAU::setup();
}