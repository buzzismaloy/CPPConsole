#pragma once
#include "Armament.h"

class Warbow : public Armament
{
public:
	Warbow(int rarity);
	virtual ~Warbow() = default;//����������� ���������� ������ �� ���������

private:
	const int MIN_DMG_BORDER{ 15 };//��� ����
	const int MAX_DMG_BORDER{ 35 };//������ ������� ��� ��������� �����
	const int MAX_AVAILABLE_DMG{ MAX_DMG_BORDER * static_cast<int>(Rarity::Mythical) };//����������� ��������� ����
	const int MIN_END_BORDER{ 7 };//��� ���������
	const int MAX_END_BORDER{ 21 };// ������ ������� ��� ��������� ���������
	const int MAX_AVAILABLE_END{ MAX_END_BORDER * static_cast<int>(Rarity::Mythical) };//����������� ��������� ���������
	const int MIN_ATT_SPEED_BORDER{ 9 };//��� �������� �����
	const int MAX_ATT_SPEED_BORDER{ 22 };//������ ������� ��� ��������� �������� �����
	const int MAX_AVAILABLE_ATT_SPEED{ MAX_ATT_SPEED_BORDER * static_cast<int>(Rarity::Mythical) }; //����������� ��������� �������� �����

	void setAttackSpeed() override;
	void setDamage() override;
	void setEndurance() override;
};

