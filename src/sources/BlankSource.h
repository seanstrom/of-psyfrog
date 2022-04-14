#pragma once

#include "ofMain.h"
#include "FboSource.h"

class BlankSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
};
