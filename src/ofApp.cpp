#include "ofApp.h"

void ofApp::setup(){
    
    smallFont.loadFont("selena.otf", 16); //http://openfontlibrary.org/en/font/selena
    largeFont.loadFont("selena.otf", 48);
    
    kinect.setup(12345, smallFont);
    skeletons = kinect.getSkeletons();
    renderer.setup(skeletons);
    
    mixer.setInputBusCount(2);
    leftChain.setup("left-chain", &mixer, 0);
    rightChain.setup("right-chain", &mixer, 1);
    leftChain.select();
    compressor.setup();
    mixer.connectTo(*compressor.get()).connectTo(output);
    output.start();
    
    playing = false;
    
    ofAddListener(bpm.beatEvent, this, &ofApp::play);
    bpm.start();
}

void ofApp::play(void){
    if(playing) {
        leftChain.midiNoteOn();
        rightChain.midiNoteOn();
    }
}

void ofApp::togglePlaying() {
    playing = !playing;
    if(!playing) {
        leftChain.midiNoteOff();
        rightChain.midiNoteOff();
    }
}

void ofApp::update(){
    leftChain.update();
    rightChain.update();
    kinect.update();
}

void ofApp::draw(){
    ofSetColor(ofColor::white);
    leftChain.draw();
    rightChain.draw();
    renderer.draw();
    
    for(int i = 0; i < skeletons->size(); i++) {
        val = ofMap(skeletons->at(i).getLeftHandNormal().x, 0, 1, 0, 50);
        leftChain.reverbDryWet(val);
        val = ofMap(skeletons->at(i).getRightHandNormal().x, 0, 1, 50, 0);
        rightChain.reverbDryWet(val);
        
        val = ofMap(skeletons->at(i).getLeftHandNormal().y, 0, 1, 6900, 500);
        leftChain.filterCutoff(val);
        val = ofMap(skeletons->at(i).getRightHandNormal().y, 0, 1, 6900, 500);
        rightChain.filterCutoff(val);
    }
    
    ofSetColor(ofColor::black);
    ofDrawBitmapString(leftChain.report(), 24, 30);
    ofDrawBitmapString(rightChain.report(), 250, 30);
    ofDrawBitmapString(controls.report(), ofGetWidth() - 350, 30);
    largeFont.drawString("fps:\n" + ofToString(ofGetFrameRate()), 20, ofGetHeight() - 100);
}

void ofApp::exit() {
    leftChain.exit();
    rightChain.exit();
}

void ofApp::keyPressed(int key){
    
    
    if (key == 'u') {
        leftChain.showAlchemyUI();
    } else if(key == 'r') {
        leftChain.showReverbUI();
    } else if(key == 'f') {
        leftChain.showFilterUI();
    } else if(key == 's') {
        leftChain.savePresets();
    } else if(key == ']') {
        leftChain.incrementMidiNote();
    } else if(key == '[') {
        leftChain.decrementMidiNote();
    } else if(key == 357) {
        leftChain.incrementPreset();
    } else if(key == 359) {
        leftChain.decrementPreset();
    } else if(key == ' ') {
        togglePlaying();
    } else if(key == 358 || key == 356) {
        leftChain.toggleSelected();
        rightChain.toggleSelected();
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