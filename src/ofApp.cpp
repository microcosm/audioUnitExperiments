#include "ofApp.h"

void ofApp::setup(){
    
    //Init default MIDI values
    midiPortId = "openFrameworksPatch";
    playing = true;
    channel = 1;
    velocity = 64;
    note = 60;
    
    //Init synth and preset handler
    alchemySynth = ofxAudioUnit('aumu', 'CaC2', 'CamA');
    presets.setup("alchemy", &alchemySynth);
    
    //Init MIDI reciever, tie it to synth
    midiReceiver.createMidiDestination(midiPortId);
    midiReceiver.routeMidiTo(alchemySynth);
    alchemySynth.connectTo(tap).connectTo(output);
    
    //Create MIDI sender
    midiOut.openPort(midiPortId);
    
    //Kick off 'pull' chain
    output.start();
    
    //Play on the beat
    ofAddListener(bpm.beatEvent, this, &ofApp::play);
    bpm.start();
}

void ofApp::play(void){
    if(playing) {
        midiOut.sendNoteOn(channel, note, velocity);
    }
}

void ofApp::update(){
    tap.getLeftWaveform(waveform, ofGetWidth(), ofGetHeight());
}

void ofApp::draw(){
    ofBackground(40);
    ofSetColor(255);
    waveform.draw();
    
    stringstream midiText;
    midiText << "MIDI" << endl << endl
    << "connected to port " << midiOut.getPort()
    << " \"" << midiOut.getName() << "\"" << endl
    << "is virtual?: " << midiOut.isVirtual() << endl << endl
    << "sending to channel " << channel << endl << endl
    << "current program: " << currentPgm << endl << endl
    << "note: " << note << endl
    << "velocity: " << velocity << endl;
    
    stringstream presetText;
    presetText << "Current: " << presets.currentIndex() << endl;
    
    for(int i = 0; i < presets.size(); i++) {
        presetText << endl << i << ": " << presets.at(i).getBaseName();
    }
    
    stringstream controlText;
    controlText << "CONTROLS" << endl
    << endl << "LEFT/RIGHT: Switch presets"
    << endl << "UP/DOWN:    Switch notes"
    << endl << "SPACE:      Start/stop playing"
    << endl << "u:          Show UI"
    << endl << "s:          Save preset";
    
    ofDrawBitmapString(midiText.str(), 20, 34);
    ofDrawBitmapString(presetText.str(), 500, 34);
    ofDrawBitmapString(controlText.str(), 20, 600);
}

void ofApp::exit() {
    midiOut.closePort();
}

void ofApp::keyPressed(int key){
    
    if (key == 'u') {
        alchemySynth.showUI();
        
    } else if(key == 's') {
        presets.save();
        
    } else if(key == 357) {
        incrementNote();
        
    } else if(key == 359) {
        decrementNote();
        
    } else if(key == 358) {
        presets.increment();
        
    } else if(key == 356) {
        presets.decrement();
        
    } else if(key == ' ') {
        toggleNote();
    }
}

void ofApp::mouseMoved(int x, int y){
    
    //set parameter based on mouse
    float param = ofMap(x, 0, ofGetWidth(), 0, 1, true);
    
    AudioUnitSetParameter(alchemySynth.getUnit(),
                          0, //index of the parameter - see param list
                          kAudioUnitScope_Global,
                          0,
                          param,
                          0);
}

void ofApp::incrementNote() {
    midiOut.sendNoteOff(channel, note, velocity);
    if(note == 127) note = 0;
    else note += 1;
}

void ofApp::decrementNote() {
    midiOut.sendNoteOff(channel, note, velocity);
    if(note == 0) note = 127;
    else note -= 1;
}

void ofApp::toggleNote() {
    playing = !playing;
    if(!playing) {
        midiOut.sendNoteOff(channel, note, velocity);
    }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}