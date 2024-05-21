#pragma once
#include "CursorFunctions.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

const int X_SIZE{ 105 };
const int Y_SIZE{ 26 };
const char DEFAULT_APPLE{ '$' };
const int DEFAULT_BORDER_1{ 35 };
const int DEFAULT_BORDER_2{ 219 };

class Field
{
public:
	Field(char _head, char _body, char _apple) : head(_head), body(_body), apple(_apple) {}
	Field(char _head, char _body) : head(_head), body(_body) {
		apple = DEFAULT_APPLE;
	}
	~Field();

	char field[Y_SIZE][X_SIZE + 1]{ {} };

	void createBoundaries(char ch);
	void show() const;
	void spawnPrize();
	//char getDefaultApple() const;
	//char getApple() const;
	//void setApple(char apple);
private:
	char apple{ ' ' };
	char head{ ' ' };
	char body{ ' ' };

	Field(const Field&) = delete;
	void operator=(const Field&) = delete;
};

