#pragma once
#include <string>
#include <iostream>
#include <array>
enum class Size{ small, medium, large, giant};
struct Item
{

	const std::string name;
	const std::string description;
	const double weight;
	const Size size;
	std::string describeItem();
	Item(std::string name, std::string description, double weight, Size size);

};

