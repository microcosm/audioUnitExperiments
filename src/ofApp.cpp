#include "ofApp.h"

void ofApp::setup(){
    
    smallFont.loadFont("selena.otf", 16); //http://openfontlibrary.org/en/font/selena
    largeFont.loadFont("selena.otf", 48);
    
    kinect.setup(12345, smallFont);
    skeletons = kinect.getSkeletons();
    renderer.setup(skeletons);
    
    alchemy.setup();
    ofxAudioUnit* synth = alchemy.get();
    presets.setup("alchemy", synth);
    midi.setup(synth);
    
    filter.setup();
    reverb.setup();
    
    synth->connectTo(*filter.get())
        .connectTo(*reverb.get())
        .connectTo(tap)
        .connectTo(output);
    
    output.start();
    playing = false;
    
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
    
    for(int i = 0; i < skeletons->size(); i++) {
        reverb.setParameter(kReverbParam_DryWetMix, ofMap(skeletons->at(i).getLeftHandNormal().x, 0, 1, 0, 50));
        filter.setParameter(kLowPassParam_CutoffFrequency, ofMap(skeletons->at(i).getLeftHandNormal().y, 0, 1, 6900, 500));
        
        alchemy.setParameter(RemixX, skeletons->at(i).getRightHandNormal().x * 0.34);
        alchemy.setParameter(RemixY, skeletons->at(i).getRightHandNormal().y);
    }
    
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
        alchemy.showUI();
    } else if(key == 'r') {
        reverb.showUI();
    } else if(key == 'f') {
        filter.showUI();
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

void ofApp::mouseMoved(int x, int y){}
void ofApp::keyReleased(int key){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}