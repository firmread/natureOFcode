#pragma once

#include "ofMain.h"

class Walker {
  private:
    glm::vec2 m_position;
    int m_radius;

    void step();
    void keepInBounds();

  public:
    void setup(const glm::vec2& position, int radius = 1);
    void update();
    void draw();

    const glm::vec2& getPosition() { return m_position; }
    void setPosition(const glm::vec2& position) { m_position = position; }
};

