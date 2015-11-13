#include "Connection.h"

Connection::Connection(Neuron* from, Neuron* to,float w)
{
    weight = w;
    a = from;
    b = to;
}

void Connection::display()
{
    ofSetColor(0,0,0,255);
    ofSetLineWidth(weight*10);

    ofVec2f aLocation = a->getLocation();
    ofVec2f bLocation = b->getLocation();
    //std::cout << "Locations: " << aLocation.x << " " << aLocation.y << std::endl;
    ofLine(aLocation.x, aLocation.y, bLocation.x, bLocation.y);
    if(sending) {
        ofCircle(sender.x, sender.y, 8);
    }
}

void Connection::feedforward(float val)
{
    sending = true;
    //Start the animation at the location of Neuron A.
    sender =  a->getLocation();
    //Store the output for when it is actually time to feed it forward.
    output = val*weight;
}



void Connection::update()
{
    if (sending)
    {
        //As long as we’re sending, interpolate our points.
        ofVec2f bLocation = b->getLocation();
        sender.x = ofLerp(sender.x, bLocation.x, 0.1);
        sender.y = ofLerp(sender.y, bLocation.y, 0.1);

        float d = sender.distance(bLocation);

        // If we’re close enough (within one pixel) pass on the output. Turn off sending.
        if (d < 1)
        {
            b->feedforward(output);
            sending = false;
        }
    }

}


