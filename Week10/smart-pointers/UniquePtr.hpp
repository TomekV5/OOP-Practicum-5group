#pragma once
#include <utility>
#include <iostream>

template <typename T>
class UniquePtr 
{
	T* ptr = nullptr;
	
	void moveFrom(UniquePtr<T>&& other);
	void free();

public:
	UniquePtr() = default;
	UniquePtr(T* ptr);
	UniquePtr(const UniquePtr<T>& other) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;
	UniquePtr(UniquePtr<T>&& other) noexcept;
	UniquePtr<T>& operator=(UniquePtr<T>&& other) noexcept;
	~UniquePtr();

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

	T* get();
	const T* get() const;

	bool isInitialized() const;
	operator bool() const;

	T* release();
	void reset();
};

template<typename T>
void UniquePtr<T>::moveFrom(UniquePtr<T>&& other)
{
	this->ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
void UniquePtr<T>::free()
{
	delete ptr;
	this->ptr = nullptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr)
{
	this->ptr = ptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept
{
	if (this != &other) 
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	free();
}

template<typename T>
T& UniquePtr<T>::operator*()
{
	/*
	* в случая е хубаво да хвърлим някаква грешка, 
	ако имаме nullptr (опитваме се да го дереферираме) но все още не сме учили изключения
	*/
	if (!ptr) {
		return nullptr;
	}

	return *ptr;
}

template<typename T>
const T& UniquePtr<T>::operator*() const
{
	if (!ptr) {
		return nullptr;
	}

	return *ptr;
}

template<typename T>
T* UniquePtr<T>::operator->()
{
	return ptr;
}

template<typename T>
const T* UniquePtr<T>::operator->() const
{
	return ptr;
}

/*
идеята на get е просто да вземем указателя; 
въпреки че operator-> има абсолютно същия код, неговата цел е да запази всички 
функционалности на нормалния указател, една от които е именно този оператор

struct A {
	int a
	...
}

int main() {
	A* ptr;

	ptr->a = 5;  ===> именно тази операция се опитваме да запазим при UniquePtr
}
*/
template<typename T>
T* UniquePtr<T>::get()
{
	return ptr;
}

template<typename T>
const T* UniquePtr<T>::get() const
{
	return ptr;
}

template<typename T>
bool UniquePtr<T>::isInitialized() const
{
	return ptr != nullptr;
}

/*
ето пример как понякога можем да предефинираме как наш клас да се третира 
като bool - не толкова като самия тип данни, а логическото условие true/false

именно това в нормалните указатели ни позволява да пишем

char* str;
while (str) {
	...
}

вместо да пишем условие str != nullptr
*/

template<typename T>
UniquePtr<T>::operator bool() const
{
	return isInitialized();
}

template<typename T>
T* UniquePtr<T>::release()
{
	T* toReturn = ptr;
	ptr = nullptr;
	return toReturn;
}

template<typename T>
void UniquePtr<T>::reset()
{
	free();
}
