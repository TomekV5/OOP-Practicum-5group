#include "Album.h"
Team& Album::operator[](size_t index) {
	return teams.at(index);
}
const Team& Album::operator[](size_t index)const {
	return teams.at(index);
}

void Album::getPage(size_t page)
{
	std::cout << teams.at(page);
}