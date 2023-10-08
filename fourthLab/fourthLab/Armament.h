#pragma once
#include <iostream>
#include <vector>
#include "SpecialEffects.h"

enum class Rarity { Common = 1, Uncommon, Rare, Mythical }; //перечисление всех редкостей

const std::vector<std::string> all_types{"Spear", "Sword", "Warbow"};//конст вектор содержащий все типы оружий
const std::vector<std::string> all_rarities{"Common", "Uncommon", "Rare", "Mythical"};//строковые редкости

class Armament abstract
{
public:
	virtual ~Armament() = default;

	int getDamage() const;
	int getEndurance() const;
	int getAttackSpeed() const;
	int getRarity() const;
	int getModifier() const;
	std::string getSpecialEffect() const;

	//void printInfo();

protected:
	int damage{};//урон
	int endurance{};//прочность
	int attack_speed{};//скорость атаки
	int rarity{};//редкость
	int parameter_number{};//параметр в зависимости от которого редкость вли€ет на все характеристики или только на одну

	SpecialEffects special_effect; // экземпл€р эффекта

	void checkRarityModifier();

	virtual void setAttackSpeed() = 0;
	virtual void setDamage() = 0;
	virtual void setEndurance() = 0;

private:
	bool rarity_modifier{}; //как модифицировать с помощью редкости - один параметр или все

	void setRarityModifier();
};

