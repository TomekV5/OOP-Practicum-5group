#include "Hero.h"

void Hero::free() {
    delete[] name;
    delete[] history;
}

Hero &Hero::copyFrom(const Hero &other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    type = other.type;
    hp = other.hp;
    damagePerShot = other.damagePerShot;
    attackDelay = other.attackDelay;
    historySize = other.historySize;
    historyCount = other.historyCount;

    history = new Result[other.historySize];
    for (int i = 0; i < other.historySize; ++i) {
        history[i] = other.history[i];
    }
    return *this;
}

Hero& Hero::moveFrom(Hero &&other) {
    name = other.name;
    type = other.type;
    hp = other.hp;
    damagePerShot = other.damagePerShot;
    attackDelay = other.attackDelay;
    history = other.history;
    historySize = other.historySize;
    historyCount = other.historyCount;

    other.name = nullptr;
    other.history = nullptr;
    return *this;
}

void Hero::addResult(Result result) {
    if (historyCount >= historySize) {
        Result * temp = new Result[historySize * 2];
        for (int i = 0; i < historySize; ++i) {
            temp[i] = history[i];
        }
        delete[] history;
        history = temp;
        historySize *= 2;
    }
    history[historyCount++] = result;
}

Hero::Hero(const char *name, HeroType type, int hp, int damagePerShot, int attackDelay) : type(type), hp(hp), damagePerShot(damagePerShot), attackDelay(attackDelay), historySize(10), historyCount(0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    history = new Result[historySize]{};
}

Hero::Hero(const Hero &other) {
    copyFrom(other);
}

Hero::Hero(Hero &&other) noexcept {
    moveFrom(std::move(other));
}

Hero& Hero::operator=(const Hero &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Hero& Hero::operator=(Hero &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Hero::~Hero() {
    free();
}

void Hero::fight(Hero &opponent) {
    if (*this == opponent) {
        this->addResult(Result::Draw);
        opponent.addResult(Result::Draw);
    } else if (*this > opponent) {
        this->addResult(Result::Win);
        opponent.addResult(Result::Lose);
    } else {
        this->addResult(Result::Lose);
        opponent.addResult(Result::Win);
    }
}

void Hero::heroInfo() const {
    std::cout << "Name: " << name << "\nType: " << static_cast<int>(type) << "\nHP: " << hp
              << "\nDamage per shot: " << damagePerShot << "\nAttack delay: " << attackDelay << std::endl;
}

void Hero::gameHistory() const {
    std::cout << "Game history for " << name << ":\n";
    for (size_t i = 0; i < historyCount; ++i) {
        std::cout << "Game " << i + 1 << ": ";
        switch (history[i]) {
            case Result::Win:
                std::cout << "Win";
                break;
            case Result::Lose:
                std::cout << "Lose";
                break;
            case Result::Draw:
                std::cout << "Draw";
                break;
        }
        std::cout << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Hero &hero) {
    os << "Name: " << hero.name << "\nType: " << static_cast<int>(hero.type) << "\nHP: " << hero.hp
       << "\nDamage per shot: " << hero.damagePerShot << "\nAttack delay: " << hero.attackDelay;
    return os;
}

auto Hero::operator<=>(const Hero &other) const {
    int firstTime = (other.hp / damagePerShot) * attackDelay;
    if (other.hp % damagePerShot == 0)
        firstTime--;
    int secondTime = (hp / other.damagePerShot) * other.attackDelay;
    if (hp % other.damagePerShot == 0)
        secondTime--;

    return firstTime <=> secondTime;
}

bool Hero::operator==(const Hero &other) const {
    int firstTime = (other.hp / damagePerShot) * attackDelay;
    if (other.hp % damagePerShot == 0)
        firstTime--;
    int secondTime = (hp / other.damagePerShot) * other.attackDelay;
    if (hp % other.damagePerShot == 0)
        secondTime--;

    return firstTime == secondTime;
}

bool Hero::operator!=(const Hero &other) const {
    return !(*this == other);
}