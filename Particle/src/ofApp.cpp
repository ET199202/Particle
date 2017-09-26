#include "ofApp.h"
#include <vector>

struct Particle {
	float x, y, radius, vx, vy;
	int r, g, b;
	bool f;

	void draw() {
		ofSetColor(r, g, b);
		ofCircle(x, y, radius);
	}

	void update() {
		this->x += vx;
		this->y += vy;
		vy += 0.05;
	}
};

static const int N = 1000;
int W, H;
Particle particles[N];
bool mouse_pressed;


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0); // �w�i�F�ݒ�(r,g,b)
	ofSetBackgroundAuto(false); // �w�i�̎����h��Ԃ�������
	ofEnableAlphaBlending(); // �A���t�@�`�����l����L��
	ofSetCircleResolution(64); // �~�̉𑜓x�̐ݒ�
	ofSetFrameRate(60); // frameRate�̐ݒ�

	W = ofGetWidth(); // window�T�C�Y�̕����擾
	H = ofGetHeight(); // window�T�C�Y�̍������擾

	mouse_pressed = false; // mousePressed�̏����l�ݒ�

	for (int i = 0; i < N; i++) {
		Particle p;
		p.r = ofRandom(0, 255);
		p.g = ofRandom(0, 255);
		p.b = ofRandom(0, 255);
		p.draw();
		p.f = false;
		particles[i] = p;
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// �O�Ղ��c�����ߔ������ȍ����l�p�`�œh��Ԃ�
	ofSetColor(0, 0, 0, 23);
	ofRect(0, 0, W, H);
	for (int i = 0; i < N; i++) {
		if (particles[i].f)particles[i].draw();
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
	mouse_pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mouse_pressed = false;
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
