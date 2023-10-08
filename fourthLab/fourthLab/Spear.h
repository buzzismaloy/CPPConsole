#pragma once
#include "Armament.h"

class Spear : public Armament
{
public:
	Spear(int rarity);
	virtual ~Spear() = default;

private:
	const int MIN_DMG_BORDER{ 10 };//��� ����
	const int MAX_DMG_BORDER{ 25 };//������ ������� ��� ��������� �����
	const int MAX_AVAILABLE_DMG{ MAX_DMG_BORDER * static_cast<int>(Rarity::Mythical) }; //����������� ��������� ����
	const int MIN_END_BORDER{ 15 };//��� ���������
	const int MAX_END_BORDER{ 50 };//������ ������� ��� ��������� ���������
	const int MAX_AVAILABLE_END{ MAX_END_BORDER  * static_cast<int>(Rarity::Mythical) }; //����������� ��������� ���������
	const int MIN_ATT_SPEED_BORDER{ 5 };//��� �������� �����
	const int MAX_ATT_SPEED_BORDER{ 20 };//������ ������� ��� ��������� �������� �����
	const int MAX_AVAILABLE_ATT_SPEED{ MAX_ATT_SPEED_BORDER * static_cast<int>(Rarity::Mythical) }; //����������� ��������� �������� �����

	void setAttackSpeed() override;
	void setDamage() override;
	void setEndurance() override;
};

