#pragma once
#include <vector>
#include "Computer_Peripheral.h"
enum class Language {
	EN,
	BG,
	ES,
	FR,
	DE,
};
class Keyboard:public Computer_Peripheral
{
private:
	std::string color;
	std::vector<Language> language;
public:
	Keyboard(const std::string& model, double price, const std::string& manufacturer, const std::string& color, const std::vector<Language>& language);
};

