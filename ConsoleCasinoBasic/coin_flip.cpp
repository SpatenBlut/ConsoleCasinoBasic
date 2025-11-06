#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <Windows.h>
#include "money.h"

void HeadsTails(const std::string& choiceHT) {
	// Seed random number generator
    std::srand(static_cast<unsigned>(std::time(0)));
    int random = std::rand() % 2;

    std::string result = (random == 0) ? "Heads" : "Tails";

    std::cout << "Coin shows: " << result << "\n";

    if (choiceHT == result) {
        system("cls");
        std::cout << "You guessed correctly!\n";
        std::cout << "You Won ";
        won();
        Boutput();
        Sleep(2500);
        system("cls");
    }
    else {
        system("cls");
        std::cout << "Wrong guess.\n";
        std::cout << "You Lost ";
        lost();
        Boutput();
        Sleep(2500);
        system("cls");
    }
}