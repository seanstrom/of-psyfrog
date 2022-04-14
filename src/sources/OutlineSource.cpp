#include "OutlineSource.h"

void OutlineSource::setup(){
    name = "Outline FBO Source";
    allocate(500, 500);
   
    size = 500;
    maxSize = 500;
    maxWidth = fbo->getWidth();
    maxHeight = fbo->getHeight();
    color = pickRandomColor();
}

void OutlineSource::update(){
    // Update the size of the rectangle based on time and sin
    // Change the outline color after the size gets too small
    
    float frame = ofGetFrameNum();
    float time = frame * 2;
    
    float phase = sin(ofDegToRad(time));
    float step = ofMap(phase, -1, 1, 5, 20);
    
    size -= step;
    if (size <= 0){
        size = maxSize;
        color = pickRandomColor();
    }
}

void OutlineSource::draw(){
    float centerX = maxWidth / 2;
    float centerY = maxHeight / 2;
    
    ofVec2f coord(centerX, centerY);
    drawOutline(coord, size);
}

void OutlineSource::drawOutline(ofVec2f coord, float size){
    // Draw a centered rectangle outline at the provided coordinate
    
    ofPushMatrix();
    ofPushStyle();
    
    ofNoFill();
    ofSetColor(color);
    ofTranslate(coord.x, coord.y);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(0, 0, size, size);
    
    ofPopStyle();
    ofPopMatrix();
}

ofColor OutlineSource::pickRandomColor(){
    return ofColor(ofRandom(100, 200), ofRandom(50, 80), ofRandom(180, 250), 248);
}
