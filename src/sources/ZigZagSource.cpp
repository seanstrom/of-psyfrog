#include "ZigZagSource.h"

void ZigZagSource::setup(){
    // Set default colors and sizes
    // Set initial values for start, end, and cursor coordinates
    
    name = "ZigZag FBO Source";
    allocate(500, 500);
    
    size = 100;
    maxSize = 100;
    margin = 0;

    maxWidth = fbo->getWidth();
    maxHeight = fbo->getHeight();
    
    end = ofVec2f(maxWidth, 0);
    start = ofVec2f(0, maxHeight);
    cursor = start;
    
    ofColor purple = ofColor(120, 4, 200, 200);
    color = purple;
}

void ZigZagSource::update(){
    float frame = ofGetFrameNum();
    float time = frame * 2;
    float marginOfAcc = 1;
    
    float minX = 0 + margin;
    float maxX = maxWidth - margin;
    float offset = ofRandom(10, 50) / 100;
    
    float phase = sin(ofDegToRad(time * offset));
    float scale = ofMap(phase, -1, 1, 0.1 * offset, 0.5 * offset);
    
    size = maxSize * scale * 10;
    
    // After the first frame start drawing across from left to right and later right to left
    // The distance the cursor moves is based on the `scale` value and lerp functions
    // Basically cursor jumps across the screen until it reaches the edge, and then moves up.
    // This effectively paints the whole area from bottom to top, and left-right-left (zig zag).
    
    if (frame > 1){
        if (start.x < end.x){
            // While drawing from left to right, update the cursor position
            
            float stepX = ofLerp(start.x, end.x, scale);
            float nextX = ofClamp(cursor.x + stepX, cursor.x, end.x);
            float nearEndX = end.x - marginOfAcc;
            
            cursor.x = nextX;
            
            // If the cursor is near the right edge...
            // Move the cursor up and change the drawing direction to be right to left
            
            if (ofInRange(nextX, nearEndX, end.x)){
                float stepY = ofLerp(end.y, cursor.y, 0.1);
                float nextY = cursor.y - stepY;
                
                end.x = minX;
                start.x = maxX;
                
                cursor.x = start.x;
                cursor.y = nextY;
            }
        } else if (end.x < start.x) {
            // While drawing from right to left, update the cursor position
            
            float stepX = ofLerp(end.x, start.x, scale);
            float nextX = ofClamp(cursor.x - stepX, end.x, cursor.x);
            float nearEndX = end.x + marginOfAcc;
            
            cursor.x = nextX;
            
            // If the cursor is near the left edge...
            // Move the cursor up and change the drawing direction to be right to left
            
            if (ofInRange(nextX, end.x, nearEndX)){
                float stepY = ofLerp(end.y, cursor.y, 0.1);
                float nextY = cursor.y - stepY;
                
                end.x = maxX;
                start.x = minX;
                
                cursor.x = start.x;
                cursor.y = nextY;
            }
        }
        
        if (ofInRange(cursor.y, end.y, end.y + size / 2)){
            // If near the top, change cursor color
            // Also increase the margin from the edges of screen
            // If the margin is too big, then reset the size
            
            cursor.y = start.y;
            
            margin += 25;
            if (margin > 200){
                margin = 0;
            }
                            
            color = ofColor(ofRandom(5, 175),
                            ofRandom(80, 200),
                            ofRandom(10, 200), 120);
        }
    }
}

void ZigZagSource::draw(){
    drawZigZag(cursor, size);
}

void ZigZagSource::drawZigZag(ofVec2f coord, int size){
    // Draw a rectangle at a given size at a coordinate
    
    ofPushMatrix();
    ofPushStyle();
    
    ofSetColor(color);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofTranslate(coord.x, coord.y);
    ofDrawRectangle(0, 0, size, size);
    
    ofPopStyle();
    ofPopMatrix();
}
