#include "BlackJack.h"


void BlackJack::Run() {
	std::cout << "Welcome to BlackJack!\nHope you will enjoy this iteration of such popular game\n"<<std::endl;
	std::cout << "If you want to play, please enter \"play\", if not enter \"exit\"\n"<<std::endl;
	IsStarted = false;
	InitMenu();
}

void BlackJack::InitMenu() {
	std::string UserInput;
	std::cin >> UserInput;
	if (UserInput == "play") {
		std::cout << "If you would like to play alone, please, enter \"alone\", if you want to play vs computer enter \"PvC\" in Eng\n"<<std::endl;
		ChooseGameMode();
	}
	else if (UserInput == "exit") { 
		std::cout << "Goodbye!!!";
		exit(1);
	}
	else {
		std::cout << "\nI didnt catch that, please, try again\n"<<std::endl;
		InitMenu();
	}
}

void BlackJack::ChooseGameMode() {
	std::string UserInp;
	std::cin >> UserInp;
	if (UserInp == "alone") {
		std::cout << "\n\t\t\t\tGood luck, have fun\n"<<std::endl;
		StartGameAlone();
	}
	else if (UserInp == "PvC") {
		std::cout << "\n\t\t\t\tGood luck, have fun agains computer\n"<<std::endl;
		StartGamePvC();
	}
	else {
		std::cout << "\nI didnt catch that, please, try again\n"<<std::endl;
		ChooseGameMode();
	}
}

void BlackJack::StartGamePvC() {
	std::string UserName;
	bool enoughChoice1 = false, enoughChoice2 = false;
	int turn{ 0 };
	UserName = GreetingInGame();
	Player player(UserName);
	Player dealer("computer");
	Deck deck;
	deck.SetDeck();

	std::cout << "However you can also win your opponent - computer who is also a card dealer\n";
	std::cout << "To win him you dont need to get more than 21 points or the dealer wins\n";
	std::cout << "As computer is a dealer it has to take cards unless it gets 17 or more points and stops when it does\n";
	std::cout << "If dealer has more than 21 points - you win\n";
	std::cout << "If dealer doesnt have 21 points and your arm is bigger than its but smaller than 22 you will win. However, if your arm is weaker than dealer's one you will lose\n";
	std::cout << "If both of you gets 21 points it is draw\n";
	//std::cout << "If dealer has 21 points within 2 cards he will win in any case";
	std::cout << "In this mode you can take card by entering \"1\" and also you can finish actions with your cards by entering \"2\"\n";
	std::cout << "Finish actions with your cards means you wont be able to take more cards and you will stay with your hand till the end\n";
	std::cout << "I hope i didnt forget anything else important\nSo, that's all the rules, GL HF, bro!";
	ShowGameStartText();

	IsStarted = true;
	while (IsStarted) {
		int input{ 0 };
		std::array<std::string, 2> tempArr;

		turn++;
		std::cout << "Turn " << turn << '\n' << std::endl;
		std::cout << "Cards in the deck: " << deck.CountDeckSize() << ";\nCost of " << player.GetPlayer() << "'s hand: " << player.CountHandValue() << ";\n" << player.GetPlayer() << "'s hand: ";
		player.ShowHand();
		std::cout << "Cost of dealer's(" << dealer.GetPlayer() << ") hand: "<<dealer.CountHandValue()<<std::endl;
		std::cout << dealer.GetPlayer() << "'s hand: ";
		dealer.ShowHand();
		
		if (!enoughChoice1) {
			std::cout << "\nTo take card enter \"1\", to finish actions enter \"2\""<<std::endl;
			while (input != 1 && input != 2) input = TryInput();
			switch(input){
				case 1:
					deck.Shuffle();
					tempArr = deck.GetCard();
					player.TakeCard(tempArr[0], tempArr[1]);
					std::cout << "\nYou took: " << tempArr[0] << '-' << tempArr[1] << std::endl;
					break;
				case 2:
					std::cout << "\nYou finished your box\n";
					enoughChoice1 = true;
					break;
				default:
					std::cout << "\nWrong input\n";
					break;
			}
			

		}
		else std::cout << "\nWait untill dealer gets 17 or more points in his hand as u finished ur box\n"<<std::endl;

		if (dealer.CountHandValue() < 17) {
			deck.Shuffle();
			tempArr = deck.GetCard();
			dealer.TakeCard(tempArr[0], tempArr[1]);
			std::cout << "\nDealer took: " << tempArr[0] << '-' << tempArr[1] << std::endl;
		}
		else enoughChoice2 = true;
		
		if (enoughChoice1 && enoughChoice2) {
			if (dealer.CountHandValue() == 21 && player.CountHandValue() == 21) std::cout << "\nIt's draw\n";
			if (player.CountHandValue() > dealer.CountHandValue() && player.CountHandValue() <= 21) std::cout << "\nYou win!\n";
			if (dealer.CountHandValue() > 21 && player.CountHandValue() < 22) std::cout << "\nYou win\n";
			if (dealer.CountHandValue() > player.CountHandValue() && player.CountHandValue() <= 21) std::cout << "\nDealer wins";
			if (player.CountHandValue() > 21) std::cout << "\nDealer wins!\n";
			IsStarted = false;
		}
	}
	EndGame();
}

void BlackJack::StartGameAlone() {
	std::string UserName;
	int turn{ 0 };
	UserName = GreetingInGame();
	Player player(UserName);
	Deck deck;
	deck.SetDeck();

	std::cout << "Any other situation except when you have 21 point will be considered as loss"<<std::endl;
	std::cout << "In this mode the only option you have is to take another card(enter \"1\")"<<std::endl;
	std::cout << "Every round(every time you take card) you will be provided with information about the deck size, your hand and cost of your hand" << std::endl;
	std::cout << "GL HF, bro!";
	ShowGameStartText();

	IsStarted = true;
	while (IsStarted) {
		int input{ 0 };
		std::array<std::string, 2> tempArr;

		turn++;
		std::cout << "Turn "<<turn<<'\n'<<std::endl;
		std::cout << "Cards in the deck: " << deck.CountDeckSize() << ";\nCost of " << player.GetPlayer() << "'s hand: " << player.CountHandValue() << ";\n" << player.GetPlayer() << "'s hand: ";
		player.ShowHand();
		
		deck.Shuffle();
		std::cout << "To take card enter \"1\"\n"<<std::endl;
		while (input != 1) input = TryInput();
		tempArr = deck.GetCard();
		player.TakeCard(tempArr[0], tempArr[1]);
		std::cout << "\nYou took: " << tempArr[0] << '-' << tempArr[1] << std::endl;
		if (player.CountHandValue() == 21) {
			std::cout << "\n\nCongratulations!!! You got 21 points\n";
			IsStarted = false;
		}
		else if (player.CountHandValue() > 21) {
			std::cout << "\n\nYou lost\n\n";
			IsStarted = false;
		}
	}
	EndGame();
}

std::string BlackJack::GreetingInGame() {
	std::string UserName;
	std::cout << "Please, enter your user name(preferably in english and except for the word \"computer\")\n" << std::endl;
	while (std::cin >> UserName) {
		if (UserName != "computer") break;
	}
	std::cout << "Nice to meet you, Mr. " << UserName << '\n' << std::endl;
	std::cout << "In this game you need to get 21 points either by Black-Jack(Ace + any card that costs 10 points) or any other combination that will give you 21 pts" << std::endl;

	return UserName;
}

void BlackJack::EndGame() {
	std::cout << "That's all, if you want to play again, enter \"again\", if not enter anything else";
	std::string inp;
	std::cin >> inp;
	if (inp == "again") Run();
	else exit(1);
}

int BlackJack::TryInput() {
	int input{ 0 };
	while (!(std::cin >> input)) {
		std::cout << "Bad value!\n" << std::endl;
		std::cin.clear();
		fflush(stdin);
	}
	return input;
}

void BlackJack::ShowGameStartText() {
	std::cout << "\n\t\t\t\t\tThe game will start in 10... " << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t9..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t8..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t7..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t6..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t5..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t4..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t3..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t2..." << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t\t1..." << std::endl;
	Sleep(1000);
	system("cls");
}