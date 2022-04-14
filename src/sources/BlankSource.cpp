#include "BlankSource.h"

void BlankSource::setup(){
    name = "Blank FBO Source";
    allocate(500, 500);
}

void BlankSource::update(){
}

void BlankSource::draw(){
    // Do nothing but show a blank screen
    
    ofPushMatrix();
    ofPushStyle();
    
    ofClear(0);
    
    ofPopStyle();
    ofPopMatrix();
}
