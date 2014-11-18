#include "VideoRenderer.h"

void VideoRenderer::setup() {
    ofDisableArbTex();
    video.loadMovie("bad_reception.mov");
    texture = video.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    plane.set(ofGetWidth(), ofGetHeight(), 2, 2);
    plane.setPosition(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 0);
    wait = 0;
}

void VideoRenderer::update() {
    if(wait < 1) resetOpacity();
    else wait--;
    
    video.update();
    
    tx0 = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1);
    ty0 = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 1);
    tx1 = tx0 + 1;
    ty1 = ty0 + 1;
    plane.mapTexCoords(tx0, ty0, tx1, ty1);
}

void VideoRenderer::draw() {
    ofSetColor(255, 255, 255, opacity);
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

void VideoRenderer::resetOpacity() {
    float random = ofRandom(1);
    if(random < 0.6) {
        opacity = 100;
        wait = (int)ofRandom(30, 240);
    } else if(random < 0.7) {
        opacity = 255;
        wait = (int)ofRandom(5, 15);
    } else if(random < 0.8) {
        opacity = 200;
        wait = (int)ofRandom(10, 20);
    } else if(random < 0.9) {
        opacity = 170;
        wait = (int)ofRandom(20, 40);
    } else {
        opacity = 140;
        wait = (int)ofRandom(30, 60);
    }
}