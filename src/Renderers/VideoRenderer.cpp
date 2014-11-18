#include "VideoRenderer.h"

void VideoRenderer::setup() {
    ofDisableArbTex();
    video.loadMovie("bad_reception.mov");
    texture = video.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    plane.set(ofGetWidth(), ofGetHeight(), 2, 2);
    plane.setPosition(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 0);
}

void VideoRenderer::update() {
    video.update();
    
    tx0 = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1);
    ty0 = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 1);
    tx1 = tx0 + 1;
    ty1 = ty0 + 1;
    plane.mapTexCoords(tx0, ty0, tx1, ty1);
}

void VideoRenderer::draw() {
    texture.bind();
    plane.draw();
    texture.unbind();
}

void VideoRenderer::play() {
    video.play();
}

void VideoRenderer::stop() {
    video.stop();
}