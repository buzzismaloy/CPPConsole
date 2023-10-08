#pragma once
#include "WeaponExample.h"
class WeaponShop
{
public:
	WeaponShop();
	~WeaponShop();

	void startInteraction();
private:
	WeaponExample* weapon_exmpl;//указатель на WeaponExample

	//const int MYTHICAL_AMOUNT{ 1 };
	const int RARE_AMOUNT{ 2 };//количество редкого оружия
	const int UNCOMMON_AMOUNT{ 3 };//количество необычного оружия
	const int COMMON_AMOUNT{ 4 };//количество обычного оружия

	const int MULTIPLIER{ 1000 };//множитель для подсчета стоимости оружия
	const int MYTHICAL_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Mythical) }; //цена мифического оружия
	const int RARE_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Rare) };//цена редкого оружия
	const int UNCOMMON_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Uncommon) };//цена необычного оружия
	const int COMMON_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Common) };//цена обычного оружия
	
	int min_selected_rarity{};//выбранная редкость в соответствии с бюджетом пользователя
	std::string selected_type{};//выбранный тип оружия

	std::vector<WeaponExample*> v_weapon;//вектор оружий

	void fillTheVector();
	void interactionWithUser();
	void checkUserMoney();
	void checkWeaponTypeChoice();
	void printSelectedWeapons();
	
	void printRarityModifier(int modifier);
	std::string getRarityName(int rarity);
	
};

