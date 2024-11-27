#include <iostream>
#include "Calculations.h"

int main()
{
    double x = 0.0, y = 0.0, result = 0.0;
    int choice = 0;
    char operation = ' ';
    std::cout << "Simple Console Calculator" << std::endl << "\n";
    std::cout << "Please enter the operation to perform. Format: a+b || a-b || a*b  || a/b"<<std::endl;
    Calculations calc;
    while (choice < 1) {
        std::cout << "to perform operations press 0 to exit press 1 or any larger number";
        std::cin >> choice;
        if (choice == 0) {
            std::cin >> x >> operation >> y;
            if (operation == '/' && y == 0) {
                std::cout << "Attempted to divide by zero!\n";
                continue;
            }
            else result = calc.Calculate(x, operation, y);
            std::cout << "Result of " << x << operation << y << " is: " << result << std::endl;
        }
        else break;
    }
    return 0;
}

