#pragma once
class Counter
{
	unsigned sharedCount = 0;
	unsigned weakCount = 0;

	Counter() = default;

	void addSharedPtr();
	void removeSharedPtr();
	void addWeakPtr();
	void removeWeakPtr();
};
