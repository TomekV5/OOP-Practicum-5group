#pragma once
#include "Computer_Peripheral.h"
class Monitor:public Computer_Peripheral
{
private:
	double refresh_rate;
	double size;
public:
	Monitor(const std::string& model, double price, const std::string& manufacturer, double refresh_rate, double size);
};