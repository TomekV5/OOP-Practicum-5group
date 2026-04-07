#pragma once
class Vector
{
private:
	int size;
	int capacity;
	int* data = nullptr;
	void movefrom(Vector&& other);
	void copyfrom(const Vector& other);
	void free();
	void resize();
public:
	Vector();
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other) noexcept;
	~Vector();
	void push_back(const int& number);
	int getSize();
	int& at(int index);
	int& operator[](int index);
	const int& operator[](int index) const;
	void pop_back();
	int getCapacity();
	bool isEmpty();
};