#include "BubblesSource.h"

// Inspired by the BouncingBalls source

void BubblesSource::setup(){
    name = "Bubbles FBO Source";
    allocate(1000, 500);

    maxWidth = fbo->getWidth();
    maxHeight = fbo->getHeight();
    bgColor = ofColor(ofRandom(80, 100),
                      ofRandom(100, 150),
                      ofRandom(190, 250), 240);
    
    setupBubbles();
}

void BubblesSource::update(){
    updateBubbles();
}

void BubblesSource::draw(){
    ofClear(bgColor);
    drawBubbles(0, 0, maxWidth, maxHeight);
}

void BubblesSource::setupBubbles() {
    ofSetCircleResolution(50);
    
    // Create bubbles with a location and speed
    // Store each value in a separate vector for the drawing phase
    
    for (int i = 0; i < 50; i++){
        ofVec2f randomSpeed =
            ofVec2f(ofRandom(-3, 3),
                    ofRandom(-3, 3));
        
        ofVec2f randomLocation =
            ofVec2f(ofRandom(0, maxWidth),
                    ofRandom(0, maxHeight));
        
        speeds.push_back(randomSpeed);
        locations.push_back(randomLocation);
    }
}

void BubblesSource::updateBubbles(){
    // Iterate through each bubble location
    // Change a bubble position based on their location
    
    for(int i = 0; i < locations.size(); i++){
        ofVec2f loc = locations[i];
        ofVec2f speed = speeds[i];
        ofVec2f nextLoc = loc + speed;
        
        locations[i] = nextLoc;

        if (nextLoc.x < 5 || nextLoc.x > maxWidth - 5){
            speeds[i].x *= -1;
        }

        if (nextLoc.y < 5 || nextLoc.y > maxHeight - 5){
           speeds[i].y *= -1;
        }
    }
}

void BubblesSource::drawBubbles(int x, int y, int w, int h){
    // Draw each bubble with a random bubble color

    for(int i = 0; i < locations.size(); i++){
        ofPushStyle();
        
        ofColor color =
            ofColor(ofRandom(40, 80),
                    ofRandom(80, 120),
                    ofRandom(220, 250), 240);
        
        ofSetColor(color);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(locations[i], 100, 100);
        ofPopStyle();
    }
}
