#include "ofApp.h"
#include <math.h>


//float threeFourTime_x;
float fourFourTime_x;
float fiveFourTime_x;

//float threeFourTime[81];
float fourFourTime[41];
float fiveFourTime[33];

//int threeFourTimeColor[81];
int fourFourTimeColor[41];
int fiveFourTimeColor[33];


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1800, 768);
    ofBackground(255);
    
    for (int i = 0; i < 60; i++) {
        fourFourTime[i] = (float)i * (40.0/40.0) / 2;
    }

    for (int i = 0; i < 48; i++) {
        fiveFourTime[i] = (float)i * (40.0/32.0) / 2;
    }
    
    fourFourTime_x = (ofGetWidth() - 100.0) / 40.0;
    fiveFourTime_x = (ofGetWidth() - 100.0) / 32.0;
    
    // 2 ... 4/4 == 5/4
    // 4 ... all

    
    for (int j = 0; j < 41; j++) {
        for (int k = 0; k < 33; k++) {
            if (fmod(fourFourTime[j], 4.0) == 0 && j != 0) {
                fourFourTimeColor[j] = 4;
            }
            if (fabsf(fourFourTime[j] - fiveFourTime[k]) < FLT_EPSILON){
                fourFourTimeColor[j] = 2;
            }
        }
    }
    
    for (int k = 0; k < 33; k++) {
        for (int j = 0; j < 41; j++) {
            if (fabsf(fiveFourTime[k] - fourFourTime[j]) < FLT_EPSILON){
                fiveFourTimeColor[k] = 2;
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(5);
    
    for (int i = 0; i < 41; i++) {
        switch (fourFourTimeColor[i]) {
            case 1:
                ofSetColor(255, 100, 0);
                break;
            case 2:
                ofSetColor(0, 255, 0);
                break;
            case 3:
                ofSetColor(0, 0, 255);
                break;
            case 4:
                ofSetColor(255, 0, 0);
                break;
            default:
                ofSetColor(128, 128, 128);
                break;
        }
        
        if (i % 8 == 0){
            ofDrawLine(i * fourFourTime_x + 50, 140, i * fourFourTime_x + 50, 240);
        } else {
            ofDrawLine(i * fourFourTime_x + 50, 160, i * fourFourTime_x + 50, 220);

        }
        
        ofSetColor(0);
        if (i % 2 == 0) {
            ofDrawBitmapString(ofToString(fourFourTime[i]+1), i * fourFourTime_x + 45, 250);
        } else {
            ofDrawBitmapString(ofToString(fourFourTime[i]+1), i * fourFourTime_x + 45, 265);
        }
    }
    
    for (int i = 0; i < 33; i++) {
        switch (fiveFourTimeColor[i]) {
            case 1:
                ofSetColor(255, 100, 0);
                break;
            case 2:
                ofSetColor(0, 255, 0);
                break;
            case 3:
                ofSetColor(0, 0, 255);
                break;
            case 4:
                ofSetColor(255, 0, 0);
                break;
            default:
                ofSetColor(128, 128, 128);
                break;
        }
        
        if (i % 8 == 0){
            ofDrawLine(i * fiveFourTime_x + 50, 280, i * fiveFourTime_x + 50, 380);
        } else {
            ofDrawLine(i * fiveFourTime_x + 50, 300, i * fiveFourTime_x + 50, 360);
        }
        
        ofSetColor(0);
        if (i % 2 == 0) {
            ofDrawBitmapString(ofToString(fiveFourTime[i]+1), i * fiveFourTime_x + 45, 390);
        } else {
            ofDrawBitmapString(ofToString(fiveFourTime[i]+1), i * fiveFourTime_x + 45, 405);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
