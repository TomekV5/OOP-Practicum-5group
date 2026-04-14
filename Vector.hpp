#pragma once
#include <utility>
template <typename T> class Vector
{
private:
	size_t size;
	size_t capacity;
	T* data = nullptr;
	void movefrom(Vector&& other);
	void copyfrom(const Vector& other);
	void free();
	void resize(size_t newCapacity);
public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, const T& obj);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other) noexcept;
	~Vector();
	void push_back(const T& obj);
	void push_back(T&& obj);
	bool insert(size_t idx, const T& obj);
	bool insert(size_t idx, T&& obj);
	bool erase(size_t idx);
	T& begin();
	const T& begin() const;
	T& end();
	const T& end() const;
	size_t Size() const;
	size_t Capacity();
	T& operator[](int index);
	const T& operator[](int index) const;
	void shrink_to_fit();
	bool empty();
	void clear();
};

template<typename T>
void Vector<T>::movefrom(Vector&& other)
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void Vector<T>::copyfrom(const Vector& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++) {
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}

template<typename T>
void Vector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 8;
}

template<typename T>
void Vector<T>::resize(size_t newCapacity)
{
	capacity = newCapacity;
	T* newData = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		newData[i] = std::move(data[i]);
	}
	delete[] data;
	data = newData;
}

template <typename T>
Vector<T>::Vector()
{
	capacity = 8;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(size_t n)
{
	capacity = size = n;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(size_t n, const T& obj)
{
	capacity = size = n;
	data = new T[capacity]{ obj };
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
	copyfrom(other);
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
{
	movefrom(std::move(other));
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other) {
		free();
		movefrom(std::move(other));
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	free();
}

template<typename T>
void Vector<T>::push_back(const T& obj)
{
	if (size >= capacity) {
		resize(capacity + 10);
	}
	data[size++] = obj;
}

template<typename T>
void Vector<T>::push_back(T&& obj)
{
	if (size >= capacity) {
		resize(capacity + 10);
	}
	data[size++] = std::move(obj);
}

template<typename T>
bool Vector<T>::insert(size_t idx, const T& obj)
{
	if (idx >= size || idx < 0) {
		return false;
	}
	if ((size + 1) >= capacity) {
		resize(capacity + 10);
	}
	for (int i = size; idx < i; i--) {
		data[i + 1] = data[i];
	}
	data[idx] = obj;
	size++;
	return true;
}

template<typename T>
bool Vector<T>::insert(size_t idx, T&& obj)
{
	if (idx >= size || idx < 0) {
		return false;
	}
	if ((size + 1) >= capacity) {
		resize(capacity + 10);
	}
	for (int i = size; idx <= i; i--) {
		data[i + 1] = data[i];
	}
	data[idx] = std::move(obj);
	size++;
	return true;
}

template<typename T>
bool Vector<T>::erase(size_t idx)
{
	if (idx >= size || idx < 0) {
		return false;
	}
	for (int i = idx; i <= size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
	return true;
}

template<typename T>
T& Vector<T>::begin() {
	return data[0];
}

template<typename T>
const T& Vector<T>::begin() const {
	return data[0];
}

template<typename T>
T& Vector<T>::end() {
	return data[size - 1];
}

template<typename T>
const T& Vector<T>::end() const {
	return data[size - 1];
}

template<typename T>
size_t Vector<T>::Size() const {
	return size;
}

template<typename T>
size_t Vector<T>::Capacity()
{
	return capacity;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
	return data[index];
}

template<typename T>
const T& Vector<T>::operator[](int index) const
{
	return data[index];
}

template<typename T>
void Vector<T>::shrink_to_fit() {
	capacity = size;
	resize(capacity);
}

template<typename T>
bool Vector<T>::empty() {
	return size == 0;
}

template<typename T>
void Vector<T>::clear() {
	size = 0;
}