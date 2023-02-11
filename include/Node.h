#pragma once

#include <vector>

class Node {
public:
    Node(int id, int type, std::vector<int> neighbors)
            : m_id(id), m_type(type), m_neighbors(neighbors) {}

    int getId() const;

    void setType(int);

    int getType() const;

    const std::vector<int> getNeighborsId() const;

    void setNeighbors(std::vector<int> neighbors);

    void disable();

    void enable();

    bool status() const;

private:
    int m_id;
    int m_type;
    bool m_status = true;
    std::vector<int> m_neighbors;

};


