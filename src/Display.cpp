
#include <iostream>
#include "Display.h"
#include <iostream>
Display::Display(int size)
        : m_rows(size), m_cols(size) {
    m_window.create(sf::VideoMode::getDesktopMode(), "CircleTheCat");
    auto radius = float(m_window.getSize().y / (m_rows + 2)) / 2;
    initBtn(radius * 4);
    initShapes(radius);
}

int Display::getUserInput() {
    auto event = sf::Event{};
    while (true) {
        if (m_window.waitEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    exit(EXIT_SUCCESS);
                case sf::Event::MouseButtonReleased:
                    auto cords = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                    for (int i = 0; i < m_nodesShape.size(); ++i)
                        if (m_nodesShape[i].getGlobalBounds().contains(cords)) return i;
                    if (m_undoSprite.getGlobalBounds().contains(cords))return -1;
                    break;

            }
        }
    }

}

void Display::setNodeType(int id, int type) {
    m_nodes[id] = type;
    setShapeColorByType(m_nodesShape[id], type);
}

void Display::update() {
    m_window.clear(sf::Color(255, 189, 89, 255));
    for (auto& shape : m_nodesShape) {
        m_window.draw(shape);
    }
    m_window.draw(m_undoSprite);
    m_window.draw(m_catSprite);
    m_window.draw(m_clickCountSprite);
    m_window.draw(m_text);
    m_window.display();

}

void Display::initShapes(float radius) {
    m_catTexture.loadFromFile("resources/cat.png");//in mac: "../resources/cat.png");
    m_catSprite.setTexture(m_catTexture);
    m_catSprite.scale(radius * 2 / m_catSprite.getGlobalBounds().width,
                      radius * 2 / m_catSprite.getGlobalBounds().height);

    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            m_nodesShape.push_back(sf::CircleShape(radius, 6));
            initShape(m_nodesShape.back(), {col, row}, radius);
        }
    }


}

void Display::setShapeColorByType(sf::CircleShape &shape, int type) {

    if (type == Blocked)shape.setFillColor(sf::Color(255, 22, 22, 255));
    else {
        if (type == Cat) m_catSprite.setPosition(shape.getPosition());
        shape.setFillColor(sf::Color(255, 222, 89, 255));
    }
}

void Display::init(std::vector<int> gameGraph) {
    m_nodes = gameGraph;
    for (int i = 0; i < m_nodesShape.size(); ++i) {
        setShapeColorByType(m_nodesShape[i], m_nodes[i]);
    }
}

void Display::initShape(sf::CircleShape &shape, sf::Vector2<int> index, float radius) {
    auto xSize = sqrt(3) * radius;
    auto thickness = radius / 2;
    shape.setPosition(xSize + index.x * (xSize + thickness) + index.y % 2 * (xSize + thickness) / 2,
                      xSize + index.y * radius * 2 + thickness);
    shape.setOutlineThickness(thickness / 4);
    shape.setOutlineColor(sf::Color(0, 74, 173, 255));

}

void Display::initBtn(float size) {
    m_undoTexture.loadFromFile("resources/undo.png");
    m_undoSprite.setTexture(m_undoTexture);
    initSprite(m_undoSprite, size, {m_window.getSize().x - (2 * size), size});
    m_clickCountTexture.loadFromFile("resources/clickCount.png");
    m_clickCountSprite.setTexture(m_clickCountTexture);
    initSprite(m_clickCountSprite, size, {m_window.getSize().x - (2 * size), m_window.getSize().y - (2 * size)});
    m_font.loadFromFile("resources/Montserrat-SemiBold.ttf");
    m_text.setFont(m_font);
    initText(m_text, size / 2, m_clickCountSprite.getPosition());
    m_winMsg.setFont(m_font);
    m_winMsg.setString("you won");
    initText(m_winMsg, size, {m_window.getSize().x / float(2), m_window.getSize().y / float(2)});
    m_loseMsg.setFont(m_font);
    m_loseMsg.setString("you lose");
    initText(m_loseMsg, size, {m_window.getSize().x / float(2), m_window.getSize().y / float(2)});
}

void Display::setClickCount(int clickCount) {
    m_clickCount = clickCount;
    m_text.setString(std::to_string(clickCount));
}

void Display::displayEndScreen(bool status) {
    sf::Clock clock;
    while (m_window.isOpen()) {
        sf::Event event{};
        if (clock.getElapsedTime() > m_elapsed) {
            clock.restart();
            break;
        }
        if (m_window.pollEvent(event) && event.type == sf::Event::Closed) {
            m_window.close();
            exit(EXIT_SUCCESS);
        }
        m_window.clear(sf::Color(255, 189, 89, 255));
        status ? m_window.draw(m_winMsg) : m_window.draw(m_loseMsg);
        m_window.display();
    }
}

void Display::initSprite(sf::Sprite &sprite, float size, sf::Vector2<float> position) {
    sprite.scale(size / m_undoSprite.getTextureRect().width, size / m_undoSprite.getTextureRect().height);
    sprite.setOrigin(size / 2, size / 2);
    sprite.setPosition(position);
}

void Display::initText(sf::Text &text, float size, sf::Vector2<float> position) {
    text.setFillColor(sf::Color(0, 74, 173, 255));
    text.setCharacterSize(size);
    text.setOrigin(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2);
    text.setPosition(position);
}


