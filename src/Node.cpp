#include "Node.h"

int Node::getId() const { return m_id; }

const std::vector<int> Node::getNeighborsId() const { return m_neighbors; }

void Node::setNeighbors(std::vector<int> neighbors) { m_neighbors = neighbors; }

bool Node::status() const { return m_status; }

void Node::disable() { m_status = false; }

void Node::enable() { m_status = true; }

void Node::setType(int type) { m_type = type; }

int Node::getType() const { return m_type; }



