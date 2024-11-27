#pragma once
#include "Snake.h"
#include <conio.h>

enum class GameModes { //мб потом допилю мод с динамической скоростью где тики сокращаются с каждым яблоком на 1 от 300 до 15, чтобы победить надо собрать 290 яблок
	mode_1 = 1, //первый гейммод, яблоки появляются последовательно
	mode_2, //второй, яблоки появляются все сразу
	mode_3//динамическая скорость, яблоки появляются последовательно, при поднятии яблока изменяется скорость
};

class SnakeGame
{
public:
	SnakeGame();
	~SnakeGame();

	void start();

	//void testStartGame();

private:
	const int MAX_APPLES_AMOUNT{ X_SIZE* Y_SIZE - 3 };
	const int MAX_TOTAL_APPLES{ ((X_SIZE * Y_SIZE) / 10 ) / 3 + 9 + 100};
	const int MIN_TOTAL_APPLES{ 25 };
	const int MIN_VELOCITY{ 15 };
	const int MAX_VELOCITY{ 300 };
	const int DYNAMIC_SPEED_MAX_VELOCITY{ 60 };
	const int DYNAMIC_MODIFIER{ 10 };
	const int DYNAMIC_SPEED_MAX_APPLES{MAX_VELOCITY - DYNAMIC_SPEED_MAX_VELOCITY + DYNAMIC_MODIFIER};

	bool border_mode{ true };//если тру - то змея при соприкосновении со стеной умирает, фолс - выходит с противоположной стороны
	bool winning_flag{ true };//flag that tells us if user won
	clock_t time_1{}, time_2{};
	double game_duration{ 0.0 };
	int velocity{ 70 };
	bool control_type{ true };
	int selected_border{ DEFAULT_BORDER_1 };
	bool game_mode{ true };//old variant of flag that tells us the game mode chosen by user, do not use
	bool default_chars{ true };//if this flag true - it tells us that default symbols for head, body and apple are used
	char head{}, body{}, apple{};//symbols for head, body and apple
	int apples_amount{ MIN_TOTAL_APPLES };
	HANDLE h_console_output{};
	WORD old_text_attr{};
	unsigned int succeded_apples{ 0 };
	GameModes cur_game_mode{GameModes::mode_1};

	SnakeGame(const SnakeGame&) = delete;
	void operator=(const SnakeGame&) = delete;

	void menu();
	void run();
	void settings();
	void quit();

	void runSequentGame();
	void runAtOnceGame();
	//void runDynamicSpeed();
	void endingGameMsg();
	void clearKeyBoardBuffer();

	void setControls();
	void setBorders();
	void setVelocity();
	void setGameMode();
	void setEnumGameMode();
	void setAppleNumb();
	void setEnumAppleNumb();
	void setChars();
	void setBorderMode();

	void setTextAttr(WORD attr);
	bool checkVictory();
};

