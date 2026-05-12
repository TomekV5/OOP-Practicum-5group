#include "MarketPlace.h"

void MarketPlace::free() {
    delete[] description;
    for (size_t i = 0; i < size; i++) {
        delete merchants[i];
    }
    delete[] merchants;
}

void MarketPlace::copyFrom(const MarketPlace& other) {
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);

    slotRent = other.slotRent;
    size = other.size;
    capacity = other.capacity;

    merchants = new Merchant*[capacity];
    for (size_t i = 0; i < size; i++) {
        merchants[i] = new Merchant(*other.merchants[i]);
    }
}

void MarketPlace::moveFrom(MarketPlace&& other) {
    description = other.description;
    slotRent = other.slotRent;
    size = other.size;
    capacity = other.capacity;
    merchants = other.merchants;

    other.description = nullptr;
    other.merchants = nullptr;
}

MarketPlace::MarketPlace(const char* description, unsigned int capacity, double slotRent) {
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);

    this->slotRent = slotRent;
    this->capacity = capacity;
    this->size = 0;

    this->merchants = new Merchant*[capacity];
}

MarketPlace::MarketPlace(const MarketPlace& other) {
    copyFrom(other);
}

MarketPlace& MarketPlace::operator=(const MarketPlace& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MarketPlace::MarketPlace(MarketPlace&& other) noexcept {
    moveFrom(std::move(other));
}

MarketPlace& MarketPlace::operator=(MarketPlace&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MarketPlace::~MarketPlace() {
    free();
}

MarketPlace& MarketPlace::operator+=(const Merchant& m) {
    if(size == capacity) {
		delete merchants[size - 1];
		merchants[size - 1] = new Merchant(m);
		return *this;
	}

	for (int i = 0; i < capacity; i++)
	{
		if(merchants[i] == nullptr) {
			merchants[i] = new Merchant(m);
			break;
		}
	}

	size++;
	return *this;
}

MarketPlace& MarketPlace::operator-=(double minRevenue) {
    for (int i = 0; i < capacity; i++)
	{
		if(merchants[i] && merchants[i]->getIncome() < minRevenue) {
			delete merchants[i];
			merchants[i] = nullptr;
			size--;
		}
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const MarketPlace& m) {
   for (int i = 0; i < m.capacity; i++) {
		if (m.merchants[i] == nullptr) {
			os << "*";
		}
		else {
			os << m.merchants[i]->getId() << " ";
		}
	}
	os << m.description;
	os << m.slotRent;
	return os;
}

auto MarketPlace::operator<=>(const MarketPlace& other) const {
    double sumOfCurrentMerchant = getProfit();

	double sumOfOtherMerchant = other.getProfit();

	if (abs(sumOfCurrentMerchant - sumOfOtherMerchant) < 0.001) {
		double myRatio = (double)size / capacity;
		double otherRatio = (double)other.size / other.capacity;
		return myRatio <=> otherRatio;
	}
	return sumOfCurrentMerchant <=> sumOfOtherMerchant;
}

MarketPlace& MarketPlace::operator()(int days) {
    for (int i = 0; i < capacity; i++)
	{
		if (merchants[i]) {
			for (int j = 0; j < days; j++)
			{
				++(*merchants[i]);
			}
		}
	}
	return *this;
}

MarketPlace::operator bool() const {
   return size > (capacity / 2.00);
}

void MarketPlace::addAt(int pos, const Merchant &m) {
    if(pos < 0 || pos >= capacity) {
        return;
    }

    if (merchants[pos]) {
		delete merchants[pos];
	}
	else {
		size++;
	}
	merchants[pos] = new Merchant(m);
}

bool MarketPlace::isFreeSlot(int pos) const {
    if(pos < 0 || pos >= capacity) {
        return false;
    }

    return merchants[pos] == nullptr;
}

unsigned int MarketPlace::takenSlots() const {
    return size;
}

double MarketPlace::getProfit() const {
	double res = 0;

	for (int i = 0; i < capacity; i++)
	{
		if (merchants[i]) {
			res += merchants[i]->getIncome();
		}
	}

	res -= (slotRent * size);

	return res;
}

double MarketPlace::averageProfit() const {
    if(size == 0) {
        return 0;
    }

    return getProfit() / size;
}