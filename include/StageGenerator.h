#pragma once
#include "GameEnum.h"
#include "Node.h"

class StageGenerator {
public:
    StageGenerator(int size);

    std::vector<Node> getStage(int stage);

private:
    std::vector<Node> creatEmptyStage();
    void generate(std::vector<Node>&,int);
    int m_rows,m_cols;
};