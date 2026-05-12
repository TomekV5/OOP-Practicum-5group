#include "Player.h"

Player::Player(const std::string &name, double money, int nonchalantSkill, int luck, int aura)
{
    this->id = ++idCounter;
    this->name = name;
    this->money = money;
    this->nonchalantSkill = nonchalantSkill;
    this->luck = luck;
    this->aura = aura;
}

int Player::getId() const
{
    return id;
}

std::string Player::getName() const
{
    return name;
}

double Player::getMoney() const
{
    return money;
}

int Player::getNonchalantSkill() const
{
    return nonchalantSkill;
}

int Player::getLuck() const
{
    return luck;
}

int Player::getAura() const
{
    return aura;
}