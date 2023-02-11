#pragma once

#include <vector>
#include "Node.h"
#include <list>
#include <cmath>
#include <vector>
#include <utility>
#include <set>


class Graph {
public:
    explicit Graph(std::vector<Node> nodes) : m_nodes(nodes) {}

     Node & getNode(int id) ;

    std::vector<int> getShortestPath(int src,int type);

private:
    int bfs(int src, int type, std::vector<int>& father);

    std::vector<Node> m_nodes;
};


