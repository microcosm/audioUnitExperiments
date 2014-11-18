#include "Renderer1.h"

void Renderer1::setup(vector<Skeleton>* _skeletons) {
    BodyRenderer::setup(_skeletons);
    allocate(&fbo1);
    allocate(&fbo2);
}

void Renderer1::draw() {
    fbo1.begin();
    ofClear(0, 0, 0, 20);
    for(int i = 0; i < skeletons->size(); i++) {
        skeleton = &skeletons->at(i);
        drawHands();
    }
    fbo1.end();
    
    fbo2.begin();
    fbo1.draw(0,0);
    fbo2.end();
    
    fbo2.draw(0,0);
}

void Renderer1::drawHand(Hand hand, Joint handJoint) {
    ofFill();
    ofSetColor(ofColor::white);
    ofCircle(handJoint.getPoint(), 100);
}

void Renderer1::drawBone(Joint joint1, Joint joint2) {}
void Renderer1::drawJoint(Joint joint) {}

void Renderer1::allocate(ofFbo *fbo) {
    fbo->allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo->begin();
    ofClear(255, 255, 255, 0);
    fbo->end();
}