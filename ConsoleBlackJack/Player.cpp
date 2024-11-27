#include "Player.h"

Player::Player(std::string PlayerName) {
	this->PlayerName = PlayerName;
}

std::string Player::GetPlayer() {
	return PlayerName;
}

void Player::TakeCard(std::string suit, std::string value) {
	handValue.push_back(value);
	handSuits.push_back(suit);
}

void Player::ShowHand() {
	if (handValue.empty()) std::cout << "\nHand is empty";
	else {
		for (int i = 0; i < handValue.size(); ++i)
			std::cout << '\n' << PlayerName << "'s hand: " << handSuits[i] << '-' << handValue[i] << ' ';
	}
	std::cout << '\n' << std::endl;
}

int Player::CountHandValue() {
	int result{ 0 };
	if (handValue.empty()) return 0;
	else {
		for (auto i : handValue) {
			if (result <= 21) result += cardValues[i];
			else {
				if (i == "A") result += 1;
				else result += cardValues[i];
			}
		}
		return result;
	}
}