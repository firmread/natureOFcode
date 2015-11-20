#include "Tree.h"
#include <iostream>

Tree::Tree(float len, float ang, ofPoint _startPoint)
{

    maxLength = len;
    startPoint =  _startPoint;
    minLength = 20.0;
    angle = ang;
    nextLengthMultiplier = 0.9;

    ofPoint trunkEnd = ofPoint(startPoint.x,startPoint.y - maxLength);
    Branch trunk = Branch(maxLength,trunkEnd, this,-1);
    branches.push_back(trunk);
}

void Tree::display()
{

    for (std::vector<Branch>::iterator it = branches.begin() ; it != branches.end(); ++it)
    {
        ofPoint ep = (*it).getEndPoint();

        int pPos = (*it).getParentPosition();

        ofPoint sp = startPoint;
        if(pPos>-1)
        {
            Branch thisParent = branches[pPos];
            sp = thisParent.getEndPoint();
        }

        ofSetColor(0,0,0);
        ofSetLineWidth(2.0);
        ofLine(sp.x,sp.y,ep.x,ep.y);
        ofSetColor(255,0,0);
        ofCircle(ep.x,ep.y,2);
    }

}

/*
* Would have preferred to pass in the Branch itself to the constructor of the next branch, but has having issues with this
* so ended up just passing in the position of the current branch in the branches vector so that each branch tracks position of it's parent
*/
Tree::Branch::Branch(float _length, ofPoint _endPoint, Tree* t,int _parentPos)
{
    length = _length;
    endPoint = _endPoint;
    // parent = p;
    parentPos = _parentPos;

    // Create a normalised vector pointing in the direction of the previous branch - if no previous just assume to be pointing directly up
    ofPoint previousDirection = ofPoint(0,-1);
    if(parentPos>-1)
    {
        Branch thisParent = t->branches[parentPos];
        previousDirection = endPoint - thisParent.getEndPoint();
        previousDirection.normalize();
        // std::cout << "Parent: x " << pep.x << std::endl;
    }

    // std::cout << "Branch Length: " << length << " x: " << endPoint.x << " y: " << endPoint.y << std::endl;
    t->branches.push_back(*this);
    float nextLength = length * t->nextLengthMultiplier;

    int thisPosition = t->branches.size() - 1; // Pass this down to child branches to keep track of parent position in vector

    if(nextLength >= t->minLength)
    {
        nextBranch(t,previousDirection,nextLength,t->angle,thisPosition);
        nextBranch(t,previousDirection,nextLength,t->angle * -1, thisPosition);
    }
}


void Tree::Branch::nextBranch(Tree* t,ofPoint previousDirection,float nextLength, float ang, int parentPosition)
{
    ofPoint nextEndPoint = previousDirection * nextLength;
    nextEndPoint.rotate(ang);
    nextEndPoint += endPoint;
    Branch(nextLength,nextEndPoint,t,parentPosition);
}


ofPoint Tree::Branch::getEndPoint()
{
    return endPoint;
}

/*
ofPoint Tree::Branch::getParentEndPoint()
{
    return parent->getEndPoint();
}
Tree::Branch Tree::Branch::getParent()
{
    return *parent;
}
*/

