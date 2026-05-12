#include <iostream>
#include "Merchant.h"
#pragma once
#pragma warning(disable:4996)

class MarketPlace {
private:
    char* description = nullptr;
    double slotRent;
    Merchant** merchants;
    size_t size;
    size_t capacity;

    void free();
    void copyFrom(const MarketPlace& other);
    void moveFrom(MarketPlace&& other);

public:
    MarketPlace(const char* description, unsigned int capacity, double slotRent);
	MarketPlace(const MarketPlace& other);
	MarketPlace& operator=(const MarketPlace& other);
	MarketPlace(MarketPlace&& other) noexcept;
	MarketPlace& operator=(MarketPlace&& other) noexcept;
	~MarketPlace();

    MarketPlace& operator+=(const Merchant& m);
	MarketPlace& operator-=(double minRevenue);

	friend std::ostream& operator<<(std::ostream& os, const MarketPlace& m);
	auto operator<=>(const MarketPlace& other) const;

    MarketPlace& operator()(int days);
	operator bool() const;

    void addAt(int pos, const Merchant& m);
	bool isFreeSlot(int pos) const;
	unsigned int takenSlots() const;
	double getProfit() const;
	double averageProfit() const;
};