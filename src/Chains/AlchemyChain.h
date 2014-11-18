#pragma once
#include "ofMain.h"
#include "BaseChain.h"
#include "AlchemyPlayer.h"
#include "LowPassFilter.h"
#include "Reverb.h"

class AlchemyChain : public BaseChain {
    
public:
    void setup(string name, ofxAudioUnitMixer* mixer, int mixerChannel);
    void reverbDryWet(float val);
    void filterCutoff(float val);
    void alchemyRemixX(float val);
    void alchemyRemixY(float val);
    void showAlchemyUI();
    void showFilterUI();
    void showReverbUI();
    
protected:
    AlchemyPlayer alchemy;
    LowPassFilter filter;
    Reverb reverb;
};