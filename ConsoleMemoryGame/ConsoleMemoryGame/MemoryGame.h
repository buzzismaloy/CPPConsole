#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
#include <cstdlib>
#include <vector>

class MemoryGame
{
	public:
		void RunGame();
	private:
		int x0{}, y0{};
		int amountRounds{}, nSize{}, mSize{}, succeeded{}, mistakes{};
		const std::vector<std::string> vectorModes{ "number" , "sequence" , "matrix"};

		void InitMenu();
		void CheckInput(std::string);
		void EndGame();

		//template<typename int, std::size_t nSize> void CheckInput(int (&arr)[nSize]);
		//template<typename int, std::size_t nSize, std::size_t mSize> void CheckInput(int(&arr)[nSize][mSize]);
		void runNumbMode();
		void runSequenceMode();
		void runMatrixMode();
		//void gameProccess();

		int createNumb();
		std::vector<int> createNumbSequence();
		std::vector<std::vector<int>> createMatrix();
		
		void formatText(std::string);
		void formatMode(std::string);
};

