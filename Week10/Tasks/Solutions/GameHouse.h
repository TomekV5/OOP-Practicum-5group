#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"
#include "Game.h"

class GameHouse {
private:
    std::vector<std::pair<std::shared_ptr<Player>, double>> players;
    std::vector<Game> games;
    std::vector<double> houseEarnings;
    static int totalGamesPlayed;
    double dayEarnings;

    void removeBanckruptedPlayers();

public:
    void play(Game game);
    void addPlayer(std::shared_ptr<Player> player);
    std::vector<std::pair<std::shared_ptr<Player>, double>> getPlayers() const;
    double displayHouseEarnings() const;
    void depositEarnings(double amount, std::shared_ptr<Player> player);

    friend std::ostream& operator<<(std::ostream& os, const GameHouse& house);
};