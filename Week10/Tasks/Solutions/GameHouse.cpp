#include "GameHouse.h"

void GameHouse::removeBanckruptedPlayers() {
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i].first->getMoney() <= 0) {
            players.erase(players.begin() + i);
            --i;
        }
    }
}

void GameHouse::play(Game game)
{
    games.push_back(game);
    totalGamesPlayed++;
    if (totalGamesPlayed % 5 == 0) {
        houseEarnings.push_back(dayEarnings);
        dayEarnings = 0;
    }
    double pool = game.play();
    double winnerEarnings = 0.0;
    switch (game.getGameType()) {
    case GameType::Blackjack:
        dayEarnings += pool * 0.3;
        winnerEarnings = pool * 0.7;
        break;
    case GameType::Poker:
        dayEarnings += pool * 0.2;
        winnerEarnings = pool * 0.8;
        break;
    case GameType::Slots:
        dayEarnings += pool * 0.35;
        winnerEarnings = pool * 0.65;
        break;
    }

    for (const auto& player : game.getPlayers()) {
        if (player.first->getId() == game.getWinnerId()) {
            depositEarnings(winnerEarnings, player.first);
        } else {
            depositEarnings(-player.second, player.first);
        }
    }

    removeBanckruptedPlayers();
}

void GameHouse::addPlayer(std::shared_ptr<Player> player) {
    players.push_back({player, 0.0});
}

std::vector<std::pair<std::shared_ptr<Player>, double>> GameHouse::getPlayers() const {
    return players;
}

double GameHouse::displayHouseEarnings() const
{
    double res=0;
    for (const auto& earning : houseEarnings) {
        res += earning;
    }
    return res;
}

void GameHouse::depositEarnings(double amount, std::shared_ptr<Player> player)
{
    for (auto& p : players) {
        if (p.first == player) {
            p.second += amount;
            break;
        }
    }

}

std::ostream &operator<<(std::ostream &os, const GameHouse &house)
{
    os << "GameHouse has " << house.players.size() << " players and has earned " << house.displayHouseEarnings() << " today." << std::endl;
    os << "Players:" << std::endl;
    for (const auto& player : house.players) {
        os << "Player " << player.first->getName() << " (Name: "  << player.first->getName() << ") has " << player.second  << "$" << std::endl;
    }
    os << "Games played: " << house.games.size() << std::endl;
     for (const auto& game : house.games) {
        os << "Game Type: ";
        switch (game.getGameType()) {
            case GameType::Blackjack:
                os << "Blackjack";
                break;
            case GameType::Poker:
                os << "Poker";
                break;
            case GameType::Slots:
                os << "Slots";
                break;
        }
        os << ", Winner: " << game.getWinner() << std::endl;
    }
    return os;
}
