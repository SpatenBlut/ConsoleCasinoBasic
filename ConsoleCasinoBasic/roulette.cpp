#include <random>
#include <iostream>
#include <string>
#include <Windows.h>
#include "money.h"


void Roulette() {

    static std::random_device rd;       //Hardware-Seed
    static std::mt19937 gen(rd());      // Mersenne-Twister Generator

    std::uniform_int_distribution<int> numDist(1, 36);
    std::uniform_int_distribution<int> colorDist(0, 1);

    int Nrandom = numDist(gen);
    int Crandom = colorDist(gen);

    std::string Cresult = (Crandom == 0) ? "Red" : "Black";
	Sleep(500);
    std::cout << "Roulette shows: " << Cresult << " " << Nrandom << "\n";
	std::cout << "Press Enter to continue...";
    while (true) {
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // VK_RETURN = Enter
            break;
        }
        Sleep(50);
    }
	system("cls");

}

