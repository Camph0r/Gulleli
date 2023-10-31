#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <functional>

#include "gamemodes.hpp"
#include "../button.hpp"
#include "components.hpp"
#include "highscore.hpp"
#include "window.hpp"
#include "sound.hpp"

#define window Window::window

void homescreen();
void playscreen();
void controls();
void gameover(std::string fire, int mode);
void gulleli_easy();
void gulleli_medium();
void gulleli_hard();
SoundManager audio;

void fire(sf::Sprite &obj, sf::Sprite &aim)
{

    audio.playHit();

    sf::Vector2f endPos = aim.getPosition();
    sf::Vector2f startPos = obj.getPosition();
    sf::Time translationDuration = sf::seconds(2.0f);
    sf::Time elapsedTranslationTime = sf::seconds(0.0f);
    clock1.restart();

    while (elapsedTranslationTime.asSeconds() < translationDuration.asSeconds())
    {
        elapsedTranslationTime += clock1.getElapsedTime();
        float interpolationFactor = elapsedTranslationTime.asSeconds() / translationDuration.asSeconds();
        obj.setPosition(startPos + (endPos - startPos) * interpolationFactor);
    }
};

void playscreen()
{
    sf::Font font_heading, font_n;

    if (!font_heading.loadFromFile("Resources/font/Freedom.ttf"))
    {
        std::cout << "Cannot load font ";
    }
    sf::Text heading, easy, medium, hard, back;
    heading.setFont(font_heading);
    heading.setCharacterSize(60);
    heading.setString("Difficulty level");
    heading.setPosition(sf::Vector2f(230, 100));

    if (!font_n.loadFromFile("Resources/font/arial.ttf"))
    {
        std::cout << "Cannot load font ";
    }

    sf::Texture background;

    easy.setFont(font_n);
    easy.setCharacterSize(30);
    easy.setString("Easy");
    easy.setPosition(sf::Vector2f(450, 400));

    medium.setFont(font_n);
    medium.setCharacterSize(30);
    medium.setString("Medium");
    medium.setPosition(sf::Vector2f(420, 500));

    hard.setFont(font_n);
    hard.setCharacterSize(30);
    hard.setString("Hard");
    hard.setPosition(sf::Vector2f(420, 600));

    back.setFont(font_n);
    back.setCharacterSize(30);
    back.setString("Back");
    back.setPosition(sf::Vector2f(10, 10));

    background.loadFromFile("Resources/img/image.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    Button button_easy(sf::Vector2f(390, 400), sf::Vector2f(200, 50), "Easy", gulleli_easy);
    Button button_medium(sf::Vector2f(390, 500), sf::Vector2f(200, 50), "Medium", gulleli_medium);
    Button button_hard(sf::Vector2f(390, 600), sf::Vector2f(200, 50), "Hard", gulleli_hard);
    Button button_back(sf::Vector2f(10, 10), sf::Vector2f(70, 50), "Back", homescreen);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            button_easy.handle_event(window, event);
            button_medium.handle_event(window, event);
            button_hard.handle_event(window, event);
            button_back.handle_event(window, event);
        }

        window.clear();
        window.draw(backgroundSprite);

        button_easy.draw(window);

        button_hard.draw(window);
        button_medium.draw(window);
        button_back.draw(window);
        window.draw(heading);
        window.draw(easy);
        window.draw(medium);
        window.draw(hard);
        window.draw(back);

        window.display();
    }
}

void controls()
{
    sf::Font font_heading, font_n;
    if (!font_heading.loadFromFile("Resources/font/Freedom.ttf"))
    {
        std::cout << "Cannot load font ";
    }
    sf::Text heading, back, howToPlay;
    sf::RectangleShape howto;
    howto.setPosition(sf::Vector2f(100, 200));
    howto.setFillColor(sf::Color(51, 203, 172, 220));
    howto.setSize(sf::Vector2f(770, 400));
    heading.setFont(font_heading);
    heading.setCharacterSize(60);
    heading.setString("Controls");
    heading.setPosition(sf::Vector2f(230, 100));

    howToPlay.setFont(font_n);
    howToPlay.setCharacterSize(30);
    howToPlay.setString(" Click right mouse button and move the mouse to control \n the aim's position. Click left mouse button to fire ball \n toward aimed direction. Hit the bird's eye with bullets \n to earn points.");
    howToPlay.setPosition(sf::Vector2f(100, 200));

    back.setFont(font_n);
    back.setCharacterSize(30);
    back.setString("Back");
    back.setPosition(sf::Vector2f(10, 10));
    Button button_back(sf::Vector2f(10, 10), sf::Vector2f(70, 50), "Back", homescreen);

    if (!font_n.loadFromFile("Resources/font/arial.ttf"))
    {
        std::cout << "Cannot load font ";
    }

    sf::Texture background;

    background.loadFromFile("Resources/img/image.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            button_back.handle_event(window, event);
        }

        window.clear();
        window.draw(backgroundSprite);

        button_back.draw(window);
        window.draw(back);
        window.draw(heading);

        window.draw(howto);
        window.draw(howToPlay);
        window.display();
    }
}

void gameover(std::string fire, int mode)
{
    audio.stopMusic();
    audio.playSound();
    HighScore hs(mode);
    int scores = std::stoi(fire);
    hs.handleFile(scores);
    window.setMouseCursorVisible(true);
    sf::Font font_heading, font_n;

    if (!font_heading.loadFromFile("Resources/font/Freedom.ttf"))
    {
        std::cout << "Cannot load font ";
    }
    sf::Text heading, back, text_score, text_highscore, score_count, highscore_count;
    heading.setFont(font_heading);
    heading.setCharacterSize(70);
    heading.setString("Game Over");
    heading.setPosition(sf::Vector2f(230, 100));

    if (!font_n.loadFromFile("Resources/font/arial.ttf"))
    {
        std::cout << "Cannot load font ";
    }

    sf::Texture background;

    back.setFont(font_heading);
    back.setCharacterSize(30);
    back.setString("Back");
    back.setPosition(sf::Vector2f(440, 465));

    background.loadFromFile("Resources/img/image.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);

    Button button_back(sf::Vector2f(430, 460), sf::Vector2f(100, 50), "Back", homescreen);

    text_score.setFont(font_heading);
    text_score.setCharacterSize(45);
    text_score.setString("Your score");
    text_score.setPosition(sf::Vector2f(150, 200));

    text_highscore.setFont(font_heading);
    text_highscore.setCharacterSize(45);
    text_highscore.setString("High score");
    text_highscore.setPosition(sf::Vector2f(550, 200));

    score_count.setFont(font_n);
    score_count.setCharacterSize(50);
    score_count.setString(fire);
    score_count.setPosition(sf::Vector2f(250, 300));

    highscore_count.setFont(font_n);
    highscore_count.setCharacterSize(50);
    highscore_count.setString(std::to_string(hs.getHighscore()));
    highscore_count.setPosition(sf::Vector2f(650, 300));

    if (hs.isHighScore)
    {
        audio.playHighScore();
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            button_back.handle_event(window, event);
        }

        window.clear();
        window.draw(backgroundSprite);

        button_back.draw(window);
        window.draw(heading);

        window.draw(back);
        window.draw(score_count);
        window.draw(highscore_count);
        window.draw(text_highscore);
        window.draw(text_score);
        window.display();
    }
}
