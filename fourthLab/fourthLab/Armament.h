#pragma once
#include <iostream>
#include <vector>
#include "SpecialEffects.h"

enum class Rarity { Common = 1, Uncommon, Rare, Mythical }; //������������ ���� ���������

const std::vector<std::string> all_types{"Spear", "Sword", "Warbow"};//����� ������ ���������� ��� ���� ������
const std::vector<std::string> all_rarities{"Common", "Uncommon", "Rare", "Mythical"};//��������� ��������

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
	int damage{};//����
	int endurance{};//���������
	int attack_speed{};//�������� �����
	int rarity{};//��������
	int parameter_number{};//�������� � ����������� �� �������� �������� ������ �� ��� �������������� ��� ������ �� ����

	SpecialEffects special_effect; // ��������� �������

	void checkRarityModifier();

	virtual void setAttackSpeed() = 0;
	virtual void setDamage() = 0;
	virtual void setEndurance() = 0;

private:
	bool rarity_modifier{}; //��� �������������� � ������� �������� - ���� �������� ��� ���

	void setRarityModifier();
};

