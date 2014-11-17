#include "Reverb.h"

void Reverb::setup() {
    synth = ofxAudioUnit(kAudioUnitType_Effect,
                         kAudioUnitSubType_MatrixReverb);
    
    setParameter(kReverbParam_SmallLargeMix, 30);
    
    BaseAU::setup();
}