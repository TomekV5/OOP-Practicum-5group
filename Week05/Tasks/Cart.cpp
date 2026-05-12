#include "Cart.h"

//Product* products;
//size_t productCount;
//int id;

//static int idCounter;

void Cart::free() {
	delete[] products;
	products = nullptr;
}

void Cart::copyFrom(const Cart& other) {
	size = other.size;
	id = other.id;

	products = new Product[other.size];
	for (int i = 0; i < other.size; i++) {
		products[i] = other.products[i];
	}
}
