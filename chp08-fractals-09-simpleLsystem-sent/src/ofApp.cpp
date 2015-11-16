#include "ofApp.h"

void outputCurrent(int cnt, string current)
{
    std::stringstream ss;
    ss << "Generation " << cnt << ": " << current << std::endl;
    std::cout << ss.str();
}

//--------------------------------------------------------------
void ofApp::setup()
{
    current = "A";
    cnt = 0;
    outputCurrent(cnt,current);

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    string next = "";

    //Traverse the current String and make the new one.
    for (int i = 0; i < current.length(); i++)
    {
        char c = current.at(i);
        if (c == 'A')
        {
            next += "AB";
        }
        else if (c == 'B')
        {
            next += "A";
        }
    }
    current = next;
    cnt++;
    outputCurrent(cnt,current);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
