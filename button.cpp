#include "button.hpp"
#include <thread>

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string s, std::function<void()> onClick)
    : m_shape(size), m_onClick(onClick), m_text(s), m_isHovered(false)
{
    m_shape.setPosition(position);
    m_shape.setFillColor(sf::Color(247, 103, 72, 150));
}

void Button::handle_event(sf::RenderWindow &window, sf::Event &m_event)
{
    if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(m_event.mouseButton.x, m_event.mouseButton.y));
        if (m_shape.getGlobalBounds().contains(mousePos))
        {
            
            m_onClick();
        }
    }
    if (m_event.type == sf::Event::MouseMoved)
    {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(m_event.mouseMove.x, m_event.mouseMove.y));
        if (m_shape.getGlobalBounds().contains(mousePos))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            m_shape.setFillColor(sf::Color(100, 150, 112, 150));
        }
        else
        {
            m_shape.setFillColor(sf::Color(247, 103, 72, 150));
        }
    }
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(m_shape);
}

bool Button::isHovered() const
{
    return m_isHovered;
}
