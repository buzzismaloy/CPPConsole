#include "WeaponShop.h"
#include "MyReadKeyBoard.h"

WeaponShop::WeaponShop() {//конструктор класса в котором вызывается функция для заполнения вектора оружий
	fillTheVector();
}

/* данная функция не принимает аргументы и не возвращает
* данная функция заполняет вектор оружий
*/
void WeaponShop::fillTheVector() {
	for (auto j : all_types) {
		for (int i = 0; i < COMMON_AMOUNT; ++i) {
			weapon_exmpl = new WeaponExample{ j, static_cast<int>(Rarity::Common) };
			v_weapon.push_back(weapon_exmpl);
			//WeaponExample weapon_example{ j, static_cast<int>(Rarity::Common) };
			//v_weapon.push_back(weapon_example);
		}
		
		for (int i = 0; i < UNCOMMON_AMOUNT; ++i) {
			//WeaponExample weapon_example{ j, static_cast<int>(Rarity::Uncommon) };
			//v_weapon.push_back(weapon_example);
			weapon_exmpl = new WeaponExample{ j, static_cast<int>(Rarity::Uncommon) };
			v_weapon.push_back(weapon_exmpl);
		}

		for (int i = 0; i < RARE_AMOUNT; ++i) {
			//WeaponExample weapon_example{ j, static_cast<int>(Rarity::Rare) };
			//v_weapon.push_back(weapon_example);
			weapon_exmpl = new WeaponExample{ j, static_cast<int>(Rarity::Rare) };
			v_weapon.push_back(weapon_exmpl);
		}
		
		weapon_exmpl = new WeaponExample{ j, static_cast<int>(Rarity::Mythical) };
		v_weapon.push_back(weapon_exmpl);
		//WeaponExample weapon_example{ j, static_cast<int>(Rarity::Mythical) };
		//v_weapon.push_back(weapon_example);
	}
}

/* данная функция не принимает и не возвращает аргументы
* данная функция выводит на экран действия доступные пользователю и вызывает основную функцию interactionWithUser для взаимодействия с пользователем
*/
void WeaponShop::startInteraction() {
	std::cout << "\nWelcome to Ammu-Nation\n";
	std::cout << "We have 3 types of weapon: spears, swords and warbows" << std::endl;
	std::cout << "The price of the weapon depends on the rareness of the weapon, so the most rare weapon costs most expensive and the least rare is the cheapest" << std::endl;
	std::cout << "Price list is presented below:" << std::endl;
	std::cout << "1)Common weapon costs " << COMMON_PRICE << std::endl;
	std::cout << "2)Uncommon weapon costs " << UNCOMMON_PRICE << std::endl;
	std::cout << "3)Rare weapon costs " << RARE_PRICE << std::endl;
	std::cout << "4)Mythical weapon costs " << MYTHICAL_PRICE << std::endl;

	interactionWithUser();
}

/* данная функция ничего не принимает и не возвращает
* функция для взаимодействия с пользователем
*/
void WeaponShop::interactionWithUser() {
	while (true) {
		try {
			std::cout << "\nPlease, tell me how much money do you have\n" << std::endl;
			checkUserMoney();
			std::cout << "\nPlease, tell me which type of weapon you want to buy;\n0 is for spears, 1 is for swords, 2 is for warbows\n" << std::endl;
			checkWeaponTypeChoice();
			std::cout << "\nOkay, here are all the weapons that meet your needs\n";
			printSelectedWeapons();
		}
		catch (int error_numb) {
			if(error_numb == 1) std::cout << "\nSorry, you dont have enough money, try again later";
			continue;
		}


	}
}

/* данная функция ничего не принимает и не вызывает
* функция проверяет бюджет пользователя
*/
void WeaponShop::checkUserMoney() {
	int money{ 0 };
	MyReadKeyBoard::readInteger(&money);
	if (money < COMMON_PRICE) throw 1;
	else if (money >= COMMON_PRICE && money < UNCOMMON_PRICE) min_selected_rarity = static_cast<int>(Rarity::Common);
	else if (money >= UNCOMMON_PRICE && money < RARE_PRICE) min_selected_rarity = static_cast<int>(Rarity::Uncommon);
	else if (money >= RARE_PRICE && money < MYTHICAL_PRICE) min_selected_rarity = static_cast<int>(Rarity::Rare);
	else min_selected_rarity = static_cast<int>(Rarity::Mythical);
}

/* данная функция ничего не принимает и не возвращает
* функция обрабатывает выбор типа оружия
*/
void WeaponShop::checkWeaponTypeChoice() {
	int weapon{ 0 };
	bool flag{ true };
	while(flag){
		MyReadKeyBoard::readInteger(&weapon);
		switch (weapon) {
		case 0:
			selected_type = all_types[weapon];
			flag = false;
			break;
		case 1:
			selected_type = all_types[weapon];
			flag = false;
			break;
		case 2:
			selected_type = all_types[weapon];
			flag = false;
			break;
		default: 
			std::cout << "\nSorry I didnt catch that, please try again" << std::endl;
			continue;
			break;
		}
	}
}


/* данная функция ничего не принимает и не возвращает
* данная функция выводит на экран всё оружие что соответствует запросу пользователя
*/
void WeaponShop::printSelectedWeapons() {
	int printed_numb{ 0 };
	std::cout << '\n' << std::endl;
	for (int i = 0; i < v_weapon.size(); ++i) {
		if (v_weapon[i]->getTypeName() == selected_type) {
			void* temp_ptr{ v_weapon[i]->getObjPointer() };
			if (selected_type == all_types[0]) {
				Spear spear = *((Spear*) temp_ptr);
				//Spear* spear = static_cast<Spear*>(temp_ptr);
				if (spear.getRarity() <= min_selected_rarity) {
					printed_numb++;
					std::cout << printed_numb << ") This instance of spear is " << getRarityName(spear.getRarity());
					std::cout << "; It has " << spear.getDamage() << " points of damage, " << spear.getAttackSpeed() << " points of attack speed, ";
					std::cout << spear.getEndurance() << " points of endurance";
					printRarityModifier(spear.getModifier());
					std::cout << "\nSpecial effect : *** "<<spear.getSpecialEffect()<<" ***\n"<<std::endl;
				}
			}

			else if (selected_type == all_types[1]) {
				Sword sword = *((Sword*)temp_ptr);
				if (sword.getRarity() <= min_selected_rarity) {
					printed_numb++;
					std::cout << printed_numb << ") This instance of sword is " << getRarityName(sword.getRarity());
					std::cout << "; It has " << sword.getDamage() << " points of damage, " << sword.getAttackSpeed() << " points of attack speed, ";
					std::cout << sword.getEndurance() << " points of endurance";
					printRarityModifier(sword.getModifier());
					std::cout << "\nSpecial effect : *** " << sword.getSpecialEffect() << " ***\n" << std::endl;

				}
			}

			else {
				Warbow warbow = *((Warbow*)temp_ptr);
				if (warbow.getRarity() <= min_selected_rarity) {
					printed_numb++;
					std::cout << printed_numb << ") This instance of warbow is " << getRarityName(warbow.getRarity());
					std::cout << "; It has " << warbow.getDamage() << " points of damage, " << warbow.getAttackSpeed() << " points of attack speed, ";
					std::cout << warbow.getEndurance() << " points of endurance";
					printRarityModifier(warbow.getModifier());
					std::cout << "\nSpecial effect : *** " << warbow.getSpecialEffect() << " ***\n" << std::endl;
				}
			}
		}
		else continue;
	}
}

/* @param rarity - редкость оружия 
*  return - возвращает строковый тип редкости оружия из вектоар all_rarities
*/
std::string WeaponShop::getRarityName(int rarity) {
	return all_rarities[rarity - 1];
}

/* @param modifier - модификатор с помощью которого определяется как редкость влияет на характеристики
* данная функция ничего не возвращает
* данная функция выводит на экран то как редкость влияет на хар-ки
*/
void WeaponShop::printRarityModifier(int modifier) {
	std::cout << std::endl;
	switch (modifier) {
	case -1:
		std::cout << "All characteristics of this instance are multiplied by rarity to obtain values above the average for the corresponding rarity";
		break;
	default:
		std::cout << "one characteristic of this type of weapon is closer to the maximum, depending on the rarity";
		break;
	}
}

//деструктор класса который удаляет динамически выделенные объекты
WeaponShop::~WeaponShop() {
	for (int i = 0; i < v_weapon.size(); ++i) delete v_weapon[i];
	//v_weapon.clear();
}