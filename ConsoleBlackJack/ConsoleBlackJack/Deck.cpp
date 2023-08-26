#include "Deck.h"
#include <time.h>
#include <cstdlib>

void Deck::SetDeck() {
	HeartsSuit = ExampleSuit;
	DiamondsSuit = ExampleSuit;
	ClubsSuit = ExampleSuit;
	SpadesSuit = ExampleSuit;
}

void Deck::Shuffle() {
	srand(time(NULL));
	int choice{ 0 + rand() % (3 - 0 + 1) };
	switch(choice) {
		case 0:
			ChosenCard[0] = Suits[choice];
			IndexOfCard = 0 + rand() % (HeartsSuit.size() - 0);
			ChosenCard[1] = HeartsSuit[IndexOfCard];
			break;
		case 1:
			ChosenCard[0] = Suits[choice];
			IndexOfCard = 0 + rand() % (DiamondsSuit.size() - 0);
			ChosenCard[1] = DiamondsSuit[IndexOfCard];
			break;
		case 2:
			ChosenCard[0] = Suits[choice];
			IndexOfCard = 0 + rand() % (SpadesSuit.size() - 0);
			ChosenCard[1] = SpadesSuit[IndexOfCard];
			break;
		case 3: 
			ChosenCard[0] = Suits[choice];
			IndexOfCard = 0 + rand() % (ClubsSuit.size() - 0);
			ChosenCard[1] = ClubsSuit[IndexOfCard];
			break;
	}
}

std::array<std::string, 2> Deck::GetCard() {
	RemoveCard();
	return ChosenCard;
}

void Deck::RemoveCard() {
	if (ChosenCard[0] == Suits[0]) {
		auto iter = HeartsSuit.begin();
		HeartsSuit.erase(iter + IndexOfCard);
	}
	else if (ChosenCard[0] == Suits[1]) {
		auto iter = DiamondsSuit.begin();
		DiamondsSuit.erase(iter + IndexOfCard);
	}
	else if (ChosenCard[0] == Suits[2]) {
		auto iter = SpadesSuit.begin();
		SpadesSuit.erase(iter + IndexOfCard);
	}
	else if (ChosenCard[0] == Suits[3]) {
		auto iter = ClubsSuit.begin();
		ClubsSuit.erase(iter + IndexOfCard);
	}
}


int Deck::CountDeckSize() {
	int res = HeartsSuit.size() + DiamondsSuit.size() + SpadesSuit.size() + ClubsSuit.size();
	return res;
}