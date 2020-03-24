#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// load a csv file
	csv.load("Subways.csv");

	string coordsString = csv[1][3];
	coordsString.pop_back();
	string coords = coordsString.substr(7);
	vector<string> latlon = ofSplitString(coords, " ");
	vector<float> latlonF;
	latlonF.push_back(std::stof(latlon.at(0)));
	latlonF.push_back(std::stof(latlon.at(1)));

	// y coord
	cout << latlonF.at(0) << "\n";
	// x coord
	cout << latlonF.at(1) << "\n";

	for (int i = 1; i < csv.getNumRows(); i++) {
		string coordsString = csv[i][3];
		coordsString.pop_back();
		string coords = coordsString.substr(7);
		vector<string> latlon = ofSplitString(coords, " ");
		vector<float> latlonF;
		latlonF.push_back(std::stof(latlon.at(0)));
		latlonF.push_back(std::stof(latlon.at(1)));
		if (latlonF.at(0) < lowY) {
			lowY = latlonF.at(0);
		}
		if (latlonF.at(0) > highY) {
			highY = latlonF.at(0);
		}
		if (latlonF.at(1) < lowX) {
			lowX = latlonF.at(1);
		}
		if (latlonF.at(1) > highX) {
			highX = latlonF.at(1);
		}
	}

	for (int i = 1; i < csv.getNumRows(); i++) {
		string coordsString = csv[i][3];
		coordsString.pop_back();
		string coords = coordsString.substr(7);
		vector<string> latlon = ofSplitString(coords, " ");
		vector<float> latlonF;
		latlonF.push_back(std::stof(latlon.at(0)));
		latlonF.push_back(std::stof(latlon.at(1)));
		
		// y coord
		float xCoord = ofMap(latlonF.at(0), lowY, highY, 0, ofGetWidth());
		// x coord
		float yCoord = ofMap(latlonF.at(1), highX, lowX, 0, ofGetHeight());

		subways.push_back(new Subway(csv[i][2], xCoord, yCoord));
	}

	cout << lowX << "\n";
	cout << highX << "\n";
	cout << lowY << "\n";
	cout << highY << "\n";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0);
	ofFill();
	ofDrawBitmapString(subwayStation, 200, 50);

	for (int i = 0; i < subways.size(); i++) {
		subways[i]->display();
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
	for (int i = 0; i < subways.size(); i++) {
		if (subways[i]->hover(x, y)) {
			subwayStation = subways[i]->name;
		}
	}
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
