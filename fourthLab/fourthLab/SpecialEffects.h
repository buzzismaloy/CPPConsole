#pragma once
#include <vector>
#include <iostream>

class SpecialEffects
{
public:
	void setEffect(int rarity);
	std::string getSpecialEffect() const;
private:
	std::string selected_effect{};//выбранный эффект
	std::string common_effect{ "this weapon has no special effect" }; //эффект обычного оружия
	/*
	* uncommon_effects - вектор эффектов для необычного оружия
	* rare_effects - вектор эффектов для редкого оружия
	* mythical_effects - вектор эффектов для мифического оружия
	*/
	std::vector<std::string> uncommon_effects{"by holding this weapon your intelligence increases with +4", "by holding this weapon your regeneration increases with +2", "by holding this weapon your resistance to poisons increases with +1", "by holding this weapon your durability increases with +7", "by holding this weapon your agility increases with +2", "by holding this weapon your strength increases with +10"};
	std::vector<std::string> rare_effects{"attacks of this weapon ignore 5 armor", "attacks of this weapon accelerate your movement speed by +20", "attacks of this weapon additionally deal 2 units of damage", "attacks of this weapon cause bleeding", "attacks of this weapon impose poison"};
	std::vector<std::string> mythical_effects{"attacks of this weapon set fire to the opponent adding +10 to damage and dealing 5 damage every 2 seconds for 10 seconds; the weapon itself glows brightly", "the attacks of this weapon partially freeze the affected area by adding +5 damage to the attack, applying a slowdown for 2 seconds and dealing 2 units of damage every 4 seconds for 12 seconds; the weapon blows cold, frost forms in places", "attacks of this weapon add + 7 lightning damage and stun for 1 second; the weapon  sparkles with electricity"};

	std::string getUncommonEffect();
	std::string getRareEffect();
	std::string getMythicalEffect();
};

