#pragma once
#include "Armament.h"

class Spear : public Armament
{
public:
	Spear(int rarity);
	virtual ~Spear() = default;

private:
	const int MIN_DMG_BORDER{ 10 };//мин урон
	const int MAX_DMG_BORDER{ 25 };//правая граница для генерации урона
	const int MAX_AVAILABLE_DMG{ MAX_DMG_BORDER * static_cast<int>(Rarity::Mythical) }; //максимально возможный урон
	const int MIN_END_BORDER{ 15 };//мин прочность
	const int MAX_END_BORDER{ 50 };//правая граница для генерации прочности
	const int MAX_AVAILABLE_END{ MAX_END_BORDER  * static_cast<int>(Rarity::Mythical) }; //максимально возможная прочность
	const int MIN_ATT_SPEED_BORDER{ 5 };//мин скорость атаки
	const int MAX_ATT_SPEED_BORDER{ 20 };//правая граница для генерации скорости атаки
	const int MAX_AVAILABLE_ATT_SPEED{ MAX_ATT_SPEED_BORDER * static_cast<int>(Rarity::Mythical) }; //максимально возможная скорость атаки

	void setAttackSpeed() override;
	void setDamage() override;
	void setEndurance() override;
};

