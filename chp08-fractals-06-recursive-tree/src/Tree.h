#include <vector>
#include "ofMain.h"

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree
{

private:

    ofPoint startPoint;
    float maxLength;
    float minLength;
    float angle;
    float nextLengthMultiplier;

    class Branch
    {
    friend class Tree;

    public:

        Branch() {};
        Branch(float _length,ofPoint _endPoint, Tree* t, int parentPos);
        ofPoint getEndPoint();
        ofPoint endPoint;
        //ofPoint getParentEndPoint();
        Branch getParent();
        int getParentPosition() { return parentPos; };
        void nextBranch(Tree* t,ofPoint previousDirection,float nextLength, float ang, int parentPosition);

        // Branch * parent;
        int parentPos;

    private:

        float length;

    };

public:

    Tree() {};
    Tree(float len, float ang, ofPoint startPoint);
    void display();

    vector<Branch> branches;

};

#endif // TREE_H_INCLUDED
