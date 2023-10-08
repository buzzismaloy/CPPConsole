#include "Armament.h"

int Armament::getDamage() const//������ �����
{
	return this->damage;
}

int Armament::getEndurance() const//������ ���������
{
	return this->endurance;
}

int Armament::getAttackSpeed() const//������ �������� �����
{
	return this->attack_speed;
}

int Armament::getRarity() const//������ ��������
{
	return this->rarity;
}

int Armament::getModifier() const//������ ��������� ����������� �� �� ��� �������������� ��������������
{
	return this->parameter_number;
}

std::string Armament::getSpecialEffect() const {//������ ������������ �������
	return special_effect.getSpecialEffect();
}

void Armament::checkRarityModifier()//������ ��������� ����������� �� �������� ������� ��� �������������� ��������������
{
	setRarityModifier();
	if (rarity_modifier) parameter_number = rand() % 3;
	else parameter_number = -1;
}

void Armament::setRarityModifier()//������ ��������� �� �������� ������� ��� ����������� �������������
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
