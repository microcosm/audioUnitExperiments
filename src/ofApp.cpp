#include "ofApp.h"

void ofApp::setup(){
    smallFont.loadFont("selena.otf", 16); //http://openfontlibrary.org/en/font/selena
    largeFont.loadFont("selena.otf", 48);
    
    kinect.setup(12345, smallFont);
    skeletons = kinect.getSkeletons();
    renderer.setup(skeletons);
    video.setup();
    
    mixer.setInputBusCount(2);
    leftChain.setup("left-chain", &mixer, 0, ofColor::lightGray);
    rightChain.setup("right-chain", &mixer, 1, ofColor::white);
    leftChain.select();
    compressor.setup();
    mixer.connectTo(*compressor.get()).connectTo(output);
    output.start();
    
    playing = showDebugUI = false;
    
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
    if(playing) {
        video.play();
    } else {
        video.stop();
        leftChain.midiNoteOff();
        rightChain.midiNoteOff();
    }
}

void ofApp::toggleDebugUI() {
    showDebugUI = !showDebugUI;
}

void ofApp::update(){
    video.update();
    leftChain.update();
    rightChain.update();
    kinect.update();
}

void ofApp::draw(){
    ofBackground(0);
    video.draw();
    leftChain.draw();
    rightChain.draw();
    renderer.draw();
    
    if(kinect.hasSkeletons()) {
        skeleton = kinect.getNearestSkeleton();
        
        val = ofMap(skeleton->getSpineShoulder().z(), 10, 18, 0, 1, true);
        mixer.setInputVolume(val, 0);
        mixer.setInputVolume(val, 1);
        
        val = ofMap(skeleton->getLeftHandNormal().x, 0, 1, 0, 50);
        leftChain.reverbDryWet(val);
        val = ofMap(skeleton->getRightHandNormal().x, 0, 1, 50, 0);
        rightChain.reverbDryWet(val);
        
        val = ofMap(skeleton->getLeftHandNormal().y, 0, 1, 6900, 500);
        leftChain.filterCutoff(val);
        val = ofMap(skeleton->getRightHandNormal().y, 0, 1, 6900, 500);
        rightChain.filterCutoff(val);
    }
    
    if(showDebugUI) {
        drawDebugBox(10, 10, 420, 300);
        drawDebugBox(ofGetWidth() - 370, 10, 300, 230);
        drawDebugBox(10, ofGetHeight() - 160, 210, 150);
        
        ofSetColor(ofColor::black);
        ofDrawBitmapString(leftChain.report(), 24, 30);
        ofDrawBitmapString(rightChain.report(), 250, 30);
        ofDrawBitmapString(controls.report(), ofGetWidth() - 350, 30);
        largeFont.drawString("fps:\n" + ofToString(ofGetFrameRate()), 20, ofGetHeight() - 100);
    }
}

void ofApp::drawDebugBox(int x, int y, int w, int h) {
    ofSetColor(255, 255, 255, 128);
    ofFill();
    ofRect(x, y, w, h);
    ofSetColor(0);
    ofNoFill();
    ofRect(x, y, w, h);
}

void ofApp::exit() {
    leftChain.exit();
    rightChain.exit();
}

void ofApp::keyPressed(int key){
    
    AlchemyChain* selectedChain;
    selectedChain = leftChain.isSelected() ? &leftChain : &rightChain;
    
    if (key == 'u') {
        selectedChain->showAlchemyUI();
    } else if(key == 'r') {
        selectedChain->showReverbUI();
    } else if(key == 'f') {
        selectedChain->showFilterUI();
    } else if(key == 'd') {
        toggleDebugUI();
    } else if(key == 's') {
        selectedChain->savePresets();
    } else if(key == ']') {
        selectedChain->incrementMidiNote();
    } else if(key == '[') {
        selectedChain->decrementMidiNote();
    } else if(key == 359) {
        selectedChain->incrementPreset();
    } else if(key == 357) {
        selectedChain->decrementPreset();
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