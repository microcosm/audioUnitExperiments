#include "BaseChain.h"

void BaseChain::setup(string name, ofxAudioUnitMixer* mixer, int mixerChannel){}

void BaseChain::update(){
    tap.getLeftWaveform(waveform, ofGetWidth(), ofGetHeight());
}

void BaseChain::draw(){
    ofSetColor(ofColor::white);
    waveform.draw();
    ofSetColor(ofColor::black);
    ofDrawBitmapString(midi.report(), 20, 34);
    ofDrawBitmapString(presets.report(), 500, 34);
}

void BaseChain::exit() {
    midi.exit();
}

void BaseChain::savePresets() {
    presets.save();
}

void BaseChain::incrementPreset() {
    presets.increment();
}

void BaseChain::decrementPreset() {
    presets.decrement();
}

void BaseChain::incrementMidiNote() {
    midi.incrementNote();
}

void BaseChain::decrementMidiNote() {
    midi.decrementNote();
}

void BaseChain::midiNoteOn() {
    midi.sendNoteOn();
}

void BaseChain::midiNoteOff() {
    midi.sendNoteOff();
}