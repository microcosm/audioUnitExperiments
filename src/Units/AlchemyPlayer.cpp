#include "AlchemyPlayer.h"

void AlchemyPlayer::setup() {
    synth = ofxAudioUnit('aumu', 'CaC2', 'CamA');
    BaseAU::setup();
}