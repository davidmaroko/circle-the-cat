#include "Graph.h"
#include <vector>
#include <queue>


 Node& Graph::getNode(int id)  {
    return m_nodes[id];
}

std::vector<int> Graph::getShortestPath(int src, int type) {
    auto father = std::vector<int>(m_nodes.size());
    for (int i = 0; i < father.size(); ++i) father[i] = i;
    auto destination = bfs(src, type, father);
    auto shortestPath = std::vector<int>();

    while (destination != src) {
        shortestPath.push_back(destination);
        destination = father[destination];
    }
    std::reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

int Graph::bfs(int src, int type, std::vector<int> &father) {
    auto queue = std::queue<int>();
    auto alreadyInQueue = std::vector<bool>(m_nodes.size(), false);
    auto currentNode = src;
    queue.push(currentNode);
    alreadyInQueue[currentNode] = true;
    while (!queue.empty()) {
        for (auto &neighborsId: m_nodes[currentNode].getNeighborsId()) {
            if(m_nodes[neighborsId].status()) {
                if(alreadyInQueue[neighborsId])continue;
                queue.push(neighborsId);
                alreadyInQueue[neighborsId]= true;
                father[neighborsId] = currentNode;
                if (m_nodes[neighborsId].getType() == type)return neighborsId; };
        }
        queue.pop();
        if (!queue.empty())currentNode = queue.front();
    }
    return src;
}
