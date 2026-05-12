#pragma once
#include "Cart.h"

class User
{
	Cart cart;
	char* username;
	double balance;
	char* password;
	int userId;

	static int idCounter;

	void free();
	void copyFrom(const User& other);
public:
	User(const User& other);
};

