#pragma once
#include "Pair.hpp"
#include <utility>

template <typename K, typename V>
class Map {
	Pair* data;
	size_t size;
	size_t capacity;

	void resize(size_t newCapacity);
	void copyFrom(const Map& other);
	void moveFrom(Map&& other) noexcept;
	void free();
	int findIndex(const K& key) const;
public:
	Map() : size(0), capacity(4);
	Map(const Map& other);
	Map(Map&& other) noexcept;
	Map& operator=(const Map& other);
	Map& operator=(Map&& other) noexcept;
	~Map();
	void add(const K& key, const V& value);
	void add(const K& key, V&& value);
	void remove(const K& key);
	bool contains(const K& key) const;
	V& operator[](const K& key);
	const V& operator[](const K& key) const;
	size_t getSize() const;
	size_t getCapacity() const;
	bool empty() const;
};

template<typename K, typename V>
void Map<K, V>::resize(size_t newCapacity) {
	capacity = newCapacity;
	Pair* newData = new Pair[capacity];

	for (size_t i = 0; i < size; i++) {
		newData[i] = std::move(data[i]);
	}

	delete[] data;
	data = newData;
}

template<typename K, typename V>
void Map<K, V>::copyFrom(const Map& other) {
	data = new Pair[other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template<typename K, typename V>
inline void Map<K, V>::moveFrom(Map&& other) noexcept
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;
	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename K, typename V>
void Map<K, V>::free() {
	delete[] data;
}

template<typename K, typename V>
int Map<K, V>::findIndex(const K& key) const {
	for (size_t i = 0; i < size; i++) {
		if (data[i].key == key)
			return i;
	}
	return -1;
}

template<typename K, typename V>
Map<K, V>::Map() : size(0), capacity(4) {
	data = new Pair[capacity];
}

template<typename K, typename V>
Map<K, V>::Map(const Map& other) {
	copyFrom(other);
}

template<typename K, typename V>
inline Map<K, V>::Map(Map&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename K, typename V>
Map<K, V>& Map<K, V>::operator=(const Map& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename K, typename V>
Map<K, V>& Map<K, V>::operator=(Map&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename K, typename V>
Map<K, V>::~Map() {
	free();
}

template<typename K, typename V>
void Map<K, V>::add(const K& key, const V& value) {
	if (contains(key)) return;

	if (size >= capacity)
		resize(capacity + 10);

	data[size++] = { key, value };
}

template<typename K, typename V>
void Map<K, V>::add(const K& key, V&& value) {
	if (contains(key)) return;

	if (size >= capacity)
		resize(capacity + 10);

	data[size].key = key;
	data[size].value = std::move(value);
	size++;
}

template<typename K, typename V>
void Map<K, V>::remove(const K& key) {
	int index = findIndex(key);
	if (index == -1) return;

	for (size_t i = index; i < size - 1; i++) {
		data[i] = std::move(data[i + 1]);
	}

	size--;
}

template<typename K, typename V>
bool Map<K, V>::contains(const K& key) const {
	return findIndex(key) != -1;
}

template<typename K, typename V>
V& Map<K, V>::operator[](const K& key) {
	int index = findIndex(key);

	if (index == -1) {
		throw std::out_of_range("Key not found");
	}

	return data[index].value;
}

template<typename K, typename V>
const V& Map<K, V>::operator[](const K& key) const {
	int index = findIndex(key);

	if (index == -1) {
		throw std::out_of_range("Key not found");
	}

	return data[index].value;
}

template<typename K, typename V>
size_t Map<K, V>::getSize() const {
	return size;
}

template<typename K, typename V>
size_t Map<K, V>::getCapacity() const {
	return capacity;
}

template<typename K, typename V>
bool Map<K, V>::empty() const {
	return size == 0;
}