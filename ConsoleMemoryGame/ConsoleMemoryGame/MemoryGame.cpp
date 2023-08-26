#include "MemoryGame.h"

void MemoryGame::RunGame() {
	char input;
	std::cout << "Welcome to my version of the MEMORY GAME\nDo You want to play? If, so, please, enter \"y\". If not, enter \"n\".\n" << std::endl;
	std::cin >> input;
	switch (input) {
		case 'y':
			std::cout << "\n\n" << std::endl;
			InitMenu();
			break;
		case 'n':
			std::cout << "Goodbye!!!" << std::endl;
			exit(0);
		default:
			std::cout << "I didnt catch that, so, goodbye!!!" << std::endl;
			exit(0);
	}
}

void MemoryGame::InitMenu() {
	std::cout << "Please, enter integer range boundaries for generating numbers. Format of the rang: [x0; y0]; Input format: x0 y0\n"<<std::endl;
	std::cout << "However, if you enter same numbers you will only get this number\n"<<std::endl;
	while (!(std::cin >> x0 >> y0)) {
		std::cout << "Bad value!\n" << std::endl;
		std::cin.clear();
		fflush(stdin);
	}

	std::cout << "\n\nPlease, enter amount of rounds you would like to play(only integer)\n" << std::endl;
	while (!(std::cin >> amountRounds)) {
		std::cout << "Bad value!\n" << std::endl;
		std::cin.clear();
		fflush(stdin);
	}

	std::cout << "\n\nPlease, enter game mode to play. Available game modes: single numbers(enter \"number\"), number sequences(enter \"sequence\") and number matrixes(enter\"matrix\")\n"<<std::endl;
	std::string inputGameMode;
	std::cin >> inputGameMode;
	CheckInput(inputGameMode);
}

void MemoryGame::CheckInput(std::string gameMode) {
	std::string input;
	srand(time(NULL));
	succeeded = 0, mistakes = 0;
	if (gameMode == vectorModes[0]) {
		formatMode(vectorModes[0]);
		runNumbMode();
	}
	else if (gameMode == vectorModes[1]) {
		std::cout << "Please enter size of the number sequences(between 1 to 10)\n" << std::endl;
		while (!(std::cin >> nSize) && nSize > 0 && nSize < 11) {
			std::cout << "Bad value!\n" << std::endl;
			std::cin.clear();
			fflush(stdin);
		}
		formatMode(vectorModes[1]);
		runSequenceMode();
	}
	else if (gameMode == vectorModes[2]) {
		std::cout << "Please enter sizes of the matrixes(between 2 to 5)\n" << std::endl;
		while (!(std::cin >> nSize>> mSize) && nSize > 1 && nSize < 6 && mSize > 1 && mSize < 6) {
			std::cout << "Bad value!\n" << std::endl;
			std::cin.clear();
			fflush(stdin);
		}
		formatMode(vectorModes[2]);
		runMatrixMode();
	}
	else {
		std::cout << "I didnt catch that may be because you made a mistake or the developer is a dummy that forgot to add that mode. Try again. Here you are available modes:\n";
		for (int i = 0; i < vectorModes.size(); ++i) std::cout <<"\"" << vectorModes[i] << "\" ";
		std::cin >> input;
		CheckInput(input);
	}
}

void MemoryGame::formatText(std::string mode) {
	std::cout<< "\n\t\t\t\t\tThe "<< mode <<" will disappear in 3... " << std::endl;
	Sleep(1110);
	std::cout << "\t\t\t\t\t2..." << std::endl;
	Sleep(1110);
	std::cout << "\t\t\t\t\t1..." << std::endl;
	Sleep(1110);
	system("cls");
	std::cout << "Enter the "<<mode<<" you just saw" << std::endl;
}

void MemoryGame::formatMode(std::string mode) {
	std::cout << "\n\t\t\t\t\tGame in mode \"" << mode << "\" begins in 3..." << std::endl;
	Sleep(1110);
	std::cout << "\t\t\t\t\t2... " << std::endl;
	Sleep(1110);
	std::cout << "\t\t\t\t\t1... \n" << std::endl;
	Sleep(1110);
}

void MemoryGame::runNumbMode() {
	int numbExample{ 0 }, userInput{ 0 };
	for (int i = 0; i < amountRounds; ++i) {
		numbExample = createNumb();
		std::cout << "\n\n\n" << numbExample;
		formatText(vectorModes[0]);
		//std::cin >> userInput;
		while (!(std::cin >> userInput)) {
			std::cout << "Bad value!\n" << std::endl;
			std::cin.clear();
			fflush(stdin);
		}
		if (userInput == numbExample) {
			std::cout << "\nCorrect!!!" << std::endl;
			succeeded++;
		}
		else mistakes++;
	}
	EndGame();
}

int MemoryGame::createNumb() {
	int returnNumb{ 0 };
	returnNumb = x0 + rand() % (y0 - x0 + 1);
	return returnNumb;
}


void MemoryGame::runSequenceMode() {
	std::vector<int> vectorEx;
	std::vector<int> userVector;
	int userInput{ 0 };
	for (int i = 0; i < amountRounds; ++i) {
		vectorEx = createNumbSequence();
		std::cout << "\n\n\nYour sequence is:\n"<<std::endl;
		for (int i : vectorEx) std::cout << i << ' ';
		formatText(vectorModes[1]);
		for (int i = 0; i < nSize; ++i) {
			std::cin >> userInput;
			userVector.push_back(userInput);
		}
		if (userVector == vectorEx) {
			std::cout << "\nCorrect!!!" << std::endl;
			succeeded++;
		}
		else mistakes++;
	}
	EndGame();
}

std::vector<int> MemoryGame::createNumbSequence() {
	std::vector<int> returnVector;
	for (int i = 0; i < nSize; ++i) 
		returnVector.push_back(createNumb());
	
	return returnVector;
}

void MemoryGame::runMatrixMode() {
	std::vector<std::vector<int>> matrixEx;
	std::vector<std::vector<int>> userMatrix;
	int userInput{ 0 };
	for (int i = 0; i < amountRounds; ++i) {
		matrixEx = createMatrix();
		std::cout << "Your matrix is:\n" << std::endl;
		for (auto i : matrixEx) {
			for (auto j : i)
				std::cout << j << ' ';
			std::cout << '\n';
		}
		formatText(vectorModes[2]);
		for (int i = 0; i < nSize; ++i) {
			std::vector<int> temp;
			for (int j = 0; j < mSize; ++j) {
				std::cin >> userInput;
				temp.push_back(userInput);
			}
			userMatrix.push_back(temp);
		}
		if (userMatrix == matrixEx) {
			std::cout << "\nCorrect!!!" << std::endl;
			succeeded++;
		}
		else mistakes++;
	}
	EndGame();
}

std::vector<std::vector<int>> MemoryGame::createMatrix() {
	std::vector<std::vector<int>> returnVector;
	for (int i = 0; i < nSize; ++i) {
		std::vector<int> tempVector;
		for (int j = 0; j < mSize; ++j) 
			tempVector.push_back(createNumb());
		returnVector.push_back(tempVector);
	}
	return returnVector;
}

void MemoryGame::EndGame() {
	char input;
	std::cout << "That's all!!! Your results: " << succeeded << " correct and " << mistakes << " mistakes" << std::endl;
	std::cout << "Would you like to play again or exit? If you want to play please enter \"p\", if not enter \"e\"" << std::endl;
	std::cin >> input;
	switch (input) {
		case 'p':
			InitMenu();
			break;
		case 'e':
			exit(0);
		default:
			std::cout << "I didnt catch that, try again in 3 seconds";
			Sleep(3000);
			system("cls");
			EndGame();
			break;
	}
}
