#pragma once
#include "Computer_Peripheral.h"
class Mouse: public Computer_Peripheral
{
private:
	bool connectivity;
public:
	Mouse(const std::string& model, double price, const std::string& manufacturer, bool connectivity);
};

