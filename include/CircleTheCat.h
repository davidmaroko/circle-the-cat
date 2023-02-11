#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <vector>
#include "Node.h"
#include "Graph.h"
#include "Display.h"
#include "GameEnum.h"

class CircleTheCat {
public:

    CircleTheCat(std::vector<Node> vertex, int size, Display& display);

    bool runNewLevel();

private:
    int randomPath();

    void undo();

    int smartPath();

    void playerTurn();

    void moveTheCat(int newPlace);

    bool block(int place);

    void setItem(int loc,int type);

    Graph m_graph;
    Display& m_display;
    int m_cat = 0;
    bool playerVictory = false;
    bool catVictory = false;
    bool noWayOut = false;
    int clickCunt = 0;
    std::vector<int> catHistory;
    std::vector<int> playerHistory;

};