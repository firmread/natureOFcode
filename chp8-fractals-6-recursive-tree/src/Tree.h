#include <vector>
#include "ofMain.h"

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree
{

private:

    ofVec2f startPoint;
    float maxLength;
    float minLength;
    float angle;
    float nextLengthMultiplier;

    class Branch
    {
    friend class Tree;

    public:

        Branch() {};
        Branch(float _length,ofVec2f _endPoint, Tree* t, int parentPos);
        ofVec2f getEndPoint();
        ofVec2f endPoint;
        //ofVec2f getParentEndPoint();
        Branch getParent();
        int getParentPosition() { return parentPos; };
        void nextBranch(Tree* t,ofVec2f previousDirection,float nextLength, float ang, int parentPosition);

        // Branch * parent;
        int parentPos;

    private:

        float length;

    };

public:

    Tree() {};
    Tree(float len, float ang, ofVec2f startPoint);
    void display();

    vector<Branch> branches;

};

#endif // TREE_H_INCLUDED
