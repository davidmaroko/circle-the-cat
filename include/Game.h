#pragma once

#include <vector>
#include "StageGenerator.h"
#include "CircleTheCat.h"
#include <SFML/Graphics.hpp>


class Game {
public:
    void run();

private:
    int m_size = 11;
    int m_levelsNum = 11;
};