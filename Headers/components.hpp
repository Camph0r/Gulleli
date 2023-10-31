#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <thread>
#include <fstream>
#include "gamemodes.hpp"
#include "components.hpp"
#include "highscore.hpp"
#include "window.hpp"
#include "sound.hpp"

#include <chrono>

void gameover(std::string fire, int mode);
void fire(sf::Sprite &obj, sf::Sprite &aim);
  enum class direction
    {
        minus4,
        minus3,
        minus2,
        minus1,
        zero,
        plus1,
        plus2,
        plus3,
        plus4
    };

    class Textures
    {
    public:
        sf::Texture guleli_t;
        sf::Texture bg;
        sf::Texture ball;
        sf::Texture ball_original;
        sf::Texture rubber;
        sf::Texture aim;

        Textures();
    };

    Textures::Textures()
    {
        if (!guleli_t.loadFromFile("./Resources/img/slingshot.png"))
        {
            std::cout << "texture wasn't loaded"
                      << "\n";
        };
        if (!bg.loadFromFile("./Resources/img/bgE.jpg"))
        {
            std::cout << "background wasn't loaded"
                      << "\n";
        };
        if (!ball.loadFromFile("./Resources/img/bb.png"))
        {
            std::cout << "texture wasn't loaded"
                      << "\n";
        };
        if (!ball_original.loadFromFile("./Resources/img/ball.png"))
        {
            std::cout << "texture wasn't loaded"
                      << "\n";
        };
        if (!rubber.loadFromFile("./Resources/img/rubbers.png"))
        {
            std::cout << "texture wasn't loaded"
                      << "\n";
        };
        rubber.setSmooth(true);
        if (!aim.loadFromFile("./Resources/img/aim2.png"))
        {
            std::cout << "texture wasn't loaded"
                      << "\n";
        };
    };

    Textures textures;

    class Rubber
    {
        sf::Sprite rubber_object;
        sf::Vector2f rubberScaleFactor = sf::Vector2f(0.6, 0.5);
        sf::IntRect rubberRect = sf::IntRect(613 * 4, 0, 613, 432);
        direction currentD;

    public:
        Rubber();
        sf::Sprite &getRubber()
        {
            return rubber_object;
        };
        sf::Vector2f getPosition()
        {
            return rubber_object.getPosition();
        };

        direction getCurrentD()
        {

            return currentD;
        };

        void elongate(sf::RenderWindow &window)
        {

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 11 / 100))
            {
                currentD = direction::minus4;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 11 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 22 / 100))
            {
                currentD = direction::minus3;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 22 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 33 / 100))
            {
                currentD = direction::minus2;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 33 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 44 / 100))
            {
                currentD = direction::minus1;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 44 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 55 / 100))
            {
                currentD = direction::zero;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 55 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 66 / 100))
            {
                currentD = direction::plus1;
            }

            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 66 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 77 / 100))
            {
                currentD = direction::plus2;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 77 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x * 88 / 100))
            {
                currentD = direction::plus3;
            }
            else if (static_cast<int>(mousePosition.x) > static_cast<int>(window.getSize().x * 88 / 100) && static_cast<int>(mousePosition.x) < static_cast<int>(window.getSize().x))
            {
                currentD = direction::plus4;
            }

            else
            {
                currentD = direction::zero;
            }
            sf::IntRect newRect = rubberRect;
            newRect.top = 0;
            newRect.width = 550;
            newRect.height = 500;
            int frameWidth = 613;

            switch (currentD)
            {
            case direction::minus4:
                newRect.left = 0 * frameWidth;

                break;
            case direction::minus3:
                newRect.left = 1 * frameWidth;

                break;
            case direction::minus2:
                newRect.left = 2 * frameWidth;

                break;
            case direction::minus1:
                newRect.left = 3 * frameWidth;
                break;
            case direction::zero:
                newRect.left = 4 * frameWidth;

                break;
            case direction::plus1:
                newRect.left = 5 * frameWidth;
                break;
            case direction::plus2:
                newRect.left = 6 * frameWidth;
                break;
            case direction::plus3:
                newRect.left = 7 * frameWidth;
                break;
            case direction::plus4:
                newRect.left = 8 * frameWidth;

                break;
            default:
                newRect.left = frameWidth * 5;

                break;
            }
            rubber_object.setTextureRect(newRect);
        }
    };

    Rubber::Rubber()
    {
        rubber_object.setTexture(textures.rubber);
        rubber_object.setScale(rubberScaleFactor);
        rubber_object.setPosition(sf::Vector2f(307, 408));
        rubber_object.setTextureRect(rubberRect);
    };

    class Guleli
    {
        sf::Sprite guleli_o;
        sf::Vector2f guleliScaleFactor = sf::Vector2f(0.6, 0.5);

    public:
        Guleli();
        sf::Sprite &getGuleli()
        {
            return guleli_o;
        }
    };
    Guleli::Guleli()
    {
        guleli_o.setTexture(textures.guleli_t);
        guleli_o.scale(guleliScaleFactor);
        sf::Rect<float> size = guleli_o.getGlobalBounds();
        guleli_o.setOrigin(size.width / 2.0f, size.height / 2.0f);
        guleli_o.setPosition(sf::Vector2f((Window::window.getSize().x) / 2.2f, (Window::window.getSize().y) / 1.5f));
    };

    class Background
    {
        sf::Sprite bg_object;

    public:
        Background();
        sf::Sprite &getBackground()
        {
            return bg_object;
        }
    };

    Background::Background()
    {
        bg_object.setTexture(textures.bg);
    };

    class Ball
    {

        sf::Sprite ball_object;

    public:
        Ball();
      
       
        void setPostition(sf::Vector2f newPosition)
        {
            ball_object.setPosition(newPosition);
        };
 sf::Sprite &getBall()
        {
            return ball_object;
        };
        void fireTexture(bool opt);
      

        void moveBall(Rubber &c);

        void resetPosition();
     
    };

 void Ball::resetPosition()
        {
            ball_object.setPosition(Window::centerPosition.x + 48, Window::centerPosition.y + 150);
        };

 void Ball::fireTexture(bool opt)
        {
            if (opt)
            {
                ball_object.setTexture(textures.ball_original);
            }
            else
            {
                ball_object.setTexture(textures.ball);
            }
        };




    void Ball::moveBall(Rubber &c)
    {
        sf::Vector2f temp(c.getPosition());
        direction currenD = c.getCurrentD();
        this->fireTexture(false);

        switch (currenD)
        {
        case direction::minus4:
            temp = sf::Vector2f(temp.x + 25, temp.y + 160);

            break;
        case direction::minus3:
            temp = sf::Vector2f(temp.x + 70, temp.y + 165);
            break;
        case direction::minus2:
            temp = sf::Vector2f(temp.x + 100, temp.y + 160);
            break;
        case direction::minus1:
            temp = sf::Vector2f(temp.x + 135, temp.y + 160);

            break;
        case direction::zero:
            temp = sf::Vector2f(temp.x + 180, temp.y + 160);

            break;
        case direction::plus1:
            temp = sf::Vector2f(temp.x + 200, temp.y + 160);
            break;
        case direction::plus2:
            temp = sf::Vector2f(temp.x + 235, temp.y + 160);

            break;
        case direction::plus3:
            temp = sf::Vector2f(temp.x + 265, temp.y + 160);
            break;
        case direction::plus4:
            temp = sf::Vector2f(temp.x + 299, temp.y + 160);

            break;

        default:
            temp = sf::Vector2f(temp.x + 170, temp.y + 160);
            break;
        };

        this->setPostition(temp);
    };

    Ball::Ball()
    {
        ball_object.setTexture(textures.ball);
        ball_object.setScale(0.15f, 0.15f);
        ball_object.setOrigin(ball_object.getLocalBounds().width / 2.0f, ball_object.getLocalBounds().height / 2.0f);
        ball_object.setPosition(Window::centerPosition.x + 48, Window::centerPosition.y + 150);
    };

    class Aim
    {
        sf::Sprite aim_object;

    public:
        Aim();
        void moveAim(sf::RenderWindow &window);
        sf::Sprite &getAim()
        {
            return aim_object;
        };
    };

    Aim::Aim()
    {
        aim_object.setTexture(textures.aim);
        aim_object.setPosition(sf::Vector2f((Window::window.getSize().x) / 2.2f, (Window::window.getSize().y) / 2.0f));
        aim_object.setOrigin(aim_object.getLocalBounds().width / 2.0f, aim_object.getLocalBounds().height / 2.0f);
    };

    void Aim::moveAim(sf::RenderWindow &window)
    {

        aim_object.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        sf::Vector2i mousePosition = sf::Mouse::getPosition(Window::window);
        float newY = window.getSize().y - mousePosition.y;
        if (newY > window.getSize().y / 2)
        {
            newY = aim_object.getPosition().y;
        }

        aim_object.setPosition(window.getSize().x - sf::Mouse::getPosition(Window::window).x, newY);
    };
  class Bird
    {
    protected:
        sf::Texture bird; 
        sf::Sprite bird_object;
        sf::Vector2f birdScaleFactor = sf::Vector2f(0.6, 0.6);
        sf::IntRect birdRect = sf::IntRect(0, 0, 182, 170);
        float birdSpeed;
        int fire_count;

    public:
        Bird();
        sf::Sprite &getBird()
        {
            return bird_object;
        };
        void animateBird();
        virtual sf::Vector2f randomizeStartingPosition();
        void check_boundary(sf::FloatRect &boundary, Ball &obj, Aim &aim, int mode);
        int getFireCount();
    };

    Bird::Bird()
    {
        if (!bird.loadFromFile("./Resources/img/bird.png"))
        {
            std::cout << "texture wasn't loaded"
                      << "\n";
        };
        bird.setSmooth(true);

        bird_object.setTexture(bird);
        bird_object.setTextureRect(birdRect);
        bird_object.scale(birdScaleFactor);
        birdSpeed = 6.0f;
        fire_count = 0;
    };

    void Bird::check_boundary(sf::FloatRect &boundary, Ball &obj, Aim &aim, int mode)
    {
        sf::Vector2f birdPosition = getBird().getPosition();

        float offset = 50.0f;
        sf::Vector2f birdHeadPosition(birdPosition.x + offset, birdPosition.y + offset);
        static bool moveDownward = false;

        if ((boundary.contains(birdHeadPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            fire_count += 1;
            fire(obj.getBall(), aim.getAim());
            obj.fireTexture(true);
            moveDownward = true;

            randomizeStartingPosition();
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
          
            Window::window.setMouseCursorVisible(true);
            gameover(std::to_string(getFireCount()), mode);
        }
    }

    void Bird::animateBird()
    {
        if (birdRect.left == 728)
        {
            birdRect.left = 0;
            if (birdRect.top == 340)
            {
                birdRect.top = 0;
            }
            else
            {
                birdRect.top += 170;
            };
        }
        else if (birdRect.top == 340 && birdRect.left == 546)
        {
            birdRect.top = 0;
            birdRect.left = 0;
        }
        else
        {
            birdRect.left += 182;
        };

        bird_object.setTextureRect(birdRect);
        bird_object.move(birdSpeed, 0.0f);
    };
    sf::Vector2f Bird::randomizeStartingPosition()
    {

        birdSpeed += 2.0f;
        bird_object.move(birdSpeed, 0.0f);

        float lowerBound = 0.0f;
        float upperBound = 250.0f;
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<float> distribution(lowerBound, upperBound);

        float randomPosition = distribution(generator);
        bird_object.setPosition(lowerBound, randomPosition);

        return sf::Vector2f(0, 0);
    }

    int Bird::getFireCount()
    {
        return fire_count;
    }

    class Bird_medium : public Bird
    {
    protected:
        sf::Texture birdf;
        bool inverted = false;
        sf::IntRect invertedBirdRect = sf::IntRect(0, 0, 179, 154);

    public:
        Bird_medium() : Bird()
        {
            if (!birdf.loadFromFile("./Resources/img/birdR.png"))
            {
                std::cout << "texture wasn't loaded"
                          << "\n";
            };
            randomizeStartingPosition();
        };
        sf::Vector2f randomMotion(int sign);
        void animateBird();
        sf::Vector2f randomizeStartingPosition() override;
    };

    sf::Vector2f Bird_medium::randomizeStartingPosition()
    {
      
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = now.time_since_epoch();
        auto seed = static_cast<unsigned int>(duration.count());

     
        std::mt19937 generator(seed);

        std::uniform_real_distribution<float> distribution2(0, 150);

        birdSpeed += 2.0f;

        float lowerBound = 0.0f;
        float upperBound = 250.0f;

        std::uniform_real_distribution<float> distribution(lowerBound, upperBound);

        float randomPosition = distribution(generator);

        float y = distribution2(generator);

        float x;

        if (distribution2(generator) > 75)
        {
            inverted = true;
            x = Window::window.getSize().x - 40;
            bird_object.setTexture(birdf);
            birdRect = invertedBirdRect;
            bird_object.setPosition(Window::window.getSize().x, randomPosition);
        }
        else
        {
            inverted = false;
            x = 0;
            bird_object.setTexture(bird);
            birdRect = sf::IntRect(0, 0, 182, 170);

            bird_object.setPosition(Window::window.getSize().x, randomPosition);
        }

        return sf::Vector2f(x, y);
    }

    sf::Vector2f Bird_medium::randomMotion(int sign)
    {
        static std::random_device rd;
        static std::default_random_engine engine(rd());
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = now.time_since_epoch();
        auto seed = static_cast<unsigned int>(duration.count());
        engine.seed(seed);

        std::uniform_real_distribution<float> distribution1(4.0f, 10.0f);
        std::uniform_real_distribution<float> distribution2(-6.0f, 6.0f);

        float x = distribution1(engine) * sign;
        float y = distribution2(engine);

        if (((bird_object.getPosition().y + y) < 0) || ((bird_object.getPosition().y + y) > 200))
        {
            y = 0;
        }
        if (sign == 1)
        {
            x += birdSpeed;
        }
        else
        {
            x -= birdSpeed;
        }

        return sf::Vector2f(x, y);
    }

    void Bird_medium::animateBird()
    {
        int invSpriteWidth = 179;
        int invSpriteHeight = 154;

        if (inverted)
        {
            if (birdRect.left == invSpriteWidth * 2)
            {
                birdRect.left = 0;
                if (birdRect.top == invSpriteHeight * 2)
                {
                    birdRect.top = 0;
                }
                else
                {
                    birdRect.top += invSpriteHeight;
                };
            }
            else if (birdRect.top == invSpriteHeight * 2 && birdRect.left == invSpriteWidth)
            {
                birdRect.top = 0;
                birdRect.left = 0;
            }
            else
            {
                birdRect.left += invSpriteWidth;
            };
        }
        else
        {

            if (birdRect.left == 728)

            {
                birdRect.left = 0;
                if (birdRect.top == 340)
                {
                    birdRect.top = 0;
                }
                else
                {
                    birdRect.top += 170;
                };
            }
            else if (birdRect.top == 340 && birdRect.left == 546)
            {
                birdRect.top = 0;
                birdRect.left = 0;
            }
            else
            {
                birdRect.left += 182;
            };
        };

        bird_object.setTextureRect(birdRect);
        if (inverted)
        {
            bird_object.move(this->randomMotion(-1));
        }
        else
        {
            bird_object.move(this->randomMotion(1));
        }

        if ((bird_object.getPosition().x > Window::window.getSize().x) || (bird_object.getPosition().x < 0))
        {
            bird_object.setPosition(this->randomizeStartingPosition());
        };
        if (bird_object.getPosition().y > Window::window.getSize().y)
        {
            bird_object.setPosition(this->randomizeStartingPosition());
        };
    };

    class Bird_Hard : public Bird_medium
    {
        Bird_medium **ptr;
        float offset = 50.0f;
        int no;

    public:
        Bird_Hard(int);
        ~Bird_Hard();
        void draw();
        void animate();
        void check_boundary(sf::FloatRect &boundary, Ball &obj, Aim &aim, int mode);
    };

    void Bird_Hard::animate()
    {
        for (int i = 0; i < no; i++)
        {

            (*ptr[i]).animateBird();
        }
    }

    Bird_Hard::Bird_Hard(int n)
    {

        ptr = new Bird_medium *[n];
        for (int i = 0; i < n; i++)
        {
            ptr[i] = new Bird_medium();
        }
        no = n;
    }

    void Bird_Hard::draw()
    {
        for (int i = 0; i < no; i++)
        {

            Window::window.draw((*ptr[i]).getBird()); // sf::Sprite& s = (*ptr[i]).getBird();
        }
    }
    void Bird_Hard::check_boundary(sf::FloatRect &boundary,Ball &obj, Aim &aim, int mode)
    {
        int rebound{0};
        static int framesToSkip = 0;
        int old_score = fire_count;
        for (int i = 0; i < no; i++)
        {

            if (framesToSkip > 0)
            {
                framesToSkip--;
                continue;
            }
            sf::Vector2f birdPositionWithOffset(ptr[i]->getBird().getPosition().x + offset, ptr[i]->getBird().getPosition().y + offset);
            if (boundary.contains(birdPositionWithOffset) && sf::Mouse::isButtonPressed(sf::Mouse::Left))

            {

                fire_count += 1;

               
                fire(obj.getBall(), aim.getAim());
                obj.fireTexture(true);

                ptr[i]->randomizeStartingPosition();

                framesToSkip = 80;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (framesToSkip > 40)
                {
                    framesToSkip--;
                    continue;
                }

                else if (fire_count == old_score && fire_count > 0)
                {
                    gameover(std::to_string(getFireCount()), mode);
                }
            }
        }
    }

    Bird_Hard::~Bird_Hard()
    {
        delete[] ptr;
    }

   

