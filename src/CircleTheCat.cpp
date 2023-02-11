#include "CircleTheCat.h"


CircleTheCat::CircleTheCat(std::vector<Node> vertex, int size, Display &display)
        : m_graph(vertex), m_display(display) {
    auto displayVec = std::vector<int>();
    for (auto &node: vertex) {
        displayVec.push_back(node.getType());
        if (node.getType() == Cat)m_cat = node.getId();
    }
    m_display.init(displayVec);
}

bool CircleTheCat::runNewLevel() {


    while (true) {
        m_display.update();
        if (catVictory) {
            m_display.displayEndScreen(false);
            return false;
        }
        if (playerVictory) {
            m_display.displayEndScreen(true);
            return true;
        }
        playerTurn();
        m_display.update();
        moveTheCat(noWayOut ? randomPath() : smartPath());
    }
}


void CircleTheCat::playerTurn() {
    while (true) {
        auto input = m_display.getUserInput();
        if (input == -1) {
            undo();
            continue;
        }
        if (block(input)) {
            break;
        }
    }
}


void CircleTheCat::moveTheCat(int newPlace) {
    setItem(m_cat, Empty);
    catHistory.push_back(m_cat);
    m_cat = newPlace;
    setItem(m_cat, Cat);
}

bool CircleTheCat::block(int newPlace) {
    auto currentStatus = m_graph.getNode(newPlace).getType();
    if (currentStatus == Cat || currentStatus == Blocked)return false;
    setItem(newPlace, Blocked);
    m_graph.getNode(newPlace).disable();
    playerHistory.push_back(newPlace);
    ++clickCunt;
    m_display.setClickCount(clickCunt);
    return true;
}


int CircleTheCat::randomPath() {
    auto path = m_cat;
    auto vec = m_graph.getNode(m_cat).getNeighborsId();
    for (int neighborId: vec) {
        if (m_graph.getNode(neighborId).getType() == Blocked)continue;
        path = neighborId;
    }
    playerVictory = (path == m_cat);//there is no path
    return path;
}

int CircleTheCat::smartPath() {
    auto vec = m_graph.getShortestPath(m_cat, Margin);
    if (vec.empty()) {
        noWayOut = true;
        return randomPath();
    }
    catVictory = (m_graph.getNode(vec.front()).getType() == Margin);
    return vec.front();
}

void CircleTheCat::undo() {
    if (catHistory.empty() || playerHistory.empty())return;
    setItem(m_cat, Empty);
    m_cat = catHistory.back();
    catHistory.pop_back();
    setItem(m_cat, Cat);

    setItem(playerHistory.back(), Empty);
    m_graph.getNode(playerHistory.back()).enable();
    playerHistory.pop_back();
    --clickCunt;
    m_display.setClickCount(clickCunt);
    m_display.update();
    if (noWayOut)noWayOut = false;
}

void CircleTheCat::setItem(int loc, int type) {
    m_graph.getNode(loc).setType(type);
    m_display.setNodeType(loc, type);
}

