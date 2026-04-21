#include "Sticker.h"
#include <cstring>
#include <utility>
#pragma warning (disable:4996)

using namespace std;

int Sticker::number = 0;
void Sticker::free()
{
	delete[] name;
	raiting = 0;
	rarity = Rarity::Standart;
}

void Sticker::copyFrom(const Sticker& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	raiting = other.raiting;
	rarity = other.rarity;
	id = number++;
}

void Sticker::moveFrom(Sticker&& other) noexcept
{
	name = other.name;
	raiting = other.raiting;
	rarity = other.rarity;
	id = number++;
}

Sticker::Sticker()
{
	id = number++;
	name = new char[1] {""};
	raiting = 0;
	rarity = Rarity::Standart;
}

Sticker::Sticker(const char* name, int raiting, Rarity rarity)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->raiting = raiting;
	this->rarity = rarity;
	id = number++;
}

Sticker::Sticker(const Sticker& other)
{
	copyFrom(other);
}

Sticker::Sticker(Sticker&& other) noexcept
{
	moveFrom(std::move(other));
}

Sticker::~Sticker()
{
	free();
}

Sticker& Sticker::operator=(const Sticker& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Sticker& Sticker::operator=(Sticker&& other) noexcept
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

auto Sticker::operator<=>(const Sticker& other) const
{
	return id <=> id;
}

int Sticker::getRaiting() const
{
	return raiting;
}

bool operator==(const Sticker& lhs, const Sticker& rhs)
{
	return lhs.raiting==rhs.raiting;
}