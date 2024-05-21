#include "Field.h"

/*void Field::setApple(char apple) {
	this->apple = apple;
}

char Field::getApple() const {
	return apple;
}*/

/*char Field::getDefaultApple() const {
	return APPLE_BY_DEFAULT;
}*/

Field::~Field() {}

void Field::createBoundaries(char ch) {
	for (int y = 0; y < Y_SIZE; ++y) {
		for (int x = 0; x < X_SIZE; ++x) {
			if (y == 0 || y == Y_SIZE - 1 || x == 0 || x == X_SIZE - 1) field[y][x] = ch;
			else field[y][x] = ' ';
		}
		field[y][X_SIZE] = '\0';
	}
}

void Field::spawnPrize() {
	int x{ rand() % (X_SIZE - 2) + 1 };
	int y{ rand() % (Y_SIZE - 2) + 1 };
	bool is_spawned{ false };

	while (true) {
		if (x % 2 == 0) is_spawned = true;
		if (field[y][x] == head || field[y][x] == body) is_spawned = false;

		if (is_spawned) break;
		x = rand() % (X_SIZE - 2) + 1;
	}

	//if (apple == ' ') field[y][x] = APPLE_BY_DEFAULT;
	//else field[y][x] = apple;
	field[y][x] = apple;
}

void Field::show() const{
	CursorFunctions::goToXY(0, 0);
	for (int i = 0; i < Y_SIZE; ++i) {
		std::cout << field[i] << '\n';
	}
	//std::cout << "length: " << snake_length;
}