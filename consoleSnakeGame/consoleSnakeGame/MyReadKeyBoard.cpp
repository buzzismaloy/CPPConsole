#include "MyReadKeyBoard.h"

void MyReadKeyBoard::readInteger(int* numb_ptr) {
	bool flag{ true };
	while (flag) {
		try {
			std::cin >> *numb_ptr;
			if (std::cin.fail()) throw "\nWrong input type\n";
			flag = false;
		}
		catch(const char* error_msg) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << error_msg<<std::endl;
		}
	}
}
