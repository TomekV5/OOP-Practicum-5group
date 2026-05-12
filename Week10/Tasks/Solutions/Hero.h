#pragma once
#include <iostream>
#include <cstring>

enum class HeroType
{
    Tank,
    Support,
    Assassin,
    Controller,
    Marksman
};

enum class Result
{
    Win,
    Lose,
    Draw
};

class Hero
{
private:
    HeroType type;
    char *name;
    int hp;
    int damagePerShot;
    int attackDelay;
    Result *history;
    size_t historySize;
    size_t historyCount;

    void free();
    Hero &copyFrom(const Hero &other);
    Hero &moveFrom(Hero &&other);

    void addResult(Result result);
public:
    // Rule of Five
    Hero(const char *name, HeroType type, int hp, int damagePerShot, int attackDelay);
    Hero(const Hero &other);
    Hero(Hero &&other) noexcept;
    Hero &operator=(const Hero &other);
    Hero &operator=(Hero &&other) noexcept;
    ~Hero();

    void fight(Hero &opponent);
    void heroInfo() const;
    void gameHistory() const;
    friend std::ostream &operator<<(std::ostream &os, const Hero &hero);

    auto operator<=>(const Hero &other) const;
    bool operator==(const Hero &other) const;
    bool operator!=(const Hero &other) const;
};