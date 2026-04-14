#include "User.h"
#include <cstring>

//Cart cart;
//char* username;
//double balance;
//char* password;
//int userId;

void User::free() {

}

void User::copyFrom(const User& other) {
	this->username = new char[strlen(other.username) + 1];
	strcpy(this->username, other.username);

	this->password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);

	balance = other.balance;
}

User::User(const User& other) : cart(other.cart)
{
	copyFrom(other);
}
