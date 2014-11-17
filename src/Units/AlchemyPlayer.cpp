#include "AlchemyPlayer.h"

void AlchemyPlayer::setup() {
    unit = ofxAudioUnit('aumu', 'CaC2', 'CamA');
    BaseAU::setup();
}