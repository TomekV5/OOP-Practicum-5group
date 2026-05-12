#include "Game.h"

Game::Game(GameType t) : type(t), winner(""), winnerId(-1), players({}) {}

void Game::placeBet(std::shared_ptr<Player> player, double amount) {
    players.push_back(std::make_pair(player, amount));
}

double Game::play() {
    switch (type) {
        case GameType::Poker:
            double pool = 0.0;
            int maxAura = 0;
            for (const auto& player : players) {
                pool += player.second;
                if (player.first->getAura() > maxAura) {
                    winner = player.first->getName();
                    winnerId = player.first->getId();
                }
            }
            return pool;
        case GameType::Blackjack:
            double pool = 0.0;
            int maxNonchalantSkill = 0;
            for (const auto& player : players) {
                pool += player.second;
                if (player.first->getNonchalantSkill() > maxNonchalantSkill) {
                    winner = player.first->getName();
                    winnerId = player.first->getId();
                }
            }
            return pool;
        case GameType::Slots:
            double pool = 0.0;
            int maxLuck = 0;
            for (const auto& player : players) {
                pool += player.second;
                if (player.first->getLuck() > maxLuck) {
                    winner = player.first->getName();
                    winnerId = player.first->getId();
                }
            }
            return pool;
    }
}

std::string Game::getWinner() const{
    return winner;
}

int Game::getWinnerId() const
{
    return winnerId;
}

GameType Game::getGameType() const
{
    return type;
}

std::vector<std::pair<std::shared_ptr<Player>, double>> Game::getPlayers() const
{
    return players;
}
