#pragma once
#include <vector>
#include "Field.h"

const char DEFAULT_HEAD{ 'O' };
const char DEFAULT_BODY{ '*' };

enum class Rotation {
	left,
	right,
	up,
	down
};

struct Position {
	int x;
	int y;
};

class Snake
{
private:
	Snake(const Snake&) = delete;
	void operator=(const Snake&) = delete;

	void determineRotationWASD();
	void determineRotationArrows();
	void changePosition();

	bool snake_controls{};
	bool apple_taken{};
	char head{}, body{}, apple{}, border{};
	//int length{};
	std::vector<Position> snake_position{};
	Rotation snake_rotation;

public:
	Snake(Rotation rotation, bool _controls, char _apple, char _border, char _head, char _body) : snake_rotation(rotation), snake_controls(_controls), apple(_apple),
		border(_border), head(_head), body(_body) {}//{ length = 1; }
	Snake(Rotation rotation, bool _controls, char _apple, char _border) : snake_rotation(rotation), snake_controls(_controls), apple(_apple), border(_border) {
		//length = 1;
		head = DEFAULT_HEAD;
		body = DEFAULT_BODY;
	}
	~Snake();

	//char getDefaultHead() const;
	//char getDefaultBody() const;
	void setStartPosition();
	void move(char field[Y_SIZE][X_SIZE + 1]);
	void addTail();
	bool isGameOver();
	bool isGameOver(bool);
	bool getAppleTaken() const;
};

