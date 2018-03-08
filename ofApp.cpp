#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	int size = 60;

	for (int x = size / 2; x < ofGetWidth() + size / 2; x += size) {

		for (int y = size / 2; y < ofGetHeight() + size / 2; y += size) {

			ofPoint point = ofPoint(x, y);
			float radius = (size * 0.5) * 0.8;
			ofNoFill();
			this->draw_circle(point, radius);

			float mini_radius = radius * 0.25;
			float mini_deg = ofNoise(x * 0.001, y * 0.001 - ofGetFrameNum() * 0.01) * 720;
			ofPoint mini_point = point + ofPoint(radius * cos(mini_deg * DEG_TO_RAD), radius * sin(mini_deg * DEG_TO_RAD));
			ofFill();
			this->draw_circle(mini_point, mini_radius);

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_circle(ofPoint point, float radius) {

	ofPushMatrix();
	ofTranslate(point);

	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 1) {

		ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	ofEndShape();

	ofPopMatrix();
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}