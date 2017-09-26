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
	ofBackground(0, 0, 0); // 背景色設定(r,g,b)
	ofSetBackgroundAuto(false); // 背景の自動塗りつぶしを解除
	ofEnableAlphaBlending(); // アルファチャンネルを有効
	ofSetCircleResolution(64); // 円の解像度の設定
	ofSetFrameRate(60); // frameRateの設定

	W = ofGetWidth(); // windowサイズの幅を取得
	H = ofGetHeight(); // windowサイズの高さを取得

	mouse_pressed = false; // mousePressedの初期値設定

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
	// 軌跡を残すため半透明な黒い四角形で塗りつぶす
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
