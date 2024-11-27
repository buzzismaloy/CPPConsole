#pragma once
#include <vector>
#include <string>
#include <array>
class Deck
{
public:
	void SetDeck();
	void Shuffle();
	int CountDeckSize();
	std::array<std::string, 2> GetCard();
private:
	void RemoveCard();

	std::vector<std::string> ExampleSuit{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	const std::string Suits[4] = { "Hearts", "Diamonds", "Spades", "Clubs" };
	std::vector<std::string> HeartsSuit;
	std::vector<std::string> DiamondsSuit;
	std::vector<std::string> SpadesSuit;
	std::vector<std::string> ClubsSuit;
	std::array<std::string, 2> ChosenCard;
	int IndexOfCard;
};

