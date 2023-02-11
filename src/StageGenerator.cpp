#include <time.h>
#include <cmath>
#include "StageGenerator.h"

StageGenerator::StageGenerator(int size)
        : m_rows(size), m_cols(size) { srand(time(nullptr)); }

std::vector<Node> StageGenerator::getStage(int stage) {
    auto newStage = creatEmptyStage();
    generate(newStage, stage);
    return newStage;
}

void StageGenerator::generate(std::vector<Node> &stage, int stageNum) {
    auto catIndex = std::floor(m_cols / 2)
                    * m_cols + std::floor(m_rows / 2);

    stage[catIndex].setType(Cat);


    for (auto &node: stage) {
        if (node.getId() < m_cols)
            stage[node.getId()].setType(Margin);
        if (node.getId() >= m_cols * m_rows - m_cols)
            stage[node.getId()].setType(Margin);
        if (node.getId() % m_cols == 0)
            stage[node.getId()].setType(Margin);
        if ((node.getId() + 1) % m_cols == 0)
            stage[node.getId()].setType(Margin);
    }
    auto v = std::vector<Node>();
    for (int i = 14; i > stageNum ; --i) {
        int blockedIndex;
        do {
            blockedIndex = rand() % (m_cols * m_rows);
        } while (blockedIndex == catIndex);
        stage[blockedIndex].setType(Blocked);
        stage[blockedIndex].disable();
    v.push_back( stage[blockedIndex]);
    }
}

std::vector<Node> StageGenerator::creatEmptyStage() {
    auto newStage = std::vector<Node>();
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            auto index = row * m_cols + col;
            auto neighbors = std::vector<int>();
            if (row % 2 == 0) {
                if (col == 0) {
                    //R
                    if (index + 1 < m_cols * m_rows)neighbors.push_back(index + 1);
                    //UP R
                    if (index - m_cols >= 0)neighbors.push_back(index - m_cols);
                    //DOWN R
                    if (index + m_cols < m_cols * m_rows)neighbors.push_back(index + m_cols);
                }

                if (col == m_cols - 1) {
                    //L
                    if (index - 1 >= 0)neighbors.push_back(index - 1);
                    //UP L
                    if (index - (m_cols + 1) >= 0)neighbors.push_back(index - (m_cols + 1));
                    //UP R
                    if (index - m_cols >= 0)neighbors.push_back(index - m_cols);
                    //DOWN L
                    if (index + (m_cols - 1) < m_cols * m_rows)neighbors.push_back(index + (m_cols - 1));
                    //DOWN R
                    if (index + m_cols < m_cols * m_rows)neighbors.push_back(index + m_cols);
                } else {
                    //L
                    if (index - 1 >= 0)neighbors.push_back(index - 1);
                    //R
                    if (index + 1 < m_cols * m_rows)neighbors.push_back(index + 1);
                    //UP L
                    if (index - (m_cols + 1) >= 0)neighbors.push_back(index - (m_cols + 1));
                    //UP R
                    if (index - m_cols >= 0)neighbors.push_back(index - m_cols);
                    //DOWN L
                    if (index + (m_cols - 1) < m_cols * m_rows)neighbors.push_back(index + (m_cols - 1));
                    //DOWN R
                    if (index + m_cols < m_cols * m_rows)neighbors.push_back(index + m_cols);
                }

            }
            else {
                if (col == 0) {

                    //R
                    if (index + 1 < m_cols * m_rows)neighbors.push_back(index + 1);
                    //UP L
                    if (index - m_cols >= 0)neighbors.push_back(index - m_cols);
                    //UP R
                    if (index - (m_cols - 1) >= 0)neighbors.push_back(index - (m_cols - 1));
                    //DOWN L
                    if (index + m_cols < m_cols * m_rows)neighbors.push_back(index + m_cols);
                    //DOWN R
                    if (index + m_cols + 1 < m_cols * m_rows)neighbors.push_back(index + m_cols + 1);
                }

                if (col == m_cols - 1) {
                    //L
                    if (index - 1 >= 0)neighbors.push_back(index - 1);
                    //UP L
                    if (index - m_cols >= 0)neighbors.push_back(index - m_cols);
                    //DOWN L
                    if (index + m_cols < m_cols * m_rows)neighbors.push_back(index + m_cols);
                } else {
                    //L
                    if (index - 1 >= 0)neighbors.push_back(index - 1);
                    //R
                    if (index + 1 < m_cols * m_rows)neighbors.push_back(index + 1);
                    //UP L
                    if (index - m_cols >= 0)neighbors.push_back(index - m_cols);
                    //UP R
                    if (index - (m_cols - 1) >= 0)neighbors.push_back(index - (m_cols - 1));
                    //DOWN L
                    if (index + m_cols < m_cols * m_rows)neighbors.push_back(index + m_cols);
                    //DOWN R
                    if (index + m_cols + 1 < m_cols * m_rows)neighbors.push_back(index + m_cols + 1);
                }
            }
            newStage.push_back(Node(row * m_cols + col, Empty, neighbors));
        }
    }


    return newStage;
}

