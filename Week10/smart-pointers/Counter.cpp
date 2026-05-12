#include "Counter.h"

void Counter::addSharedPtr()
{
	sharedCount++;

	// винаги имаме един "имплицитен" weakptr при първото добавяне на един sharedptr
	// тъй като живота на брояча зависи и от weakCount
	if (sharedCount == 1) 
	{
		weakCount++;
	}
}

void Counter::removeSharedPtr()
{
	sharedCount--;
	if (sharedCount == 0)
	{
		weakCount--;
	}
}

void Counter::addWeakPtr()
{
	weakCount++;
}

void Counter::removeWeakPtr()
{
	weakCount--;
}
