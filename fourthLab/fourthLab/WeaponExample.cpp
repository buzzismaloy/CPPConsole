#include "WeaponExample.h"

WeaponExample::WeaponExample(std::string obj_to_generate, int rarity) { //конструктор класса который на вход принимает тип оружия и редкость
	generateWeaponObj(&obj_to_generate, &rarity);
}

/* данная функция создает объект оружия, сохраняет его тип и сохраняет объект в указатели на пустоту
* данная функция ничего не возвращает
* на вход принимается ссылка на строку содержащую тип и ссылка на число - редкость
*/
void WeaponExample::generateWeaponObj(std::string* obj, int* rarity) {
	try {
		if (std::find(all_types.begin(), all_types.end(), *obj) != all_types.end()) {
			if (*obj == all_types[0]) {
				type_name = all_types[0];
				//Spear spear(*rarity);
				//object_pointer = &spear;
				object_pointer = new Spear{ *rarity };
			}
			else if (*obj == all_types[1]) {
				type_name = all_types[1];
				//Sword sword(*rarity);
				//object_pointer = &sword;
				object_pointer = new Sword{ *rarity };
			}
			else {
				type_name = all_types[2];
				//Warbow warbow(*rarity);
				//object_pointer = &warbow;
				object_pointer = new Warbow{ *rarity };
			}
		}
		else throw "\nProbably you forgot to add some types\n";
	}
	catch (const char* error_msg) {
		std::cout << error_msg;
		std::cout << "\nProgram will be crushed"<<std::endl;
		exit(1);
	}
	
}

void* WeaponExample::getObjPointer() const{//геттер указателя на пустоту за которым скрывается объект оружия
	return object_pointer;
}

std::string WeaponExample::getTypeName() const {//геттер типа оружия
	return type_name;
}

WeaponExample::~WeaponExample() {//деструктор класса в котором освобождается динамически выделенная память для указателя на пустоту
	delete object_pointer;
}