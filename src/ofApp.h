#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "VideoSource.h"
#include "SceneManager.h"
#include "BlankSource.h"
#include "PulsingSource.h"
#include "ZigZagSource.h"
#include "OutlineSource.h"
#include "BubblesSource.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDragged(int x, int y, int button);

    ofxPiMapper piMapper;
    
    BlankSource blankSource;
    ZigZagSource zigZagSource;
    PulsingSource pulsingSource;
    OutlineSource outlineSource;
    BubblesSource bubblesSource;
    
    ofImage dummyObjects;
    SceneManager sceneManager;
};
