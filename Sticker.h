#pragma once
using namespace std;
enum class Rarity
{
	Standart,
	Silver,
	Gold,
	Platinum
};
class Sticker
{
private:
	static int number;
	int id;
	char* name;
	int raiting;
	Rarity rarity;
	void free();
	void copyFrom(const Sticker& other);
	void moveFrom(Sticker&& other) noexcept;
public:
	Sticker();
	Sticker(const char* name, int raiting, Rarity rarity);
	Sticker(const Sticker& other);
	Sticker(Sticker&& other) noexcept;
	~Sticker();
	Sticker& operator=(const Sticker& other);
	Sticker& operator=(Sticker&& other)noexcept;
	friend bool operator==(const Sticker& lhs, const Sticker& rhs);
	auto operator<=>(const Sticker& other) const;
	int getRaiting()const;
};