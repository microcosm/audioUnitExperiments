#include "Renderer1.h"

void Renderer1::setup(vector<Skeleton>* _skeletons) {
    BodyRenderer::setup(_skeletons);
    circleImage.loadImage("circle.png");
    allocate(&fbo1);
    allocate(&fbo2);
    opacity = 0;
}

void Renderer1::draw() {
    ofEnableAlphaBlending();
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
    ofDisableAlphaBlending();
}

void Renderer1::drawHand(Hand hand, Joint handJoint) {
    ofFill();
    ofSetColor(255, 255, 255, opacity);
    circleImage.draw(handJoint.getPoint());
}

void Renderer1::drawBone(Joint joint1, Joint joint2) {}
void Renderer1::drawJoint(Joint joint) {}

void Renderer1::setOpacity(float _opacity) {
    opacity = _opacity;
}

void Renderer1::allocate(ofFbo *fbo) {
    fbo->allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo->begin();
    ofClear(255, 255, 255, 0);
    fbo->end();
}