#pragma once
#include <iostream>
#include <string>

class Player
{
private:
    static int idCounter;
    int id;
    std::string name;
    double money;
    int nonchalantSkill;
    int luck;
    int aura;

public:
    Player(const std::string &name, double money, int nonchalantSkill, int luck, int aura);
    int getId() const;
    std::string getName() const;
    double getMoney() const;
    int getNonchalantSkill() const;
    int getLuck() const;
    int getAura() const;
};