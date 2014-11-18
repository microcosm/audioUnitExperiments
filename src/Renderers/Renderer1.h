#pragma once
#include "ofMain.h"
#include "ofxKinectV2OSC.h"
#include "BodyRenderer.h"

class Renderer1: public BodyRenderer {
public:
    void setup(vector<Skeleton>* _skeletons);
    void draw();
	void drawHand(Hand hand, Joint handJoint);
	void drawBone(Joint joint1, Joint joint2);
	void drawJoint(Joint joint);

protected:
    void allocate(ofFbo *fbo);
    ofFbo fbo1, fbo2;
};