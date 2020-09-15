#include "Weapon.h"
#include <sstream>
#include <iomanip>

Weapon::Weapon(std::string name, std::string description, double weight, Size size, int minDamage, int maxDamage, double attackSpeed, double critChance) : Item{ name, description, weight, size }, minDamage{ minDamage }, maxDamage{ maxDamage }, attackSpeed{ attackSpeed }, critChance{ critChance } {};
std::string Weapon::describeItem() {
	std::string description = Item::describeItem();
	description += "Damage: " + std::to_string(minDamage) + " - " + std::to_string(maxDamage) + "\n";
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << std::to_string(this->critChance * 100);
	std::string critChance = stream.str();
	description += "Crit chance: %" + critChance + "\n";
	stream.str(std::to_string(this->attackSpeed ));
	std::string attackSpeed = stream.str();
	description += "Attack speed: " + attackSpeed+ "\n";
	return description;
}