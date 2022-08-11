#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player
{
    public:
    Player();
    ~Player();
    Player(std::string name, int level, int score) : _name(name), _level(level), _score(score) {};

    std::string GetName();
    int GetLevel();
    int GetScore();

    void SetName(std::string name);
    void SetLevel(int level);
    void SetScore(int score);

    void GetPlayer();

    // rule of 5
    Player(const Player &source); // 2 : copy constructor
    Player &operator=(const Player &source); // 3 : copy assignment operator
    Player(Player &&source); // 4 : move constructor
    Player &operator=(Player &&source); // 5 : move assignment operator

    private:
    std::string _name;
    int _level;
    int _score;
};

#endif