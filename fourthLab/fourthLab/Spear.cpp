#include "Spear.h"


Spear::Spear(int rarity) {
	this->rarity = rarity;
	special_effect.setEffect(this->rarity);
	checkRarityModifier();
	setAttackSpeed();
	setDamage();
	setEndurance();
}

void Spear::setAttackSpeed(){
	switch (parameter_number) {
	case -1:
		//attack_speed = MIN_ATT_SPEED_BORDER * rarity + rand() % ((MAX_ATT_SPEED_BORDER - MIN_ATT_SPEED_BORDER + 1) * rarity);
		attack_speed = ((MIN_ATT_SPEED_BORDER + MAX_ATT_SPEED_BORDER) / 2 + rand() % ((MAX_ATT_SPEED_BORDER - rarity) - ((MIN_ATT_SPEED_BORDER + MAX_ATT_SPEED_BORDER) / 2) + 1)) * rarity;
		break;
	case 0:
		//attack_speed = (MAX_AVAILABLE_ATT_SPEED - 10) + rand() % (MAX_AVAILABLE_ATT_SPEED - 3 + rarity);
		attack_speed = MAX_AVAILABLE_ATT_SPEED - MAX_ATT_SPEED_BORDER / rarity + rand() % (rarity + 1);
		break;
	default:
		attack_speed = MIN_ATT_SPEED_BORDER + rand() % (MAX_ATT_SPEED_BORDER - MIN_ATT_SPEED_BORDER + 1);
		break;

	}
}

void Spear::setDamage(){
	switch (parameter_number) {
	case -1:
		//damage = MIN_DMG_BORDER * rarity + rand() % ((MAX_DMG_BORDER - MIN_DMG_BORDER + 1) * rarity);
		damage = ((MIN_DMG_BORDER + MAX_DMG_BORDER) / 2 + rand() % ((MAX_DMG_BORDER - rarity) - (MIN_DMG_BORDER + MAX_DMG_BORDER) / 2 + 1)) * rarity;
		break;
	case 1:
		//damage = (MAX_AVAILABLE_DMG - 10) + rand() % (MAX_AVAILABLE_DMG - 3 + rarity);
		damage = MAX_AVAILABLE_DMG - MAX_DMG_BORDER / rarity + rand() % (rarity + 1);
		break;
	default:
		damage = MIN_DMG_BORDER + rand() % (MAX_DMG_BORDER - MIN_DMG_BORDER + 1);
		break;
	}
}

void Spear::setEndurance() {
	switch (parameter_number) {
	case -1:
		//endurance = MIN_END_BORDER * rarity + rand() % ((MAX_END_BORDER - MIN_END_BORDER + 1) * rarity);
		endurance = ((MIN_END_BORDER + MAX_END_BORDER) / 2 + rand() % ((MAX_END_BORDER - rarity) - (MIN_END_BORDER + MAX_END_BORDER) / 2 + 1)) * rarity;
		break;
	case 2:
		//endurance = (MAX_AVAILABLE_END - 10) + rand() % (MAX_AVAILABLE_END - 3 + rarity);
		endurance = MAX_AVAILABLE_END - MAX_END_BORDER / rarity + rand() % (rarity + 1);
		break;
	default:
		endurance = MIN_END_BORDER + rand() % (MAX_END_BORDER - MIN_END_BORDER + 1);
		break;
	}
}