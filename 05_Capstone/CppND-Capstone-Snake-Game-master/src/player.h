#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player
{
    public:
    Player();
    ~Player();
    //Player(std::string name, int level, int score) : _name(name), _level(level), _score(score) {};

    std::string GetName();
    int GetLevel();
    int GetScore();

    void SetName(std::string name);
    void SetLevel(int level);
    void SetScore(int score);

    void GetPlayer();

    private:
    std::string _name;
    int _level;
    int _score;
};

#endif