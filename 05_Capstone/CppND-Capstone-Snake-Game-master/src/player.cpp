#include "player.h"

Player::Player()
{
    _name = "Unkown Player";
    _score = 0;
    _level = 0;
}

Player::~Player()
{
    ;
}

std::string Player::GetName()
{
    return _name;
}

int Player::GetScore()
{
    return _score;
}

int Player::GetLevel()
{
    return _level;
}

void Player::SetName(std::string name)
{
    _name = name;
}

void Player::SetScore(int score)
{
    _score = score;
}

void Player::SetLevel(int level)
{
    _level = level;
}

void Player::GetPlayer()
{
    std::string name;
    int startingLevel = 0;

    std::cout << "\n";
    std::cout << "Please enter the Player Name : ";
    std::cin >> name;

    std::cout << "\n";
    std::cout << "Please enter the Starting Level of Game : ";
    std::cin >> startingLevel;

    if(&name == nullptr)
    {
        ;
    }
    else
    {
        SetName(name);
    }

    SetLevel(startingLevel);
}
