#include "PulsingSource.h"

void PulsingSource::setup(){
    name = "Pulsing FBO Source";
    allocate(500, 500);
    
    // Init default background and foreground colors
    bgColor = ofColor(0);
    fgColor = ofColor(255, 120, 50, 200);
}

void PulsingSource::update(){
    // Update the scale of the rectangle based on time and sin
    // Increase an offset over time to fill the entire screen
    
    float frame = ofGetFrameNum();
    time = frame * 2;
    
    if (offset < 1.1) {
        offset += 0.001;
    } else {
        offset -= 0.001;
        bgColor = ofColor(ofRandom(220, 250), ofRandom(150, 180), ofRandom(40, 120));
    }
    
    float phase = sin(ofDegToRad(time));
    float rawScale = ofMap(phase, -1, 1, 0.1, 1 + offset);
    scale = ofClamp(rawScale, 0, 2);
}

void PulsingSource::draw(){
    int height = fbo->getHeight();
    int width = fbo->getWidth();
    int locX = width / 2;
    int locY = height;
   
    ofClear(bgColor);
    ofPoint coord(locX, locY);
    drawPulse(coord, width, height, time);
}

void PulsingSource::drawPulse(ofPoint coord, int width, int height, float time){
    // Draw centered rectangle at a given coordinate, scale, and size
    
    ofPushMatrix();
    ofPushStyle();
   
    ofSetColor(fgColor);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(coord.x, coord.y);
    
    ofScale(1, scale, 1);
    ofDrawRectangle(0, 0, width, height);
    
    ofPopStyle();
    ofPopMatrix();
}
