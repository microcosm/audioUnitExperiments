#include "ofApp.h"

void ofApp::setup(){
    smallFont.loadFont("selena.otf", 16); //http://openfontlibrary.org/en/font/selena
    largeFont.loadFont("selena.otf", 48);
    
    kinect.setup(12345, smallFont);
    skeletons = kinect.getSkeletons();
    renderer.setup(skeletons);
    
    alchemySynth = ofxAudioUnit('aumu', 'CaC2', 'CamA');
    presets.setup("alchemy", &alchemySynth);
    midi.setup(&alchemySynth);
    
    alchemySynth.connectTo(tap).connectTo(output);
    output.start();
    playing = true;
    
    ofAddListener(bpm.beatEvent, this, &ofApp::play);
    bpm.start();
}

void ofApp::play(void){
    if(playing) {
        midi.sendNoteOn();
    }
}

void ofApp::togglePlaying() {
    playing = !playing;
    if(!playing) {
        midi.sendNoteOff();
    }
}

void ofApp::update(){
    tap.getLeftWaveform(waveform, ofGetWidth(), ofGetHeight());
    kinect.update();
}

void ofApp::draw(){
    ofSetColor(ofColor::white);
    waveform.draw();
    renderer.draw();
    
    ofSetColor(ofColor::black);
    ofDrawBitmapString(midi.report(), 20, 34);
    ofDrawBitmapString(presets.report(), 500, 34);
    ofDrawBitmapString(controls.report(), 500, 600);
    largeFont.drawString("fps:\n" + ofToString(ofGetFrameRate()), 20, ofGetHeight() - 100);
}

void ofApp::exit() {
    midi.exit();
}

void ofApp::keyPressed(int key){
    if (key == 'u') {
        alchemySynth.showUI();
    } else if(key == 's') {
        presets.save();
    } else if(key == 357) {
        midi.incrementNote();
    } else if(key == 359) {
        midi.decrementNote();
    } else if(key == ' ') {
        togglePlaying();
    } else if(key == 358) {
        presets.increment();
    } else if(key == 356) {
        presets.decrement();
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

void ofApp::keyReleased(int key){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}