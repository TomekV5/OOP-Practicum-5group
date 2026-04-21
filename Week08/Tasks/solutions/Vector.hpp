#pragma once
#include <iostream>

template  <typename T>
class Vector
{
	const size_t INITIAL_CAPACITY = 8;

	T* data;
	size_t size;
	size_t capacity;
	
	void free();
	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other);
	void resize();

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, const T& obj);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector& operator=(Vector&& other) noexcept;
	~Vector();

	size_t getSize() const;
	size_t getCapacity() const;

	void push_back(const T& obj);
	void push_back(T&& obj);
	void pop_back();

	void insert(size_t idx, const T& obj);
	void insert(size_t idx, T&& obj);
	void erase(size_t idx);

	T* begin();
	T* end();

	const T* begin() const;
	const T* end() const;

	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	void shrink_to_fit();

	bool empty();
	void clear();
};

template<typename T>
void Vector<T>::free()
{
	delete[] data;

	size = 0;
	capacity = 0;
}

template<typename T>
void Vector<T>::copyFrom(const Vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new T[other.capacity];

	for (size_t i = 0; i < other.size; i++) 
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
void Vector<T>::moveFrom(Vector&& other)
{
	this->data = other.data;
	other.data = nullptr;

	this->size = other.size;
	this->capacity = other.capacity;
}

template<typename T>
void Vector<T>::resize()
{
	size_t newCapacity = capacity * 2;
	T* temp = new T[newCapacity];

	for (size_t i = 0; i < size; i++) 
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;

}

template<typename T>
Vector<T>::Vector()
{
	this->capacity = INITIAL_CAPACITY;
	this->size = 0;

	this->data = new T[INITIAL_CAPACITY];
}

template<typename T>
Vector<T>::Vector(size_t n)
{
	this->capacity = n;
	this->size = 0;

	this->data = new T[n];
}

template<typename T>
Vector<T>::Vector(size_t n, const T& obj)
{
	this->size = this->capacity = n;

	this->data = new T[n];
	for (size_t i = 0; i < n; i++)
	{
		this->data[i] = obj;
	}
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
	copyFrom(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
{

	moveFrom(std::move(other));
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}

template<typename T>
size_t Vector<T>::getSize() const
{
	return size;
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void Vector<T>::push_back(const T& obj)
{
	if (capacity == size) 
	{
		resize();
	}

	data[size++] = obj;
}

template<typename T>
void Vector<T>::push_back(T&& obj)
{
	if (capacity == size)
	{
		resize();
	}

	data[size++] = std::move(obj);
}

template<typename T>
void Vector<T>::pop_back()
{
	/*
	тъй като size ни се явява указател към края на масива / позицията, на която ще добавим елемент с push_back, 
	e достатъчно просто да намалим size - при следващото добавяне на елемент просто ще презапишем този, 
	който е бил там(който уж сме изтрили)
	*/
	if (size > 0)
	{
		size--;
	}
}

template<typename T>
void Vector<T>::insert(size_t idx, const T& obj)
{
	if (idx > size)
	{
		return;
	}

	if (size == capacity)
	{
		resize();
	}

	for (size_t i = size; i > idx; i--)
	{
		data[i] = data[i - 1];
	}

	data[idx] = obj;
	size++;
}

template<typename T>
void Vector<T>::insert(size_t idx, T&& obj)
{
	if (idx > size)
	{
		return;
	}

	if (size == capacity)
	{
		resize();
	}

	for (size_t i = size; i > idx; i--)
	{
		data[i] = data[i - 1];
	}

	data[idx] = std::move(obj);
	size++;
}

template<typename T>
void Vector<T>::erase(size_t idx)
{
	// тук вече idx == size не е валидно, защото нямаме какво да махаме
	if (idx >= size) 
	{
		return;
	}

	for (size_t i = idx; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
T* Vector<T>::begin()
{
	return data;
}

template<typename T>
T* Vector<T>::end()
{
	return data + size;
}

template<typename T>
const T* Vector<T>::begin() const
{
	return data;
}

template<typename T>
const T* Vector<T>::end() const
{
	return data + size;
}

template<typename T>
T& Vector<T>::operator[](size_t idx)
{
	// за момента все още не сме учили изключения, така че го оставяме така, 
	// въпреки че програмата ще се счупи при невалиден индекс
	
	/*
	if (idx > size) 
	{
		return ... -> не знаем какво да върнем
	}
	*/
	return data[idx];
}

template<typename T>
const T& Vector<T>::operator[](size_t idx) const
{
	return data[idx];
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
	capacity = size;
	T* temp = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;
}

template<typename T>
bool Vector<T>::empty()
{
	return size == 0;
}

template<typename T>
void Vector<T>::clear()
{
	size = 0;
}
