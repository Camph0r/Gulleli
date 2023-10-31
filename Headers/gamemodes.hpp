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
sf::RenderWindow &window = Window::window;
sf::Vector2f &centerPosition = Window::centerPosition;
sf::Clock clock1;
SoundManager audio1;

void gulleli_easy()

{
    window.setFramerateLimit(60);
  



    Guleli guleliC;
    Background bgC;
    Ball ballC;
    Rubber rubberC;
    Bird birdC;
    Aim aimC;

    sf::Sprite &guleli_object = guleliC.getGuleli();
    sf::Sprite &bg = bgC.getBackground();
    sf::Sprite &ball_object = ballC.getBall();
    sf::Sprite &rubber_object = rubberC.getRubber();
    sf::Sprite &bird_object = birdC.getBird();
    sf::Sprite &aim_object = aimC.getAim();

    clock1.restart();
    window.setMouseCursorVisible(false);
    audio1.playMusic();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
           

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                rubberC.elongate(window);
                if ((event.mouseMove.x || event.mouseMove.y) && window.hasFocus())
                {
                    ballC.moveBall(rubberC);
                    aimC.moveAim(window);
                };
            };
            sf::FloatRect aimBoundary = aimC.getAim().getGlobalBounds();

            birdC.check_boundary(aimBoundary, ballC, aimC, 0);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            };
        };

      
        if (clock1.getElapsedTime().asSeconds() > 0.07f)
        {

            birdC.animateBird();
            clock1.restart();
        }

        window.clear();
        window.draw(bg);
        window.draw(bird_object);
        window.draw(guleli_object);
        window.draw(rubber_object);
        window.draw(ball_object);
        window.draw(aim_object);

        window.display();
    }
}

void gulleli_medium()
{
    window.setFramerateLimit(60);
    Guleli guleliC;
    Background bgC;
    Ball ballC;
    Rubber rubberC;
    Bird_medium birdC;
    Aim aimC;

    sf::Sprite &guleli_object = guleliC.getGuleli();
    sf::Sprite &bg = bgC.getBackground();
    sf::Sprite &ball_object = ballC.getBall();
    sf::Sprite &rubber_object = rubberC.getRubber();
    sf::Sprite &bird_object = birdC.getBird();
    sf::Sprite &aim_object = aimC.getAim();

    clock1.restart();
    window.setMouseCursorVisible(false);
    audio1.playMusic();

    int fire_count = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                rubberC.elongate(window);
                if ((event.mouseMove.x || event.mouseMove.y) && window.hasFocus())
                {
                    ballC.moveBall(rubberC);
                    aimC.moveAim(window);
                };
            };
            sf::FloatRect aimBoundary = aimC.getAim().getGlobalBounds();

            birdC.check_boundary(aimBoundary, ballC, aimC, 1);
           

            if (event.type == sf::Event::Closed)
            {
                window.close();
            };
        };

     
        if (clock1.getElapsedTime().asSeconds() > 0.07f)
        {

            birdC.animateBird();
            clock1.restart();
        }

        window.clear();
        window.draw(bg);
        window.draw(bird_object);
        window.draw(guleli_object);

        window.draw(rubber_object);
        window.draw(ball_object);
        window.draw(aim_object);

        window.display();
    }
}

void gulleli_hard()
{
    window.setFramerateLimit(60);
    Bird_Hard birdC(5);
    Guleli guleliC;
    Background bgC;
    Ball ballC;
    Rubber rubberC;
    Aim aimC;

    sf::Sprite &guleli_object = guleliC.getGuleli();
    sf::Sprite &bg = bgC.getBackground();
    sf::Sprite &ball_object = ballC.getBall();
    sf::Sprite &rubber_object = rubberC.getRubber();
    sf::Sprite &aim_object = aimC.getAim();

    clock1.restart();
    window.setMouseCursorVisible(false);
    audio1.playMusic();

    int fire_count = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            rubberC.elongate(window);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && window.hasFocus())
        {
            ballC.moveBall(rubberC);
            aimC.moveAim(window);
        }

        sf::FloatRect aimBoundary = aimC.getAim().getGlobalBounds();
        birdC.check_boundary(aimBoundary, ballC, aimC, 2);

        if (clock1.getElapsedTime().asSeconds() > 0.07f)
        {
            birdC.animate();
            clock1.restart();
        }

        window.clear();
        window.draw(bg);
        window.draw(guleli_object);
        window.draw(rubber_object);
        birdC.draw();
        window.draw(ball_object);
        window.draw(aim_object);
        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }
}