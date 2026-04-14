#include "Product.h"
#include <cstring>

//char* name;
//int size;
//double price;
//static int count;
//int id;
//char* producer;


void Product::free() {
	delete[] name;
	delete[] producer;
	name = producer = nullptr;
}

void Product::copyFrom(const Product& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->producer = new char[strlen(other.producer) + 1];
	strcpy(this->producer, other.producer);
	size = other.size;
	price = other.price;
	id = other.id; // depends
}

Product::Product(const char* name, int size, double price, const char* producer) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->producer = new char[strlen(producer) + 1];
	strcpy(this->producer, producer);
	this->size = size;
	this->price = price;
	this->id = count++;
}

double Product::getPrice() const
{
	return 0.0;
}

const char* Product::getProducer() const
{
	return nullptr;
}

const char* Product::getName() const
{
	return nullptr;
}

int Product::getSize() const
{
	return 0;
}

int Product::getId() const
{
	return 0;
}

void Product::setPrice(double price)
{
}

void Product::setProducer(const char* producer)
{
}

void Product::setName(const char* name)
{
}

void Product::setSize(int size)
{
}

Product::~Product() {
	free();
}

Product& Product::operator=(const Product& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Product::Product(const Product& other) {
	copyFrom(other);
}
