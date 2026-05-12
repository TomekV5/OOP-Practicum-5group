#pragma once
#include "Computer_Peripheral.h"
class Headphones:public Computer_Peripheral
{
private:
	bool connectivity;
	bool microphone;
public:
	Headphones(const std::string& model, double price, const std::string& manufacturer, bool connectivity, bool microphone);
};