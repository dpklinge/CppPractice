// RandomItemGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include <time.h>
#include <vector>
#include "Weapon.h"
#include <functional>





class ItemGenerator {
	std::vector<std::function<Weapon(int)>> weaponGenerators;
public:
	void addGenerator(std::string weaponType, int minMinDamage, int maxMinDamage, double levelModifierMinDamage, int minMaxDamage, int maxMaxDamage, double levelModifierMaxDamage, int weakThreshHold, int strongThreshHold, double weightMin, double weightMax, double weightLevelModifier, double lightThreshHold, double heavyThreshHold, double attackSpeedMin, double attackSpeedMax, double attackSpeedLevelModifier, double slowThreshHold, double fastThreshHold, double critChanceMin, double critChanceMax, double critChanceLevelMultiplier, double dullThreshHold, double vorpalThreshHold) {
		
		weaponGenerators.push_back([weaponType, minMinDamage, maxMinDamage, levelModifierMinDamage, minMaxDamage, maxMaxDamage, levelModifierMaxDamage, weakThreshHold, strongThreshHold, weightMin, weightMax, weightLevelModifier, lightThreshHold, heavyThreshHold, attackSpeedMin, attackSpeedMax, attackSpeedLevelModifier, slowThreshHold, fastThreshHold, critChanceMin, critChanceMax, critChanceLevelMultiplier, dullThreshHold, vorpalThreshHold](int level)->Weapon {
			std::string appellate = "";
			int minDamage = rand() % (maxMinDamage - minMinDamage+1) + minMinDamage + (int)(levelModifierMinDamage * (double)level);
			int maxDamage = rand() % (maxMaxDamage - minMaxDamage+1) + minMaxDamage + (int)(levelModifierMinDamage * (double)level);
			if (maxDamage <= weakThreshHold) {
				appellate += "Weak ";
			}
			else if (maxDamage >= strongThreshHold) {
				appellate += "Strong ";
			}
			double attackSpeed = (rand() % ((int)(100 * (attackSpeedMax - attackSpeedMin))) / 100.0) + attackSpeedMin + (attackSpeedLevelModifier * level);
			if (attackSpeed < slowThreshHold) {
				appellate += "Slow ";
			}
			else if (attackSpeed > fastThreshHold) {
				appellate += "Fast ";
			}
			double critChance = (rand() % ((int)(100 * (critChanceMax - critChanceMin))) / 100.0) + critChanceMin + (critChanceLevelMultiplier * level);
			if (critChance > vorpalThreshHold) {
				appellate += "Vorpal ";
			}
			else if (critChance < dullThreshHold) {
				appellate += "Dull ";
			}
			double weight = (rand() % ((int)(10 * (weightMax - weightMin))) / 10.0) + weightMin - (weightLevelModifier * level);
			if (weight < lightThreshHold) {
				appellate += "Light ";
			}
			else if (weight > heavyThreshHold) {
				appellate += "Heavy ";
			}
			std::string name = appellate + weaponType;
			std::string description = "tempDescription";
			Weapon weapon{ name, description, weight, Size::medium, minDamage, maxDamage,attackSpeed,critChance };
			return weapon;
			});
		std::cout << "Added generator of type " << weaponType << "; total generator types: " << weaponGenerators.size()<< std::endl;
	}
	ItemGenerator() {
		srand((unsigned)time(0));
		addGenerator("Long Blade", 1, 2, .5, 5, 8, .5, 4, 8, 2, 3, .1, 1.9, 2.5, .25, .75, .05, .4, .7, .05, .15, .01, .08, .14);
		addGenerator("Short Blade", 1, 1, .5, 3, 5, .5, 3, 6, 1, 2, .1, 1, 1.7, .5, 1, .05, .6, .95, .1, .2, .02, .15, .22);
		addGenerator("Battleaxe", 1, 5, 1, 6, 12, 1, 9, 14, 4, 6, .1, 4.1, 5.5, .15, .25, .01, .2, .25, .05, .2, .01, .07, .2);
	}
	Weapon generateWeapon(int level) {
		
			int choice = rand() % (weaponGenerators.size());
			std::cout << "Picking random generator: " << choice << std::endl;
			return weaponGenerators[choice](level);
		
	}

};


int main()
{
	ItemGenerator generator;
	while (true) {
		int level = rand() % 4 + 1;
		std::cout << "Item of level " << level << ": " + generator.generateWeapon(level).describeItem();
		std::string input;
		std::getline(std::cin, input);
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
