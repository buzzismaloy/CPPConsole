#include "SnakeGame.h"
#include "MyReadKeyBoard.h"

SnakeGame::SnakeGame() {
	srand(time(NULL));
	h_console_output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(h_console_output, &csbi);
	old_text_attr = csbi.wAttributes;
}

SnakeGame::~SnakeGame(){
	CursorFunctions::cursorVisible(true);
	SetConsoleTextAttribute(h_console_output, old_text_attr);
}

void SnakeGame::setTextAttr(WORD attr) {
	SetConsoleTextAttribute(h_console_output, attr);
}

void SnakeGame::start() {
	setTextAttr(static_cast<WORD>(0x0a));
	std::cout << "\t\t\tWelcome to my iteration of the snake game!!!\n\t\t\tHope you enjoy it, GL HF\n"<<std::endl;
	menu();
}

void SnakeGame::menu() {
	//std::cout << "1)Start game\n2)Settings\n3)Quit\n" << std::endl;
	while (true) {
		std::cout << "1)Start game\n2)Go to settings\n3)Quit\nPlease, enter the number(integer) of the action you want to perform\n" << std::endl;
		int number{0};
		MyReadKeyBoard::readInteger(&number);
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		switch (number) {
		case 1:
			run();
			break;
		case 2:
			settings();
			break;
		case 3:
			quit();
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::run() {
	system("cls");
	CursorFunctions::cursorVisible(false);
	
	time_1 = clock();
	if (game_mode) {
		runSequentGame();
	}
	else {
		runAtOnceGame();
	}
	time_2 = clock();
	game_duration = static_cast<double>(time_2 - time_1) / CLOCKS_PER_SEC;
	endingGameMsg();

	succeded_apples = 0;
}

void SnakeGame::runSequentGame() {
	if (default_chars) {
		Field game_field(DEFAULT_HEAD, DEFAULT_BODY);
		Snake snake(Rotation::up, control_type, DEFAULT_APPLE, selected_border);

		game_field.createBoundaries(selected_border);
		snake.setStartPosition();

		bool apple_was_taken{ false };
		game_field.spawnPrize();
		while (true) {
			if (snake.isGameOver(border_mode)) {
				winning_flag = false;
				break;
			}

			if (apple_was_taken) { 
				game_field.spawnPrize(); 
				apple_was_taken = false;
			}

			snake.move(game_field.field);
			if (snake.getAppleTaken()) { 
				apple_was_taken = true;
				succeded_apples++; 
			}

			game_field.show();
			std::cout << "\t\t\t\t\t\t\t\t\t\t   length of snake: " << succeded_apples + 1;
			winning_flag = checkVictory();
			if (winning_flag) break;

			Sleep(velocity);
		}
	}
	else {
		Field game_field(head, body, apple);
		Snake snake(Rotation::up, control_type, apple, selected_border, head, body);

		game_field.createBoundaries(selected_border);
		snake.setStartPosition();

		bool apple_was_taken{ false };
		game_field.spawnPrize();
		while (true) {
			if (snake.isGameOver(border_mode)) {
				winning_flag = false;
				break;
			}

			if (apple_was_taken) { 
				apple_was_taken = false;
				game_field.spawnPrize(); 
			}

			snake.move(game_field.field);
			if (snake.getAppleTaken()) { 
				apple_was_taken = true;
				succeded_apples++;
			}

			game_field.show();
			std::cout << "\t\t\t\t\t\t\t\t\t\t   length of snake: " << succeded_apples + 1;
			winning_flag = checkVictory();
			if (winning_flag) break;

			Sleep(velocity);
		}
	}
}

void SnakeGame::runAtOnceGame() {
	if (default_chars) {
		Field game_field(DEFAULT_HEAD, DEFAULT_BODY);
		Snake snake(Rotation::up, control_type, DEFAULT_APPLE, selected_border);

		game_field.createBoundaries(selected_border);
		snake.setStartPosition();

		for (int i = 0; i < apples_amount; ++i) game_field.spawnPrize();
		while (true) {
			if (snake.isGameOver(border_mode)) {
				winning_flag = false;
				break;
			}

			snake.move(game_field.field);
			if (snake.getAppleTaken()) succeded_apples++;
			game_field.show();
			std::cout << "\t\t\t\t\t\t\t\t\t\t   length of snake: " << succeded_apples + 1;
			winning_flag = checkVictory();
			if (winning_flag) break;

			Sleep(velocity);
		}
	}
	else {
		Field game_field(head, body, apple);
		Snake snake(Rotation::up, control_type, apple, selected_border,head, body);

		game_field.createBoundaries(selected_border);
		snake.setStartPosition();

		for (int i = 0; i < apples_amount; ++i) game_field.spawnPrize();
		bool winning_flag{ true };
		while (true) {
			if (snake.isGameOver(border_mode)) {
				winning_flag = false;
				break;
			}
			
			snake.move(game_field.field);
			if (snake.getAppleTaken()) succeded_apples++;
			game_field.show();
			std::cout << "\t\t\t\t\t\t\t\t\t\t   length of snake: " << succeded_apples + 1;
			winning_flag = checkVictory();
			if (winning_flag) break;

			Sleep(velocity);
		}
	}
}

/*void SnakeGame::runDynamicSpeed() {

}*/

void SnakeGame::settings() {
	bool flag{ true };
	while (flag) {
		std::cout << "\nIf you want to change snake control type, enter 1\nIf you want to change borders, enter 2\nIf you want to change the velocity of snake, enter 3\n";
		std::cout << "If you want to change game mode, enter 4\nIf you want to change head,body of snake and apple, enter 5\n";
		std::cout << "If you want to change apple amount, enter 6\nIf you want to change mode of border collision, enter 7\n";
		std::cout << "If you want to go back, enter 0\n" << std::endl;
		int number{ 0 };
		MyReadKeyBoard::readInteger(&number);
		switch (number) {
		case 1:
			setControls();
			break;
		case 2:
			setBorders();
			break;
		case 3:
			setVelocity();
			break;
		case 4:
			setGameMode();
			break;
		case 5:
			setChars();
			break;
		case 6:
			setAppleNumb();
			break;
		case 7:
			setBorderMode();
			break;
		case 0:
			flag = false;
			break;
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::setBorderMode() {
	std::cout << "\nIf you want your snake to die when it touches the border, enter \'1\', if you want it to get out from the opposite boundary, enter \'0\'" << std::endl;
	if (border_mode) std::cout << "The first mode is now installed\n" << std::endl;
	else std::cout << "The second mode is now installed\n" << std::endl;

	bool flag{ true };
	while (flag) {
		int numb{ 0 };
		MyReadKeyBoard::readInteger(&numb);
		switch (numb) {
		case 0:
			border_mode = false;
			flag = false;
			break;
		case 1:
			border_mode = true;
			flag = false;
			break;
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::setControls() {
	std::cout << "\nIf you want to control snake by WASD, enter \'1\'; If you want to control snake by arrows, enter \'0\'" << std::endl;
	if (control_type) std::cout << "Now you control by WASD\n" << std::endl;
	else std::cout << "Now you control by arrows\n" << std::endl;
	bool flag{ true };
	while (flag) {
		int numb{ 0 };
		MyReadKeyBoard::readInteger(&numb);
		switch (numb) {
		case 0:
			control_type = false;
			flag = false;
			break;
		case 1:
			control_type = true;
			flag = false;
			break;
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
	
}

void SnakeGame::setBorders() {
	std::cout << "\nIf you want borders to be \'" << (char)DEFAULT_BORDER_2 << "\', enter \'35\', if you want them to be \'" << (char)DEFAULT_BORDER_1 << "\' enter \'219\'" << std::endl;
	std::cout << "Your current border is \'" << selected_border << "\'\n" << std::endl;
	bool flag{ true };
	while (flag) {
		int numb{ 0 };
		MyReadKeyBoard::readInteger(&numb);
		switch (numb) {
		case 35:
			selected_border = DEFAULT_BORDER_1;
			flag = false;
			break;
		case 219:
			selected_border = DEFAULT_BORDER_2;
			flag = false;
			break;
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::setVelocity() {
	std::cout<<"\nNow you have to choose the speed of the snake(remember, the faster your snake is the harder game is)\n" << std::endl;
	std::cout << "Your speed limits are [" << MIN_VELOCITY << ";" << MAX_VELOCITY << "], where 15 is the highest speed and 300 is the slowest; please, enter the speed you want to play with\n";
	std::cout << "current velocity of snake is " << velocity<<'\n'<<std::endl;
	bool flag{ true };
	int numb{ 0 };
	while (flag) {
		MyReadKeyBoard::readInteger(&numb);
		if (numb < MIN_VELOCITY) {
			std::cout << "\nWay too fast!!!\n";
			continue;
		}
		else if (numb > MAX_VELOCITY) {
			std::cout << "\nWay toooooooo sloooow\n";
			continue;
		}

		flag = false;
	}
	velocity = numb;
}

void SnakeGame::setGameMode() {//old variant of setting game mode which is still used!!!
	std::cout << "\nPlease, enter the game mode\n1)enter \'1\';apples appear sequentially; the more you collect the better; you cant change the number of apples in this mode;\n";
	std::cout << " the amount of apples: " << MAX_APPLES_AMOUNT<<std::endl;
	std::cout << "2)enter \'2\';apples appear all at the same time; to win you need to collect all\n";
	if (game_mode) std::cout << "current game mode is 1\n" << std::endl;
	else std::cout << "current game mode is 2\n" << std::endl;
	bool flag{ true };
	int numb{ 0 };
	while (flag) {
		MyReadKeyBoard::readInteger(&numb);
		switch (numb) {
		case 1:
			game_mode = true;
			//apples_amount = MAX_APPLES_AMOUNT;
			flag = false;
			break;
		case 2: 
			game_mode = false;
			flag = false;
			break;
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::setEnumGameMode() {//не используется
	std::cout << "\nPlease, enter the game mode\n1)enter \'1\';apples appear sequentially; the more you collect the better; you cant change the number of apples in this mode;\n";
	std::cout << " the amount of apples: " << MAX_APPLES_AMOUNT << std::endl;
	std::cout << "2)enter \'2\';apples appear all at the same time; to win you need to collect all\n";
	std::cout << "3)enter \'3\';in this mode you will have dynamic speed, that means you start with the slowest speed and will gain +1 speed with each apple eaten;\n";
	std::cout << "the slowest speed you start with: "<< MAX_VELOCITY<<"; the max velocity you will gain: "<< DYNAMIC_SPEED_MAX_VELOCITY;
	std::cout << "; you'll have to gather " << MAX_VELOCITY - DYNAMIC_SPEED_MAX_VELOCITY << " to gain max velocity and after that gather " << DYNAMIC_MODIFIER << " to win\n";
	std::cout << "In total, you need to collect " << DYNAMIC_SPEED_MAX_APPLES<<" apples\n";

	switch (cur_game_mode) {
	case GameModes::mode_1:
		std::cout << "current game mode is 1";
		break;
	case GameModes::mode_2:
		std::cout << "current game mode is 2";
		break;
	case GameModes::mode_3:
		std::cout << "current game mode is 3";
		break;
	}

	bool flag{ true };
	int numb{ 0 };
	while (flag) {
		MyReadKeyBoard::readInteger(&numb);
		
		switch (numb) {
		case 1:
		case 2:
		case 3:
			cur_game_mode = static_cast<GameModes>(numb);
			flag = false;
			break;
		default:
			std::cout << "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::setEnumAppleNumb() {
	switch (cur_game_mode) {
	case GameModes::mode_1: {
		std::cout << "\nPlease enter apple amount, number mustnt be less than " << MIN_TOTAL_APPLES << " and mustnt be greater than " << MAX_TOTAL_APPLES << std::endl;
		std::cout << "Current apple amount is " << apples_amount << '\n' << std::endl;
		bool flag{ true };
		int numb{ 0 };
		while (flag) {
			MyReadKeyBoard::readInteger(&numb);
			if (numb < MIN_TOTAL_APPLES) {
				std::cout << "\nWay too small amount\n";
				continue;
			}
			else if (numb > MAX_TOTAL_APPLES) {
				std::cout << "\nWay too big amount\n";
				continue;
			}

			flag = false;
		}
		apples_amount = numb;
		break;
	}
	case GameModes::mode_2:
		std::cout << "\nSorry but in this game mode you cant change total number of apples; amount of apples: " << MAX_APPLES_AMOUNT << "\n\n";
		break;
	case GameModes::mode_3:
		std::cout << "\nSorry but in this game mode you cant change total number of apples; amount of apples: " << DYNAMIC_SPEED_MAX_APPLES << "\n\n";
		break;
	}
}

void SnakeGame::setAppleNumb() {
	if (!game_mode) {
		std::cout << "\nPlease enter apple amount, number mustnt be less than " << MIN_TOTAL_APPLES << " and mustnt be greater than " << MAX_TOTAL_APPLES << std::endl;
		std::cout << "Current apple amount is " << apples_amount << '\n' << std::endl;
		bool flag{ true };
		int numb{ 0 };
		while (flag) {
			MyReadKeyBoard::readInteger(&numb);
			if (numb < MIN_TOTAL_APPLES) {
				std::cout << "\nWay too small amount\n";
				continue;
			}
			else if (numb > MAX_TOTAL_APPLES) {
				std::cout << "\nWay too big amount\n";
				continue;
			}

			flag = false;
		}
		apples_amount = numb;
	}
	else std::cout << "\nSorry but in this game mode you cant change total number of apples; amount of apples: " << MAX_APPLES_AMOUNT << '\n' << std::endl;
	
}

void SnakeGame::setChars() {
	std::cout << "\nIf you want to play with default snake's head(\'O\'), body(\'*\') and default apple(\'$\') enter 0, if you want to change them enter 1\n";
	if (default_chars) std::cout << "\ndefault symbols are used\n" << std::endl;
	else std::cout << "Here are symbols that are used: head - " << head << ", body - " << body << ", apple - " << apple << '\n' << std::endl;
	bool flag{ true };
	int numb{ 0 };
	while (flag) {
		MyReadKeyBoard::readInteger(&numb);
		switch (numb) {
		case 0:
			default_chars = true;
			flag = false;
			break;
		case 1: {
			default_chars = false; //добавить считывание символов
			std::cout << "\nplease enter symbol for head, body and apple; they cant be like default symbols\n";
			std::cin >> head >> body >> apple;

			
			/*std::cin >> head;
			std::cout << "please enter symbol for body\n";
			std::cin >> body;
			std::cout << "please enter symbol for apple\n";
			std::cin >> apple;*/
			flag = false;
			break;
		}
		default:
			std::cout<< "\nSorry, i didnt catch that\n";
		}
	}
}

void SnakeGame::quit() {
	std::cout << "\n\n\t\t\tGoodbye!\n\n";
	exit(1);
}

void SnakeGame::endingGameMsg() {
	Sleep(1500);
	system("cls");
	if (winning_flag && !game_mode) std::cout << "\t\t\tCongratulations!!! Y o u w o n!\nlength of your snake " << succeded_apples + 1 << '\n' << std::endl;
	else if (!winning_flag && !game_mode) std::cout << "\t\t\tY o u l o s t ! ! !\nlength of your snake " << succeded_apples + 1 << ", apples left: " << apples_amount - succeded_apples << '\n' << std::endl;
	else if (!winning_flag && game_mode && succeded_apples != MAX_APPLES_AMOUNT) std::cout << "\t\t\tY o u l o s t ! ! !\nlength of your snake " << succeded_apples + 1 << '\n';
	else if (!winning_flag && game_mode && succeded_apples == MAX_APPLES_AMOUNT) std::cout << "\t\t\tCongratulations!!! Y o u w o n!\nlength of your snake " << succeded_apples + 1 << '\n';
	std::cout << "Duration of your current session: " << game_duration << " sec\n" << std::endl;
	Sleep(2500);
	system("cls");

	clearKeyBoardBuffer();
}

void SnakeGame::clearKeyBoardBuffer() {
	while (_kbhit()) // clear the keyboard buffer
		_getch();
}

bool SnakeGame::checkVictory() {
	bool flag{ true };
	if (game_mode) flag = succeded_apples == MAX_APPLES_AMOUNT;
	else flag = succeded_apples == apples_amount;
	return flag;
}