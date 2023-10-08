#pragma once
#include "WeaponExample.h"
class WeaponShop
{
public:
	WeaponShop();
	~WeaponShop();

	void startInteraction();
private:
	WeaponExample* weapon_exmpl;//��������� �� WeaponExample

	//const int MYTHICAL_AMOUNT{ 1 };
	const int RARE_AMOUNT{ 2 };//���������� ������� ������
	const int UNCOMMON_AMOUNT{ 3 };//���������� ���������� ������
	const int COMMON_AMOUNT{ 4 };//���������� �������� ������

	const int MULTIPLIER{ 1000 };//��������� ��� �������� ��������� ������
	const int MYTHICAL_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Mythical) }; //���� ����������� ������
	const int RARE_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Rare) };//���� ������� ������
	const int UNCOMMON_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Uncommon) };//���� ���������� ������
	const int COMMON_PRICE{ MULTIPLIER * static_cast<int>(Rarity::Common) };//���� �������� ������
	
	int min_selected_rarity{};//��������� �������� � ������������ � �������� ������������
	std::string selected_type{};//��������� ��� ������

	std::vector<WeaponExample*> v_weapon;//������ ������

	void fillTheVector();
	void interactionWithUser();
	void checkUserMoney();
	void checkWeaponTypeChoice();
	void printSelectedWeapons();
	
	void printRarityModifier(int modifier);
	std::string getRarityName(int rarity);
	
};

