#pragma once

#include <vector>
#include <cmath>
#include "GameEnum.h"
#include <queue>
#include <SFML/Graphics.hpp>

class Display {
public:
    Display(int size);

    void init(std::vector<int> gameGraph);

    void setNodeType(int id, int type);

    void update();

    int getUserInput();

    void setClickCount(int);

    void displayEndScreen(bool);

private:

    void initShapes(float);

    void initShape(sf::CircleShape &, sf::Vector2<int>, float);

    void initBtn(float);

    void setShapeColorByType(sf::CircleShape &, int);

    void initText(sf::Text &text, float size, sf::Vector2<float> position);

    void initSprite(sf::Sprite &sprite, float size, sf::Vector2<float> position);

    sf::RenderWindow m_window;
    int m_rows, m_cols, m_clickCount;
    std::vector<int> m_nodes;
    std::vector<sf::CircleShape> m_nodesShape;
    sf::Texture m_catTexture, m_undoTexture, m_clickCountTexture;
    sf::Sprite m_catSprite, m_undoSprite, m_clickCountSprite;
    sf::Font m_font;
    sf::Text m_text, m_winMsg,m_loseMsg;
    sf::Time m_elapsed = sf::milliseconds(5000);



};