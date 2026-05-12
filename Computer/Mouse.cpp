#include "Mouse.h"

Mouse::Mouse(const std::string& model, double price, const std::string& manufacturer, bool connectivity):Computer_Peripheral(model,price,manufacturer),connectivity(connectivity)
{
}