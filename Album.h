#pragma once
#include <vector>
#include "Team.h"
class Album
{
private:
	vector<Team> teams;
public:
	Album() = default;
	Team& operator[](size_t index);
	const Team& operator[](size_t index) const;
	void getPage(size_t page);
};

