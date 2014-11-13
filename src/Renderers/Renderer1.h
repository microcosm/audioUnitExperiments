#pragma once
#include "ofMain.h"
#include "ofxKinectV2OSC.h"
#include "BodyRenderer.h"

class Renderer1: public BodyRenderer {
public:
    virtual void draw();
	virtual void drawHand(Hand hand, Joint handJoint);
	virtual void drawBone(Joint joint1, Joint joint2);
	virtual void drawJoint(Joint joint);

protected:
};