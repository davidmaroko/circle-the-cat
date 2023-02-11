#include "Game.h"


void Game::run() {
    auto display = Display(m_size);
    auto stagesGenerator = StageGenerator(m_size);


    auto stageNum = 0;
    while (stageNum < m_levelsNum) {
        CircleTheCat newGame(stagesGenerator.getStage(stageNum), m_size , display);
        if (newGame.runNewLevel())++stageNum;
    }
}



