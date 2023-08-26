#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>;

class Player
{
public:
	Player(std::string);
	std::string GetPlayer();
	void TakeCard(std::string, std::string);
	void ShowHand();
	int CountHandValue();
private:
	//std::map<std::string, char> hand;
	std::vector<std::string> handValue;
	std::vector < std::string> handSuits;
	std::map<std::string, int> cardValues{
		{"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 10}, {"Q", 10}, {"K", 10}, {"A", 11}
	};
	std::string PlayerName;
};

