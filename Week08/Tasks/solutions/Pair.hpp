#pragma once

template <typename K, typename V>
struct Pair
{
	K first;
	V second;

	Pair();
	Pair(const K& first, const V& second);
	Pair(const K& first, V&& second);

	friend bool operator==(const Pair<K, V>& lhs, const Pair<K, V>& rhs);
	friend bool operator!=(const Pair<K, V>& lhs, const Pair<K, V>& rhs);
};

template<typename K, typename V>
Pair<K, V>::Pair() : first(), second()
{}

template<typename K, typename V>
Pair<K, V>::Pair(const K& first, const V& second) : first(first), second(second)
{}

template<typename K, typename V>
Pair<K, V>::Pair(const K& first, V&& second) : first(first), second(std::move(second))
{
}

template<typename K, typename V>
bool operator==(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
{
	/*
	зависи от реализацията / какво искаме за конкретната задача, 
	може да се наложи да сравним first и second; 
	засега приемаме, че pair е еднозначно определено от ключа си
	*/
	return lhs.first == rhs.first;
}

template<typename K, typename V>
bool operator!=(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
{
	return !(lhs == rhs);
}
