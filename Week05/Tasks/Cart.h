#pragma once
#include "Product.h"

class Cart
{
	Product* products;
	size_t size;
	size_t capacity;
	int id;

	static int idCounter;

	void free();
	void copyFrom(const Cart& other);

public:
};

