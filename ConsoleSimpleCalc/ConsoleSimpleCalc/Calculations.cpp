#include "Calculations.h"

double Calculations::Calculate(double x, char operation, double y) {
	switch (operation) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*': 
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x * y / 100;
	default:
		return 0.0;
	}
}


