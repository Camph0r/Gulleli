#include <SFML/Graphics.hpp>
#include "Headers/canvas.hpp"
#include <SFML/Audio.hpp>
#include "button.hpp"
#include "Headers/window.hpp"
#include "Headers/sound.hpp"
#include <iostream>
#include <functional>
#include <iostream>
void homescreen();

void playscreen();
void controls();

int main()
{
    homescreen();

    return 0;
}

void homescreen()
{
    sf::Font font_heading, font_n;
    if (!font_heading.loadFromFile("Resources/font/Freedom.ttf"))
    {
        std::cout << "Cannot load font ";
    }
    sf::Text heading, play, controls_t;
    heading.setFont(font_heading);
    heading.setCharacterSize(100);
    heading.setString("Gulleli");
    heading.setPosition(sf::Vector2f(230, 100));

    if (!font_n.loadFromFile("Resources/font/arial.ttf"))
    {
        std::cout << "Cannot load font ";
    }

    sf::Texture background;

    play.setFont(font_n);
    play.setCharacterSize(30);
    play.setString("Play");
    play.setPosition(sf::Vector2f(450, 460));

    controls_t.setFont(font_n);
    controls_t.setCharacterSize(30);
    controls_t.setString("Controls");
    controls_t.setPosition(sf::Vector2f(420, 560));

    background.loadFromFile("Resources/img/image.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    Button button_play(sf::Vector2f(390, 460), sf::Vector2f(200, 50), "Play", playscreen);
    Button button_control(sf::Vector2f(390, 560), sf::Vector2f(200, 50), "Controls", controls);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            button_play.handle_event(window, event);
            button_control.handle_event(window, event);
        }

        window.clear();
        window.draw(backgroundSprite);

        button_play.draw(window);

        button_control.draw(window);
        window.draw(heading);
        window.draw(play);
        window.draw(controls_t);

        window.display();
    }
}