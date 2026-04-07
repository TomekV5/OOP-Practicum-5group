#include "Vector.h"
#include <utility>

void Vector::movefrom(Vector&& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = other.data;
	other.data = nullptr;
	other.size = 0;
	other.capacity = 2;
}

void Vector::copyfrom(const Vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		data[i] = other.data[i];
	}
}

void Vector::free()
{
	this->size = 0;
	this->capacity = 2;
	delete[] data;
	data = nullptr;
}

void Vector::resize()
{
	capacity *= 2;
	int* newData = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

Vector::Vector()
{
	this->size = 0;
	this->capacity = 2;
	data = new int[capacity];
}

Vector::Vector(const Vector& other)
{
	copyfrom(other);
}

Vector::Vector(Vector&& other) noexcept
{
	movefrom(std::move(other));
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept
{
	if (this != &other) {
		free();
		movefrom(std::move(other));
	}
	return *this;
}

Vector::~Vector()
{
	free();
}

void Vector::push_back(const int& number)
{
	if (size >= capacity) {
		resize();
	}
	data[size++] = number;
}

int Vector::getSize()
{
	return size;
}

int& Vector::at(int index)
{
	if (index >= size) {
		int a = 0;
		return a;
	}
	return data[index];
}

int& Vector::operator[](int index)
{
	return data[index];
}

const int& Vector::operator[](int index) const
{
	return data[index];
}

void Vector::pop_back() {
	if (size == 0) {
		size = 0;
	}
	else {
		--size;
	}
}

int Vector::getCapacity()
{
	return capacity;
}

bool Vector::isEmpty()
{
	return size==0;
}