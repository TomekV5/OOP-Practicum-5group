#include "Keyboard.h"

Keyboard::Keyboard(const std::string& model, double price, const std::string& manufacturer, const std::string& color, const std::vector<Language>& language):Computer_Peripheral(model,price,manufacturer), color(color),language(language)
{
	if (this->language.size() > 2) {
		this->language.resize(2);
	}
}
