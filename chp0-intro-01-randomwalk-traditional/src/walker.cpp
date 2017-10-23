#include "Walker.h"


void Walker::setup(const glm::vec2& position, int radius) {
  m_position = position;
  m_radius = radius;
}


void Walker::update() {
  step();
  keepInBounds();
}


void Walker::draw() {
  ofDrawCircle(m_position, m_radius);
}


void Walker::step() {
  int choice = ofRandom(4);
  cout << "New step choice: " << choice << "\n";

  if (choice == 0) m_position.x += (m_radius * 2);
  else if (choice == 1) m_position.x -= (m_radius * 2);
  else if (choice == 2) m_position.y += (m_radius * 2);
  else if (choice == 3) m_position.y -= (m_radius * 2);
}


void Walker::keepInBounds() {
  m_position.x = ofClamp(m_position.x, 0.0, ofGetWidth());
  m_position.y = ofClamp(m_position.y, 0.0, ofGetHeight());
}
