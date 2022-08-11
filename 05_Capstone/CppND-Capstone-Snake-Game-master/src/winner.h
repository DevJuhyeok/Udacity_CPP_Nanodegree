#ifndef WINNER_H
#define WINNER_H

#include "player.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

class Winner : Player
{
    public:
    Winner() : Player() {}
    //~Winner();
    
    void UpdateWinner(Player currentPlayer);
    void ReadWinnerPlayer();
    void WriteWinnerPlayer();

    private:
    //Player currentPlayer;
    //Player winnerPlayer;
    //int changedWinner{0};
};

#endif