#include "Headphones.h"

Headphones::Headphones(const std::string& model, double price, const std::string& manufacturer, bool connectivity, bool microphone):Computer_Peripheral(model,price,manufacturer),connectivity(connectivity),microphone(microphone)
{
}
