#pragma once
#include "Player.h"
#include "Deck.h"
#include <Windows.h>

class BlackJack
{
public:
	void Run();
private:
	bool IsStarted;

	void InitMenu();
	void ChooseGameMode();
	void StartGameAlone();
	void StartGamePvC();

	std::string GreetingInGame();
	void ShowGameStartText();
	void EndGame();

	int TryInput();
};

