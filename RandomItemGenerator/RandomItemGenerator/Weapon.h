#pragma once
#include "Item.h"
#include <string>
class Weapon :
	public Item
{
public:
	const int minDamage;
	const int maxDamage;
	const double critChance;
	const double attackSpeed;
	std::string describeItem();
	Weapon(std::string name, std::string description, double weight, Size size, int minDamage, int maxDamage, double attackSpeed, double critChance);
};

