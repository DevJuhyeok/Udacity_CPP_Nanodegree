#include "winner.h"

void Winner::UpdateWinner(Player currentPlayer)
{
    ReadWinnerPlayer();

    if(currentPlayer.GetLevel() > this->GetLevel())
    {
        //winnerPlayer = currentPlayer;
        this->SetName(currentPlayer.GetName());
        this->SetLevel(currentPlayer.GetLevel());
        this->SetScore(currentPlayer.GetScore());
        WriteWinnerPlayer();

        std::cout << "Winner is changed ! \n";
        std::cout << "Name: " << this->GetName() << "\n";
        std::cout << "Level: " << this->GetLevel() << "\n";
        std::cout << "Score: " << this->GetScore() << "\n";
    }
}

void Winner::ReadWinnerPlayer()
{
    std::string line;
    std::string name;
    std::string level;
    std::string score;

    std::ifstream ifstream("../winner.txt");
    if(ifstream.is_open())
    {
        while(std::getline(ifstream, line))
        {
            std::istringstream linestream(line);
            while(linestream >> name >> level >> score)
            {
                this->SetName(name);
                this->SetLevel(stoi(level));
                this->SetScore(stoi(score));

                //player = Player(name, stoi(level), stoi(score));
            }
        }
        ifstream.close();
    }
}

void Winner::WriteWinnerPlayer()
{
    std::ofstream ofstream("../winner.txt");
    if(ofstream.is_open())
    {
        ofstream << this->GetName() << " " << std::to_string(this->GetLevel()) << " " << std::to_string(this->GetScore());
        ofstream.close();
    }
}

