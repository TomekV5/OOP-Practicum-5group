#include "Team.h"
#include <cstring>
#include <utility>
#pragma warning (disable:4996)
void Team::free() {
	for (int i = 0; i < maxPlayersCount; i++) {
		this->players[i] = nullptr;
	}
	delete[] managerName;
	managerName = nullptr;
	stadium = "";
}
void Team::copyFrom(const Team& other)
{
	for (int i = 0; i < maxPlayersCount; i++) {
		this->players[i] = other.players[i];
	}
	this->managerName = new char[strlen(other.managerName) + 1];
	strcpy(this->managerName, other.managerName);
	this->stadium = other.stadium;
}

void Team::moveFrom(Team&& other) noexcept
{
	for (int i = 0; i < maxPlayersCount; i++) {
		this->players[i] = other.players[i];
	}
	this->managerName = other.managerName;
	this->stadium = other.stadium;
}

Team::Team()
{
	managerName = new char[1] {""};
	stadium = "";
}

Team::Team(Sticker* players, const char* managerName, string stadium)
{
	for (int i = 0; i < maxPlayersCount; i++) {
		this->players[i] = &players[i];
	}
	this->managerName = new char[strlen(managerName) + 1];
	strcpy(this->managerName, managerName);
	this->stadium = stadium;
}

Team::Team(const Team& other)
{
	copyFrom(other);
}

Team::Team(Team&& other) noexcept
{
	moveFrom(std::move(other));
}

Team::~Team()
{
	free();
}

Team& Team::operator=(const Team& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Team& Team::operator=(Team&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Team::addPlayer(const Sticker& player)
{
}

void Team::addPlayer(Sticker&& player)
{
}

double Team::averageRating() const
{
	double total = 0;
	for (int i = 0; i < maxPlayersCount; i++) {
		total += players[i]->getRaiting();
	}
	return total / 11.0;
}

std::ostream& operator<<(std::ostream& oc, const Team& team)
{
	return oc << "Stadium: " << team.stadium << "\nManager: " << team.managerName << "\nRating: " << team.averageRating();
}