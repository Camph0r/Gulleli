#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SoundManager
    {
    private:
        sf::Music musicbg, level;
        sf::SoundBuffer buffer, buffer1, buffer2;
        sf::Sound sound, hit, highScore;

    public:
        SoundManager()
        {
            if (!buffer.loadFromFile("./Resources/music/failure.mp3"))
            {
                std::cout << "Cannot load buffer" << std::endl;
            }
            if (!buffer1.loadFromFile("./Resources/music/hit.wav"))
            {
                std::cout << "Cannot load buffer" << std::endl;
            }
            if (!buffer2.loadFromFile("./Resources/music/highscore.mp3"))
            {
                std::cout << "Cannot load buffer" << std::endl;
            }

            if (!musicbg.openFromFile("./Resources/music/swag.mp3"))
            {
                std::cout << "Cannot load music" << std::endl;
            }
            if (!level.openFromFile("./Resources/music/level.mp3"))
            {
                std::cout << "Cannot load music" << std::endl;
            }
            sound.setBuffer(buffer);
            hit.setBuffer(buffer1);
            highScore.setBuffer(buffer2);
            level.setLoop(true);
            musicbg.setLoop(true);
        }

        void playSound()
        {
            sound.play();
        }
        void playHit()
        {
            hit.play();
        }

        void playHighScore()
        {
            highScore.play();
        }

        void playMusic()
        {
            musicbg.play();
        }
        void playLevel()
        {
            level.play();
        }
        void pauseMusic()
        {
            musicbg.pause();
        }

        void stopMusic()
        {
            musicbg.stop();
        }
    };