#pragma once
#include <memory>
#include "Warbow.h"
#include "Spear.h"
#include "Sword.h"

class WeaponExample
{
public:
	WeaponExample(std::string obj_to_generate, int rarity);
	~WeaponExample();

	void* getObjPointer() const;
	std::string getTypeName() const;
	
private:
	void* object_pointer{};//указатель на пустоту за которым будет храниться объект
	std::string type_name{};//тип объекта
	
	void generateWeaponObj(std::string* obj_to_generate, int* rarity);
};

