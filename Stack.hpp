#pragma once
#include <utility>
template <typename T> class Stack
{
private:
	size_t size;
	size_t capacity;
	T* data = nullptr;
	void movefrom(Stack&& other);
	void copyfrom(const Stack& other);
	void free();
	void resize(size_t newCapacity);
public:
	Stack();
	Stack(const Stack& other);
	Stack(Stack&& other) noexcept;
	Stack<T>& operator=(const Stack<T>& other);
	Stack<T>& operator=(Stack<T>&& other) noexcept;
	~Stack();
	void push(const T& obj);
	void push(T&& obj);
	void pop();
	const T& top() const;
	size_t Size() const;
	bool empty();
};

template<typename T>
void Stack<T>::movefrom(Stack&& other)
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void Stack<T>::copyfrom(const Stack& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++) {
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}

template<typename T>
void Stack<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 8;
}

template<typename T>
void Stack<T>::resize(size_t newCapacity)
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
Stack<T>::Stack()
{
	capacity = 8;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	copyfrom(other);
}

template<typename T>
Stack<T>::Stack(Stack&& other) noexcept
{
	movefrom(std::move(other));
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other) noexcept
{
	if (this != &other) {
		free();
		movefrom(std::move(other));
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	free();
}

template<typename T>
void Stack<T>::push(const T& obj)
{
	if (size >= capacity) {
		resize(capacity + 10);
	}
	data[size++] = obj;
}

template<typename T>
void Stack<T>::push(T&& obj)
{
	if (size >= capacity) {
		resize(capacity + 10);
	}
	data[size++] = std::move(obj);
}

template<typename T>
void Stack<T>::pop()
{
	if (!empty()) {
		size--;
	}
}

template<typename T>
const T& Stack<T>::top() const {
	return data[size - 1];
}

template<typename T>
size_t Stack<T>::Size() const {
	return size;
}

template<typename T>
bool Stack<T>::empty() {
	return size == 0;
}