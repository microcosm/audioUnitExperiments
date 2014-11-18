#include "AlchemyChain.h"

void AlchemyChain::setup(string name, ofxAudioUnitMixer* mixer, int mixerChannel){
    alchemy.setup();
    filter.setup();
    reverb.setup();
    
    ofxAudioUnit* synth = alchemy.get();
    presets.setup(name, synth);
    midi.setup(synth, name);
    
    synth->connectTo(*filter.get())
      .connectTo(*reverb.get())
      .connectTo(tap)
      .connectTo(*mixer, mixerChannel);
}

void AlchemyChain::update(){
    tap.getLeftWaveform(waveform, ofGetWidth(), ofGetHeight());
}

void AlchemyChain::draw(){
    ofSetColor(ofColor::white);
    waveform.draw();
    ofSetColor(ofColor::black);
    ofDrawBitmapString(midi.report(), 20, 34);
    ofDrawBitmapString(presets.report(), 500, 34);
}

void AlchemyChain::exit() {
    midi.exit();
}

void AlchemyChain::reverbDryWet(float val) {
    reverb.setParameter(kReverbParam_DryWetMix, val);
}

void AlchemyChain::filterCutoff(float val) {
    filter.setParameter(kLowPassParam_CutoffFrequency, val);
}

void AlchemyChain::alchemyRemixX(float val) {
    alchemy.setParameter(RemixX, val);
}

void AlchemyChain::alchemyRemixY(float val) {
    alchemy.setParameter(RemixY, val);
}

void AlchemyChain::showAlchemyUI() {
    alchemy.showUI();
}

void AlchemyChain::showFilterUI() {
    filter.showUI();
}

void AlchemyChain::showReverbUI() {
    reverb.showUI();
}

void AlchemyChain::savePresets() {
    presets.save();
}

void AlchemyChain::incrementPreset() {
    presets.increment();
}

void AlchemyChain::decrementPreset() {
    presets.decrement();
}

void AlchemyChain::incrementMidiNote() {
    midi.incrementNote();
}

void AlchemyChain::decrementMidiNote() {
    midi.decrementNote();
}

void AlchemyChain::midiNoteOn() {
    midi.sendNoteOn();
}

void AlchemyChain::midiNoteOff() {
    midi.sendNoteOff();
}