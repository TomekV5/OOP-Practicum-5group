#include "Monitor.h"

Monitor::Monitor(const std::string& model, double price, const std::string& manufacturer, double refresh_rate, double size):Computer_Peripheral(model,price,manufacturer), refresh_rate(refresh_rate),size(size)
{
}
