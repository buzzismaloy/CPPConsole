#include "Snake.h"

/*char Snake::getDefaultBody() const {
	return default_body;
}

char Snake::getDefaultHead() const {
	return default_head;
}*/

Snake::~Snake() {}

void Snake::setStartPosition() {
	snake_position.clear();
	snake_position.push_back({ X_SIZE / 2, Y_SIZE / 2 });

	CursorFunctions::goToXY(snake_position[0].x, snake_position[0].y);
	putchar(head);
}

void Snake::determineRotationWASD() {
	if (GetAsyncKeyState('W')) snake_rotation = Rotation::up;
	else if (GetAsyncKeyState('S')) snake_rotation = Rotation::down;
	else if (GetAsyncKeyState('A')) snake_rotation = Rotation::left;
	else if (GetAsyncKeyState('D')) snake_rotation = Rotation::right;
}

void Snake::determineRotationArrows() {
	if (GetAsyncKeyState(VK_UP)) snake_rotation = Rotation::up;
	else if (GetAsyncKeyState(VK_DOWN)) snake_rotation = Rotation::down;
	else if (GetAsyncKeyState(VK_LEFT)) snake_rotation = Rotation::left;
	else if (GetAsyncKeyState(VK_RIGHT)) snake_rotation = Rotation::right;
}

void Snake::changePosition() {
	switch (snake_rotation) {
	case Rotation::up:
		snake_position[0].y = snake_position[0].y - 1;
		break;
	case Rotation::down:
		snake_position[0].y = snake_position[0].y + 1;
		break;
	case Rotation::left:
		snake_position[0].x = snake_position[0].x - 2;
		break;
	case Rotation::right:
		snake_position[0].x = snake_position[0].x + 2;
		break;
	}
}

void Snake::move(char field[Y_SIZE][X_SIZE + 1]) {
	if (snake_controls) determineRotationWASD();
	else determineRotationArrows();

	if(snake_position[snake_position.size() - 1].y == 0 || snake_position[snake_position.size() - 1].x == 0 
		|| snake_position[snake_position.size() - 1].y == Y_SIZE - 1 || snake_position[snake_position.size() - 1].x == X_SIZE - 1) 	
		field[snake_position[snake_position.size() - 1].y][snake_position[snake_position.size() - 1].x] = border;
	else field[snake_position[snake_position.size() - 1].y][snake_position[snake_position.size() - 1].x] = ' ';
	for (int i = snake_position.size() - 1; i > 0; --i) snake_position[i] = snake_position[i - 1];
	changePosition();

	if (field[snake_position[0].y][snake_position[0].x] == apple) {
		addTail();
		apple_taken = true;
	}
	else apple_taken = false;
	if(snake_position[0].y == 0 || snake_position[0].x == 0 || snake_position[0].y == Y_SIZE - 1 || snake_position[0].x == X_SIZE - 1)
		field[snake_position[0].y][snake_position[0].x] = border;
	else field[snake_position[0].y][snake_position[0].x] = head;

	if (snake_position.size() > 1) field[snake_position[1].y][snake_position[1].x] = body;
}

bool Snake::getAppleTaken() const {
	return apple_taken;
}

void Snake::addTail() {
	snake_position.push_back({ snake_position[snake_position.size() - 1].x , snake_position[snake_position.size() - 1].y });
}

bool Snake::isGameOver() {
	bool flag{ false };

	if (snake_position[0].x <= 0 || snake_position[0].x >= X_SIZE - 1 || snake_position[0].y <= 0 || snake_position[0].y >= Y_SIZE - 1)
		flag = true;

	for (int i = 2; i < snake_position.size(); ++i) {
		if (snake_position[0].x == snake_position[i].x && snake_position[0].y == snake_position[i].y) {
			flag = true;
			break;
		}
	}

	return flag;
}

bool Snake::isGameOver(bool border_mode) {
	bool flag{ false };

	if (border_mode) {
		if (snake_position[0].x <= 0 || snake_position[0].x >= X_SIZE - 1 || snake_position[0].y <= 0 || snake_position[0].y >= Y_SIZE - 1)
			flag = true;
	}
	else {
		if (snake_position[0].x <= 0) snake_position[0].x = X_SIZE - 1;
		else if (snake_position[0].x >= X_SIZE - 1) snake_position[0].x = 0;

		if (snake_position[0].y <= 0) snake_position[0].y = Y_SIZE - 1;
		else if (snake_position[0].y >= Y_SIZE - 1) snake_position[0].y = 0;
	}

	for (int i = 2; i < snake_position.size(); ++i) {
		if (snake_position[0].x == snake_position[i].x && snake_position[0].y == snake_position[i].y) {
			flag = true;
			break;
		}
	}

	return flag;
}