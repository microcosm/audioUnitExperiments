#include "VideoRenderer.h"

void VideoRenderer::setup() {
    video.loadMovie("bad_reception.mov");
}

void VideoRenderer::update() {
    video.update();
}

void VideoRenderer::draw() {
    ofSetColor(ofColor::white);
    video.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void VideoRenderer::play() {
    video.play();
}

void VideoRenderer::stop() {
    video.stop();
}