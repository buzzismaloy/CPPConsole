#pragma once
#include "Armament.h"

class Sword : public Armament
{
public:
	Sword(int rarity);
	virtual ~Sword() = default;//����������� ���������� ������ �� ���������

private:
	const int MIN_DMG_BORDER{ 7 };//��� ����
	const int MAX_DMG_BORDER{ 23 };//������ ������� ��� ��������� �����
	const int MAX_AVAILABLE_DMG{ MAX_DMG_BORDER * static_cast<int>(Rarity::Mythical) }; // ����������� ��������� ����
	const int MIN_END_BORDER{ 22 };//��� ��������� 
	const int MAX_END_BORDER{ 55 };//������ ������� ��� ��������� ���������
	const int MAX_AVAILABLE_END{ MAX_END_BORDER * static_cast<int>(Rarity::Mythical) }; //����������� ��������� ���������
	const int MIN_ATT_SPEED_BORDER{ 8 };//��� �������� �����
	const int MAX_ATT_SPEED_BORDER{ 20 };//������ ������� ��� ��������� �������� �����
	const int MAX_AVAILABLE_ATT_SPEED{ MAX_ATT_SPEED_BORDER * static_cast<int>(Rarity::Mythical) };//����������� ��������� �������� �����

	void setAttackSpeed() override;
	void setDamage() override;
	void setEndurance() override;
};

