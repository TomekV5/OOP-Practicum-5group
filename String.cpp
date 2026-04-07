#include "String.h"
#include <cstring>
#include <utility>
#pragma warning(disable:4996)
void String::movefrom(String&& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = other.data;
	other.data = nullptr;
	other.size = 0;
	other.capacity = 16;
}
void String::copyfrom(const String& other)
{
	data = new char[other.capacity];
	size = other.size;
	capacity = other.capacity;
	strcpy(data, other.data);
}
void String::free() {
	delete[] data;
	data = nullptr;
}
void String::resize(size_t newCap)
{
	capacity = newCap;
	char* newData = new char[capacity];

	for (size_t i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	newData[size] = '\0';

	delete[] data;
	data = newData;
}

String::String()
{
	capacity = 16;
	size = 0;
	data = new char[capacity];
	data[0] = '\0';
}

String::String(const char* str)
{
	size = strlen(str);
	capacity = size + 1;

	data = new char[capacity];
	strcpy(data, str);
}

String::String(const String& other)
{
	copyfrom(other);
}

String::String(String&& other) noexcept
{
	movefrom(std::move(other));
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

String& String::operator=(String&& other)
{
	if (this != &other) {
		free();
		movefrom(std::move(other));
	}
	return *this;
}

String::~String()
{
	free();
}
void String::push_back(char c)
{
	if (size + 1 >= capacity) {
		resize(capacity * 2);
	}

	data[size++] = c;
	data[size] = '\0';
}
String& String::operator+=(const String& other)
{
	if (size + other.size + 1 > capacity) {
		resize((size + other.size + 1) * 2);
	}

	for (size_t i = 0; i < other.size; i++) {
		data[size + i] = other.data[i];
	}

	size += other.size;
	data[size] = '\0';

	return *this;
}
bool String::operator==(const String& other) const
{
	return strcmp(data, other.data) == 0;
}
const char* String::print() const
{
		return data;
}
size_t String::length()const {
	return size;
}
const char& String::operator[](size_t index) const {
	return data[index];
}
char& String::operator[](size_t index) {
	return data[index];
}
String operator+(const String& a, const String& b) {
	String result = a;
	result += b;
	return result;
}