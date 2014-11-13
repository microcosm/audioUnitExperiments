#include "Renderer1.h"

void Renderer1::draw() {
    BodyRenderer::draw();
}

void Renderer1::drawHand(Hand hand, Joint handJoint) {
    BodyRenderer::drawHand(hand, handJoint);
}

void Renderer1::drawBone(Joint joint1, Joint joint2) {
    BodyRenderer::drawBone(joint1, joint2);
}

void Renderer1::drawJoint(Joint joint) {
    BodyRenderer::drawJoint(joint);
}