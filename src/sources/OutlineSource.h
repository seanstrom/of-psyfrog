#pragma once

#include "ofMain.h"
#include "FboSource.h"

class OutlineSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void drawOutline(ofVec2f, float);
        ofColor pickRandomColor();
    
        float size;
        float maxSize;
        float maxWidth;
        float maxHeight;
        ofColor color;
};
