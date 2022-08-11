#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "player.h"
#include "winner.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Player player("NoName", 0, 0);
  player.GetPlayer();

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(player, kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  
  // set winner
  Player currentPlayer(game.GetPlayer());
  
  Player winnerPlayer;
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
        winnerPlayer.SetName(name);
        winnerPlayer.SetLevel(stoi(level));
        winnerPlayer.SetScore(stol(score));
      }
    }
    ifstream.close();
  }
  std::cout << "Write ! \n";
  if(currentPlayer.GetLevel() > winnerPlayer.GetLevel())
  {
      winnerPlayer = currentPlayer;
      std::ofstream ofstream("../winner.txt");
      if(ofstream.is_open())
      {
        std::cout << "Write 2 ! \n";
        ofstream << winnerPlayer.GetName() << " " << std::to_string(winnerPlayer.GetLevel()) << " " << std::to_string(winnerPlayer.GetScore());
        ofstream.close();
      }

      std::cout << "Winner is changed ! \n";
      std::cout << "Name: " << winnerPlayer.GetName() << "\n";
      std::cout << "Level: " << winnerPlayer.GetLevel() << "\n";
      std::cout << "Score: " << winnerPlayer.GetScore() << "\n";
  }
  
  std::cout << "Game has terminated successfully!\n";
  return 0;
}