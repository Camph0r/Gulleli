#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class Button
{
private:
    sf::RectangleShape m_shape;
    std::string m_text;
    std::function<void()> m_onClick;
    bool m_isHovered;

public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string s, std::function<void()> onClick);
    void handle_event(sf::RenderWindow &window, sf::Event &m_event);
    void draw(sf::RenderWindow &window);
    bool isHovered() const;
};
