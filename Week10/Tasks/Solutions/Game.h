#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"

enum class GameType
{
    Blackjack,
    Poker,
    Slots
};

class Game
{
private:
    GameType type;
    std::vector<std::pair<std::shared_ptr<Player>, double>> players;
    std::string winner;
    int winnerId;

public:
    Game(GameType t);
    void placeBet(std::shared_ptr<Player> player, double amount);
    double play();
    std::string getWinner() const;
    int getWinnerId() const;
    GameType getGameType() const;
    std::vector<std::pair<std::shared_ptr<Player>, double>> getPlayers() const;
};