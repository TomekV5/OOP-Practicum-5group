#pragma once
#include <string>
#include "Sticker.h"
#include <iostream>
class Team
{
private:
	static const unsigned maxPlayersCount = 11;
	Sticker* players[maxPlayersCount] = { nullptr };
	char* managerName = nullptr;
	string stadium;
	void free();
	void copyFrom(const Team& other);
	void moveFrom(Team&& other) noexcept;
public:
	Team();
	Team(Sticker*players, const char* name, string stadium);
	Team(const Team& other);
	Team(Team&& other) noexcept;
	~Team();
	Team& operator=(const Team& other);
	Team& operator=(Team&& other)noexcept;
	void addPlayer(const Sticker& player);
	void addPlayer(Sticker&& player);
	double averageRating() const;
	friend std::ostream& operator<<(std::ostream& oc, const Team& team);
};