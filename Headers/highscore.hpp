#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

class HighScore
{
private:
    int highscore;
    int mode;
    int scores_array[3];

    int highscore_f;

public:
    bool isHighScore = false;
    HighScore(int m) : mode(m)
    {
    }
    void handleFile(int currentScore)
    {

        std::fstream scoreFile("score.bin", std::ios::in | std::ios::binary);
        if (!scoreFile)
        {
            std::cerr << "Cannot load file";
        }

        scoreFile.read(reinterpret_cast<char *>(scores_array), sizeof(int) * 3);
        highscore_f = scores_array[mode];
       
        if (currentScore >= highscore_f)
        {
            isHighScore = true;
            highscore_f = currentScore;
            writeInFile(mode);
        }
        scoreFile.close();
    };

    void writeInFile(int m)
    {
        std::fstream scoreFile("score.bin", std::ios::out | std::ios::binary);
        if (!scoreFile)
        {
            std::cerr << "\n Cannot load file";
        }
        scores_array[mode] = highscore_f;

        scoreFile.write(reinterpret_cast<char *>(scores_array), sizeof(int) * 3);
    }

    int getHighscore()
    {
        return highscore_f;
    }
};
