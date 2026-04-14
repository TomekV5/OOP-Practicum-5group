#pragma once
#include <utility>
template <typename T> class Queue
{
private:
	size_t size;
	size_t capacity;
	T* data = nullptr;
	void movefrom(Queue&& other);
	void copyfrom(const Queue& other);
	void free();
	void resize(size_t newCapacity);
public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other) noexcept;
	Queue<T>& operator=(const Queue<T>& other);
	Queue<T>& operator=(Queue<T>&& other) noexcept;
	~Queue();
	void push(const T& obj);
	void push(T&& obj);
	void pop();
	const T& front() const;
	const T& back() const;
	size_t Size() const;
	bool empty();
};

template<typename T>
void Queue<T>::movefrom(Queue&& other)
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void Queue<T>::copyfrom(const Queue& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++) {
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}

template<typename T>
void Queue<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 8;
}

template<typename T>
void Queue<T>::resize(size_t newCapacity)
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
Queue<T>::Queue()
{
	capacity = 8;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Queue<T>::Queue(const Queue& other)
{
	copyfrom(other);
}

template<typename T>
Queue<T>::Queue(Queue&& other) noexcept
{
	movefrom(std::move(other));
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept
{
	if (this != &other) {
		free();
		movefrom(std::move(other));
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	free();
}

template<typename T>
void Queue<T>::push(const T& obj)
{
	if (size >= capacity) {
		resize(capacity + 10);
	}
	data[size++] = obj;
}

template<typename T>
void Queue<T>::push(T&& obj)
{
	if (size >= capacity) {
		resize(capacity + 10);
	}
	data[size++] = std::move(obj);
}

template<typename T>
void Queue<T>::pop()
{
	for (int i = 0; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
const T& Queue<T>::front() const {
	return data[0];
}

template<typename T>
const T& Queue<T>::back() const {
	return data[size - 1];
}

template<typename T>
size_t Queue<T>::Size() const {
	return size;
}

template<typename T>
bool Queue<T>::empty() {
	return size == 0;
}