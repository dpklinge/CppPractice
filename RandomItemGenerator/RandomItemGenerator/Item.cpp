#include "Item.h"
std::string& operator+(std::string& o, Size s)
{
	static std::array<const char*, 4> enumNames = { "Small", "Medium", "Large", "Giant" };
	o += enumNames[static_cast<int>(s)];
	return o;
}

std::string Item::describeItem()
{
	std::string description = "";
	description += "Name: " + name + "\nDescription: " + description + "\nWeight: " + std::to_string(weight) +"\nSize: ";
	description = description+size+"\n";
	return description;
}

Item::Item(std::string name, std::string description, double weight, Size size) : name{name}, description{description}, weight{weight}, size{size} {}

