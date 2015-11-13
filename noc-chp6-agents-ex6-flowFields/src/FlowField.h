#ifndef FLOWFIELD_H_INCLUDED
#define FLOWFIELD_H_INCLUDED
#include <vector>

class FlowField
{

public:

    FlowField() {}
    FlowField(int resolutionn);
    void displayFlowField();
    void drawArrow(float);

private:

    std::vector<float> field;
    int cols, rows;
    int resolution;           //Resolution of grid relative to window width and height in pixels

};


/*
* Was going to have an arrow object and put them in the vector, but decided to go with simpler option for time being
*
class Arrow
{
public:
    Arrow() {};
    Arrow(float len);
private:
    float length;
    float angle;
};
*/

#endif // FLOWFIELD_H_INCLUDED
