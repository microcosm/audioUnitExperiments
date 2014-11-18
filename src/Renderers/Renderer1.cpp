#include "Renderer1.h"

void Renderer1::setup(vector<Skeleton>* _skeletons) {
    BodyRenderer::setup(_skeletons);
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
}

void Renderer1::draw() {
    
    fbo.begin();
    ofClear(255, 255, 255, 0);
    for(int i = 0; i < skeletons->size(); i++) {
        skeleton = &skeletons->at(i);
        drawHands();
    }
    fbo.end();
    
    fbo.draw(0, 0);
}

void Renderer1::drawHand(Hand hand, Joint handJoint) {
    ofFill();
    ofSetColor(ofColor::blue);
    ofCircle(handJoint.getPoint(), 100);
}

void Renderer1::drawBone(Joint joint1, Joint joint2) {}
void Renderer1::drawJoint(Joint joint) {}