#include "Armament.h"

int Armament::getDamage() const//геттер урона
{
	return this->damage;
}

int Armament::getEndurance() const//геттер прочности
{
	return this->endurance;
}

int Armament::getAttackSpeed() const//геттер скорости атаки
{
	return this->attack_speed;
}

int Armament::getRarity() const//геттер редкости
{
	return this->rarity;
}

int Armament::getModifier() const//геттер параметра отвечающего за то как модифицировать характеристики
{
	return this->parameter_number;
}

std::string Armament::getSpecialEffect() const {//геттер специального эффекта
	return special_effect.getSpecialEffect();
}

void Armament::checkRarityModifier()//сеттер параметра модификации от которого зависит как модифицировать характеристики
{
	setRarityModifier();
	if (rarity_modifier) parameter_number = rand() % 3;
	else parameter_number = -1;
}

void Armament::setRarityModifier()//сеттер параметра от которого зависит тип модификации характеристик
{
	switch (rand() % 2) {
	case 0:
		rarity_modifier = false;
		break;
	case 1:
		rarity_modifier = true;
		break;
	}
}
