#pragma once

#include "ofMain.h"
#include "FboSource.h"

class BubblesSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
    
        void setupBubbles();
        void updateBubbles();
        void drawBubbles(int x, int y, int w, int h);

        vector <ofVec2f> speeds;
        vector <ofVec2f> locations;

        float maxWidth;
        float maxHeight;
        ofColor bgColor;
    };
