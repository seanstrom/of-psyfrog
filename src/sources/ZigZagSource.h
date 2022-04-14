#pragma once

#include "ofMain.h"
#include "FboSource.h"

class ZigZagSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void drawZigZag(ofVec2f, int);
    
        int size;
        int maxSize;
    
        float margin;
        float maxWidth;
        float maxHeight;
        
        ofVec2f end;
        ofVec2f start;
        ofVec2f cursor;
        ofColor color;
    };
