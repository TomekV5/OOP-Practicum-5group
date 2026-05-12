#pragma once
#include <iostream>
#include "Vector.hpp"
#include "Pair.hpp"

template <typename K, typename V>
class Map
{
	Vector<Pair<K, V>> data;

public:
	Map();
	void add(const K& key, const V& value);
	void add(const K& key, V&& value);
	void remove(const K& key);
	bool contains(const K& key);
	V operator[](const K& key);
	size_t size();
	size_t capacity();
	size_t empty();
};

template<typename K, typename V>
Map<K, V>::Map()
{
}

template<typename K, typename V>
void Map<K, V>::add(const K& key, const V& value)
{
	if (!contains(key))
	{
		data.push_back({ key, value });
	}
}

template<typename K, typename V>
inline void Map<K, V>::add(const K& key, V&& value)
{
	if (!contains(key))
	{
		data.push_back({ key, std::move(value) });
	}
}

template<typename K, typename V>
void Map<K, V>::remove(const K& key)
{
	size_t idx = -1;
	for (size_t i = 0; i < data.getSize(); i++)
	{
		auto& curr = data[i];
		if (curr.first == key)
		{
			idx = i;
			break;
		}
	}

	// отново, все още не сме учили изключения, затова правим това преминаване през idx == -1
	if (idx == -1) 
	{
		return;
	}
	data.erase(idx);
}

template<typename K, typename V>
bool Map<K, V>::contains(const K& key)
{
	for (const Pair<K, V>& curr : data)
	{
		if (curr.first == key)
		{
			return true;
		}
	}

	return false;
}

template<typename K, typename V>
V Map<K, V>::operator[](const K& key)
{
	for (const Pair<K, V>& curr : data) 
	{
		if (curr.first == key) 
		{
			return curr.second;
		}
	}

	// това не е добра практика, понеже не знаем дали V има default-ен конструктор, 
	// ще се върнем отново като вземем изключения (друга опция е да помислим как да променим типа на връщане, че да нямаме този проблем)
	return V();
}

template<typename K, typename V>
size_t Map<K, V>::size()
{
	return data.getSize();
}

template<typename K, typename V>
size_t Map<K, V>::capacity()
{
	return data.getCapacity();
}

template<typename K, typename V>
size_t Map<K, V>::empty()
{
	return data.empty();
}
