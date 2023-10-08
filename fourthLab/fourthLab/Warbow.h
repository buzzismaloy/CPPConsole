#pragma once
#include "Armament.h"

class Warbow : public Armament
{
public:
	Warbow(int rarity);
	virtual ~Warbow() = default;//виртуальный деструктор класса по умолчанию

private:
	const int MIN_DMG_BORDER{ 15 };//мин урон
	const int MAX_DMG_BORDER{ 35 };//правая граница для генерации урона
	const int MAX_AVAILABLE_DMG{ MAX_DMG_BORDER * static_cast<int>(Rarity::Mythical) };//максимально возможный урон
	const int MIN_END_BORDER{ 7 };//мин прочность
	const int MAX_END_BORDER{ 21 };// правая граница для генерации прочности
	const int MAX_AVAILABLE_END{ MAX_END_BORDER * static_cast<int>(Rarity::Mythical) };//максимально возможная прочность
	const int MIN_ATT_SPEED_BORDER{ 9 };//мин скорость атаки
	const int MAX_ATT_SPEED_BORDER{ 22 };//правая граница для генерации скорости атаки
	const int MAX_AVAILABLE_ATT_SPEED{ MAX_ATT_SPEED_BORDER * static_cast<int>(Rarity::Mythical) }; //максимально возможная скорость атаки

	void setAttackSpeed() override;
	void setDamage() override;
	void setEndurance() override;
};

