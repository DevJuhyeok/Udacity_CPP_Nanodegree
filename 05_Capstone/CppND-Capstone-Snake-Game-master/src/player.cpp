#include "player.h"

Player::Player()
{
    _name = "NoName";
    _level = 0;
    _score = 0;
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

Player::Player(const Player &source)
{
    // 2 : copy constructor

    // copy member variables
    _name = source._name;
    _level = source._level;
    _score = source._score;
}

Player &Player::operator=(const Player &source)
{
    // 3 : copy assignment operator
    if(this == &source){
        return *this;
    }

    // copy member variables
    _name = source._name;
    _level = source._level;
    _score = source._score;
    return *this;
}

Player::Player(Player &&source)
{
    // 4 : move constructor
    _name = source._name;
    _level = source._level;
    _score = source._score;

    source._name = nullptr;
    source._level = 0;
    source._score = 0;
}

Player &Player::operator=(Player &&source)
{
    // 5 : move assignment operator
    
    // exception
    if(this == &source){
        return *this;
    }

    _name = source._name;
    _level = source._level;
    _score = source._score;

    source._name = nullptr;
    source._level = 0;
    source._score = 0;
}