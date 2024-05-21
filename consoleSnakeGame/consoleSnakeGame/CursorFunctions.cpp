#include "CursorFunctions.h"


void CursorFunctions::goToXY(int x, int y) {
	COORD position{ x,y };
	HANDLE handler{ GetStdHandle(STD_OUTPUT_HANDLE) };
	SetConsoleCursorPosition(handler, position);
}

void CursorFunctions::cursorVisible(bool is_visible) {
	HANDLE handler{ GetStdHandle(STD_OUTPUT_HANDLE) };
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(handler, &cursor_info);
	cursor_info.bVisible = is_visible;
	SetConsoleCursorInfo(handler, &cursor_info);
}