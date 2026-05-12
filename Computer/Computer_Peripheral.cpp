#include "Computer_Peripheral.h"

std::string Computer_Peripheral::getModel()
{
	return model;
}

double Computer_Peripheral::getPrice()
{
	return price;
}

std::string Computer_Peripheral::getManufacturer()
{
	return manufacturer;
}

bool Computer_Peripheral::setPrice(double price)
{
	if (0 <= price) {
		this->price = price;
		return true;
	}
	return false;
}

Computer_Peripheral::Computer_Peripheral(const std::string& model, double price, const std::string& manufacturer):model(model),price(price),manufacturer(manufacturer)
{
}
