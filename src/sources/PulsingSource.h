#pragma once

#include "ofMain.h"
#include "FboSource.h"

class PulsingSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void drawPulse(ofPoint, int, int, float);
    
        ofColor fgColor;
        ofColor bgColor;
    
        float time;
        float scale;
        float offset;
};
