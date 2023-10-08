#include "SpecialEffects.h"

void SpecialEffects::setEffect(int rarity) {
	switch (rarity) {
	case 1:
		selected_effect = common_effect;
		break;
	case 2:
		selected_effect = getUncommonEffect();
		break;
	case 3:
		selected_effect = getRareEffect();
		break;
	case 4:
		selected_effect = getMythicalEffect();
		break;
	default:
		selected_effect = "\n\nERROR\n\n";
		break;
	}
}

std::string SpecialEffects::getSpecialEffect() const {
	return selected_effect;
}

std::string SpecialEffects::getUncommonEffect() {
	int index{ 0 + rand() % static_cast<int>(uncommon_effects.size()) };
	return uncommon_effects[index];
}

std::string SpecialEffects::getRareEffect() {
	int index{ 0 + rand() % static_cast<int>(rare_effects.size()) };
	return rare_effects[index];
}

std::string SpecialEffects::getMythicalEffect() {
	int index{ 0 + rand() % static_cast<int>(mythical_effects.size())};
	return mythical_effects[index];
}
