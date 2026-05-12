#pragma once
#include <string>
class Computer_Peripheral
{
protected:
	std::string model;
	double price;
	std::string manufacturer;
public:
	std::string getModel();
	double getPrice();
	std::string getManufacturer();
	bool setPrice(double price);
	Computer_Peripheral(const std::string& model, double price, const std::string& manufacturer);
};